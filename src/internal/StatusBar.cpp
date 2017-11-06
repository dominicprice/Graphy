#include <Graphy/Utils/StatusBar.hpp>

namespace xsf
{

	StatusBar::StatusBar(sf::RenderWindow& win, float height, sf::Font& font, sf::Color bg_color, sf::Color text_color) :
		win(win), height(height), font(font), bg_color(bg_color), text_color(text_color)
	{

	}

	void StatusBar::draw()
	{
		sf::RectangleShape r(sf::Vector2f(static_cast<float>(win.getSize().x), height));
		r.setPosition(0, static_cast<float>(win.getSize().y) - 2 * height);
		r.setFillColor(bg_color);
		r.setOutlineColor(sf::Color::Black);
		r.setOutlineThickness(2);
		win.draw(r);

		sf::Text t(text, font, static_cast<unsigned int>(height * 0.65));
		t.setOutlineColor(text_color);
		t.setPosition(10, win.getSize().y - 2 * height);
		win.draw(t);
	}

}
