#include <Graphy/Graph.hpp>

namespace graphy
{

	sf::Vector2f Graph::map(double x, double y)
	{
		return{ map_x(x), map_y(y) };
	}

	sf::Vector2f Graph::map(sf::Vector2d p)
	{
		return map(p.x, p.y);
	}

	float Graph::map_x(double x) {
		return rmap_x(x - bounds.left);
	}

	float Graph::map_y(double y) {
		return height() - rmap_y(y - bounds.top + bounds.height);
	}

	sf::Vector2<double> Graph::amap(float x, float y)
	{
		return{ amap_x(x), amap_y(y) };
	}

	sf::Vector2d Graph::amap(sf::Vector2f p)
	{
		return amap(p.x, p.y);
	}

	double Graph::amap_x(float x)
	{
		return armap_x(x) + bounds.left;
	}

	double Graph::amap_y(float y)
	{
		return bounds.top - bounds.height + armap_y(height() - y);
	}


	sf::Vector2f Graph::rmap(double x, double y)
	{
		return sf::Vector2f(rmap_x(x), rmap_y(y));
	}

	sf::Vector2f Graph::rmap(sf::Vector2d p)
	{
		return rmap(p.x, p.y);
	}

	float Graph::rmap_x(double x)
	{
		return static_cast<float>(x * width() / (bounds.width));
	}

	float Graph::rmap_y(double y)
	{
		return static_cast<float>(y * height() / (bounds.height));
	}


	sf::Vector2d Graph::armap(float x, float y)
	{
		return sf::Vector2d(armap_x(x), armap_y(y));
	}

	sf::Vector2d Graph::armap(sf::Vector2f p)
	{
		return armap(p.x, p.y);
	}

	double Graph::armap_x(float x)
	{
		return x * (bounds.width) / width();
	}

	double Graph::armap_y(float y)
	{
		return y * (bounds.height) / height();
	}

}
