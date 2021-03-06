#include <Graphy/Graphables/Axis.hpp>
#include <sstream>
#include <iomanip>
#include <SFDraw.h>

namespace graphy
{

	Axis::Axis(AxisStyle style) :
		tick_mode(TickMode::spacing), style(style), tick_spacing(60)
	{

	}

	void Axis::recalculate(double low_bound, double high_bound, float win_size)
	{
		if (tick_mode == TickMode::list) {
			//No need to calcualate the ticks vector
			return;
		}

		if (tick_mode == TickMode::spacing) {
			//Calculate what interval corresponds to
			//this spacing 
			tick_interval = tick_spacing * (high_bound - low_bound) / win_size;
		}

		tick_list.clear();
		double initial = std::ceil(low_bound / tick_interval) * tick_interval;
		for (double r = initial; r < high_bound; r += tick_interval)
			tick_list.push_back(r);

		//Stop rounding errors near 0
		for (double& r : tick_list)
			if (std::abs(r) < tick_interval / 2)
				r = 0;
	}

	XAxis::XAxis(AxisStyle style) :
		Axis(style)
	{

	}

	YAxis::YAxis(AxisStyle style) :
		Axis(style)
	{

	}

	void YAxis::recalculate()
	{
		Axis::recalculate(bounds().top - bounds().height, bounds().top, canvas.height());
	}

	void XAxis::recalculate()
	{
		Axis::recalculate(bounds().left, bounds().left + bounds().width, canvas.width());
	}

	void Axis::set_ticks_spacing(float spacing)
	{
		tick_mode = TickMode::spacing;
		tick_spacing = spacing;
	}

	void Axis::set_ticks_interval(double interval)
	{
		tick_mode = TickMode::interval;
		tick_interval = interval;
	}

	void Axis::set_ticks(std::vector<double> ticks)
	{
		tick_mode = TickMode::list;
		tick_list = ticks;
	}

	void YAxis::draw()
	{
		recalculate();
		sf::Vector2f origin = map(0, 0);
		double xpos;

		//Calculate x value of axis
		if (origin.x < 0)
			xpos = bounds().left;
		else if (origin.x > canvas.width() - style.thickness)
			xpos = bounds().left + bounds().width - armap_x(style.thickness);
		else
			xpos = -armap_x(style.thickness) / 2;

		//Draw axis
		canvas.draw(Canvas::Axes, sfd::rectangle(
			sf::FloatRect{ map_x(xpos), map_y(bounds().top), style.thickness, canvas.height() }, 
			style.axis_color));

		//Draw ticks and labels
		for (double y : tick_list) {
			//Labels
			std::stringstream s;
			if (std::abs(y) > 10000 || (std::abs(y) < 0.0001 && y != 0))
				s << std::scientific;
			else
				s << std::fixed;
			s << std::setprecision(style.precision) << y << style.label.text;
			sf::Text t(s.str().c_str(), canvas.font(), style.label.size);
			t.setPosition(map(xpos, y) + sf::Vector2f(0, -style.label.offset));
			if (origin.x <= canvas.width() / 2) //Print on right
				t.move(sf::Vector2f(style.tick_length * 2 + style.thickness, -t.getLocalBounds().height));
			else {//Print on left
				t.move(sf::Vector2f(-t.getLocalBounds().width - style.tick_length * 2 - style.thickness, -t.getLocalBounds().height));
			}
			t.setFillColor(style.label.color);
			canvas.draw(Canvas::Labels, t);

			//Ticks
			if (y != 0) {
				if (style.grid) {
					canvas.draw(Canvas::Axes, sfd::rectangle(sf::FloatRect{
						map_x(bounds().left), map_y(y) - style.tick_thickness / 2,
						canvas.width(), style.tick_thickness }, style.tick_color));
				}
				else {
					canvas.draw(Canvas::Axes, sfd::rectangle(sf::FloatRect{
						map_x(xpos) - style.tick_length, map_y(y) - style.tick_thickness / 2,
						style.tick_length * 2 + style.thickness, style.tick_thickness }, style.tick_color));
				}
			}
		}
	}

	void XAxis::draw()
	{
		recalculate();
		sf::Vector2f origin = map(0, 0);
		double ypos;

		//Calculate y value of x-axis
		if (origin.y < 0)
			ypos = bounds().top;
		else if (origin.y > canvas.height() + style.thickness)
			ypos = bounds().top - bounds().height + armap_y(style.thickness);
		else
			ypos = armap_y(style.thickness) / 2;

		//Draw axis
		canvas.draw(Canvas::Axes, sfd::rectangle(
			sf::FloatRect{ map_x(bounds().left), map_y(ypos), canvas.width(), style.thickness }, style.axis_color));

		//Draw ticks and labels
		for (double x : tick_list) {
			//Labels
			std::stringstream s;
			if (std::abs(x) > 10000 || std::abs(x) < 0.0001 && x != 0)
				s << std::scientific;
			else
				s << std::fixed;
			s << std::setprecision(style.precision) << x << style.label.text;
			sf::Text t(s.str().c_str(), canvas.font(), style.label.size);
			t.setPosition(map(x, ypos) + sf::Vector2f(style.label.offset, 0));
			if (origin.y <= canvas.height() / 2) //Print below
				t.move(sf::Vector2f(-t.getLocalBounds().width / 2, style.thickness + style.tick_length));
			else //Print above
				t.move(sf::Vector2f(-t.getLocalBounds().width / 2, -1 * style.thickness - style.tick_length * 2 - style.label.size));
			t.setFillColor(style.label.color);
			canvas.draw(Canvas::Labels, t);

			//Ticks
			if (x != 0) {
				if (style.grid) {
					canvas.draw(Canvas::Axes, sfd::rectangle(sf::FloatRect{
						map_x(x) - style.tick_thickness / 2, map_y(bounds().top),
						style.tick_thickness, canvas.height() }, 
						style.tick_color));
				}
				else {
					canvas.draw(Canvas::Axes, sfd::rectangle(sf::FloatRect{
						map_x(x) - style.tick_thickness / 2, map_y(ypos) - style.tick_length,
						style.tick_thickness, style.tick_length * 2 + style.thickness },
						style.tick_color));
				}
			}
		}
	}

	Axes::Axes(AxisStyle style) :
		x(style), y(style)
	{
		iterable_axes.push_back(x);
		iterable_axes.push_back(y);
	}

	Axes::Axes(AxisStyle x_style, AxisStyle y_style) :
		x(x_style), y(y_style)
	{
		iterable_axes.push_back(x);
		iterable_axes.push_back(y);
	}

	Axes::iterator Axes::begin() 
	{
		return iterable_axes.begin(); 
	}

	Axes::iterator Axes::end()
	{
		return iterable_axes.end();
	}
}
