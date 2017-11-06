/////////////////////////////////////////////////////////////////////////////////
//MIT License
//
//Copyright(c) 2017 Dominic Price
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
/////////////////////////////////////////////////////////////////////////////////

#ifndef GRAPHY_SFDRAW_H
#define GRAPHY_SFDRAW_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


namespace sfd
{
	////////////////////////////////////////////////////////////
	/// \brief Creates a drawable rectangle
	///
	/// \param dim Positions of the rectangles vertices
	/// \param fill_color Interior colour of the rectangle
	/// \param thickness Thickness in pixels of the rectangle's border
	/// \param outline_color Colour of the rectangle's border
	///
	/// \return sf::RectangleShape representing the rectangle
	///
	////////////////////////////////////////////////////////////
	sf::RectangleShape rectangle(
		const sf::FloatRect& dim,
		const sf::Color& fill_color = sf::Color::Black,
		float thickness = 0,
		const sf::Color& outline_color = sf::Color::Black);

	////////////////////////////////////////////////////////////
	/// \brief Returns a drawable line segment
	///
	/// \param from Starting position of the line segment
	/// \param to End position of the line segment
	/// \param Width in pixels of the line segment
	/// \param fill_color Interior colour of the line segment
	/// \param thickness Thickness in pixels of the line segment's border
	/// \param outline_color Colour of the line segment's border
	///
	/// \return sf::RectangleShape representing a line segment
	///
	////////////////////////////////////////////////////////////
	sf::RectangleShape line(
		const sf::Vector2f& from,
		const sf::Vector2f& to,
		float width = 1,
		const sf::Color& fill_color = sf::Color::Black,
		float thickness = 0,
		const sf::Color& outline_color = sf::Color::Black
	);

	////////////////////////////////////////////////////////////
	/// \brief Returns a drawable circle
	///
	/// \param pos Position of the center of the circle
	/// \param radius Radius of the circle
	/// \param fill_color Interior colour of the circle
	/// \param thickness Thickness in pixels of the circle's border
	/// \param outline_color Colour of the circle's border
	///
	////////////////////////////////////////////////////////////
	sf::CircleShape circle(
		const sf::Vector2f& pos,
		float radius,
		const sf::Color& fill_color = sf::Color::Black,
		float thickness = 0,
		const sf::Color& outline_color = sf::Color::Black
	);

	////////////////////////////////////////////////////////////
	/// \brief Returns drawable text
	///
	/// \param str String displayed by the text
	/// \param font Font to use to display the text
	/// \param size Height in pixels of the text
	/// \param pos Position to place the text at
	/// \param center_origin If true, the horizontal position will refer to the center point of the text
	/// \param fill_color Interior colour of the text
	/// \param thickness Thickness in pixels of the text's border
	/// \param outline_color Colour of the text's border
	///
	////////////////////////////////////////////////////////////
	sf::Text text(
		const std::string& str,
		sf::Font& font,
		unsigned int size,
		const sf::Vector2f& pos,
		bool center_origin = false,
		const sf::Color& fill_color = sf::Color::Black,
		float outline = 0,
		const sf::Color& outline_color = sf::Color::Black,
		const sf::Uint32 style = sf::Text::Regular
	);

} // namespace sfd

#endif //GRAPHY_SFDRAW_H