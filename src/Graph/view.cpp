#include <Graphy/Graph.hpp>

namespace graphy
{

	void Graph::zoom_to(double x_min, double x_max, double y_min, double y_max)
	{
		bounds.left = x_min;
		bounds.width = x_max - x_min;
		bounds.top = y_max;
		bounds.height = y_max - y_min;
	}

	void Graph::zoom_by(double x_factor, double y_factor)
	{
		bounds *= sf::Vector2d(x_factor, y_factor);
	}

	void Graph::zoom_by(float factor)
	{
		return zoom_by(factor, factor);
	}

	void Graph::shift_by(double x, double y)
	{
		bounds += sf::Vector2d(x, y);
	}

	void Graph::set_scroll_speed(float v)
	{
		scroll_speed = v;
	}

	void Graph::set_zoom_speed(float v)
	{
		zoom_speed = v;
	}


	void Graph::shift_px(float x, float y)
	{
		shift_by(
			(x / width()) * (bounds.width),
			(y / height()) * (bounds.height)
		);
	}

}
