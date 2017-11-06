#include <SFML/Graphics.hpp>

namespace sfd
{
	sf::RectangleShape rectangle(
		const sf::FloatRect& dim,
		const sf::Color& fill_color,
		float thickness,
		const sf::Color& outline_color)
	{
		sf::RectangleShape r(sf::Vector2f(dim.width, dim.height));
		r.setPosition(dim.left, dim.top);
		r.setFillColor(fill_color);
		r.setOutlineColor(outline_color);
		r.setOutlineThickness(thickness);
		return r;
	}

	sf::RectangleShape line(
		const sf::Vector2f& from,
		const sf::Vector2f& to,
		float width,
		const sf::Color& fill_color,
		float thickness,
		const sf::Color& outline_color
	)
	{
		sf::RectangleShape r;
		sf::Vector2f cur_vec = to - from;
		r.setRotation(57.296f * std::atan2(cur_vec.y, cur_vec.x));
		r.setSize(sf::Vector2f(std::hypot(cur_vec.x, cur_vec.y), width));
		r.setPosition(from);
		r.setFillColor(fill_color);
		r.setOutlineThickness(thickness);
		r.setOutlineColor(outline_color);
		return r;
	}

	sf::CircleShape circle(
		const sf::Vector2f& pos,
		float radius,
		const sf::Color& fill_color,
		float thickness,
		const sf::Color& outline_color
	)
	{
		sf::CircleShape r;
		r.setRadius(radius);
		r.setPosition(pos);
		r.setFillColor(fill_color);
		r.setOutlineColor(outline_color);
		r.setOutlineThickness(thickness);
		return r;
	}

	sf::Text text(
		const std::string& str,
		sf::Font& font,
		unsigned int size,
		const sf::Vector2f& pos,
		bool center_origin,
		const sf::Color& fill_color,
		float outline,
		const sf::Color& outline_color,
		const sf::Uint32 style
	)
	{
		sf::Text t(str, font, size);
		t.setStyle(style);
		t.setFillColor(fill_color);
		t.setOutlineThickness(outline);
		t.setOutlineColor(outline_color);
		if (center_origin)
			t.setOrigin(t.getGlobalBounds().width / 2, 0);
		t.setPosition(pos);
		return t;
	}
}