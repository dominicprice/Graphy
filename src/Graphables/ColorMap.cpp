#include <Graphy/Graphables/ColorMap.hpp>

namespace graphy
{
	ColorMap::ColorMap(std::function<sf::Color(double, double)> eq) :
		eq(eq), grain_size(5)
	{

	}

	void ColorMap::draw()
	{
		sf::RectangleShape p(sf::Vector2f(grain_size, grain_size));
		for (float x = 0; x < canvas.width(); x += grain_size) {
			for (float y = 0; y < canvas.height(); y += grain_size) {
				p.setPosition(x, y);
				p.setFillColor(eq(amap_x(x), amap_y(y)));
				canvas.draw(Canvas::Background, p);
			}
		}
	}
}
