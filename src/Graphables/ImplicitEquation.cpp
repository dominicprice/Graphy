#include <Graphy/Graphables/ImplicitEquation.hpp>

namespace graphy
{

	ImplicitEquation::ImplicitEquation(std::function<double(double, double)> equation, LineStyle style) :
		equation(equation), style(style), label_pos_set(false), grain_size(3)
	{

	}

	void ImplicitEquation::draw()
	{
		//Draw label
		if (style.label.enabled && label_pos_set) {
			sf::Text t(style.label.text, canvas.font(), style.label.size);
			t.setFillColor(style.label.color);
			//Position
			switch (style.label.pos) {
			case LabelStyle::below_left:
				t.setPosition(map(label_pos_) + sf::Vector2f(-t.getLocalBounds().width, 0));
				break;
			case LabelStyle::above_left:
				t.setPosition(map(label_pos_) + sf::Vector2f(-t.getLocalBounds().width, -t.getLocalBounds().height * 2));
				break;
			case LabelStyle::above_right:
				t.setPosition(map(label_pos_) + sf::Vector2f(0, -t.getLocalBounds().height * 2));
				break;
			case LabelStyle::below_right:
				t.setPosition(map(label_pos_) + sf::Vector2f(0, 0));
				break;
			default:
				break;
			}

			canvas.draw(Canvas::Labels, t);
		}


		sf::RectangleShape p(sf::Vector2f(grain_size, grain_size));
		sf::Color color = style.color;

		if (!label_pos_set && style.label.enabled) {
			reposition_label();
		}

		//Loop through every point on the canvas separated by grain_size
		for (float x = 0; x < canvas.width(); x += grain_size) {
			for (float y = 0; y < canvas.height(); y += grain_size) {
				double result = equation(amap_x(x), amap_y(y));
				double excess = std::abs(result / armap_x(style.thickness));
				//Draw curve
				if (excess < 1) {
					color.a = static_cast<sf::Uint8>(style.color.a * (1 - excess));
					p.setPosition(x, y);
					p.setFillColor(color);
					canvas.draw(Canvas::Objects, p);
				}
				//Draw inequality
				if (style.inequality.region == InequalityStyle::greater_than && result > 0 ||
					style.inequality.region == InequalityStyle::less_than && result < 0) {
					p.setPosition(x, y);
					p.setFillColor(style.inequality.color);
					canvas.draw(Canvas::Background, p);
				}
			}
		}
	}

	void ImplicitEquation::reposition_label()
	{
		static const float label_pos_tolerance = 50;

		label_pos_.x = std::numeric_limits<double>().max();
		for (float x = map_x(style.label.x) - label_pos_tolerance, xf = map_x(style.label.x) + label_pos_tolerance; x < xf; x += grain_size) {
			for (float y = 0; y < canvas.height(); y += grain_size) {
				double excess = std::abs(equation(amap_x(x), amap_y(y)) / armap_x(style.thickness));
				if (excess < 1 && std::abs(amap_x(x) - style.label.x) < std::abs(label_pos_.x - style.label.x))
					label_pos_ = sf::Vector2d(amap_x(x), amap_y(y));
			}
		}
		if (label_pos_.x == std::numeric_limits<double>().max()) {
			label_pos_set = false;
		}
		else {
			label_pos_set = true;
		}
	}

}
