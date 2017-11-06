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

#ifndef GRAPHY_STATUSBAR_H
#define GRAPHY_STATUSBAR_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

namespace xsf
{
	////////////////////////////////////////////////////////////
	/// \brief Class to wrap a status bar at bottom of an SFML
	/// render window
	////////////////////////////////////////////////////////////
	struct StatusBar
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief Construct a new status bar
		///
		/// \param win The render window to attach the status bar to
		/// \param height Height of the status bar
		/// \param font Font to be used to display text in the status bar
		/// \param bg_color Background colour of the status bar
		/// \param text_color Text colour of the status bar
		///
		////////////////////////////////////////////////////////////
		StatusBar(sf::RenderWindow& win, float height, sf::Font& font,
			sf::Color bg_color = sf::Color(100, 100, 100), sf::Color text_color = sf::Color::White);
		
		////////////////////////////////////////////////////////////
		/// \brief Draws the status bar to the render window
		///
		////////////////////////////////////////////////////////////
		void draw();

		////////////////////////////////////////////////////////////
		/// \brief Text to be displayed on the status bar
		///
		////////////////////////////////////////////////////////////
		std::string text;

		////////////////////////////////////////////////////////////
		/// \brief Height of the status bar
		///
		////////////////////////////////////////////////////////////
		float height;

		////////////////////////////////////////////////////////////
		/// \brief Background colour of the status bar
		///
		////////////////////////////////////////////////////////////
		sf::Color bg_color;

		////////////////////////////////////////////////////////////
		/// \brief Text colour of the status bar
		///
		////////////////////////////////////////////////////////////
		sf::Color text_color;

		////////////////////////////////////////////////////////////
		/// \brief Reference to the font to be used on the status bar
		///
		////////////////////////////////////////////////////////////
		sf::Font& font;

		////////////////////////////////////////////////////////////
		/// \brief Reference to the render window displaying the status bar
		///
		////////////////////////////////////////////////////////////
		sf::RenderWindow& win;
	};

} // namespace xsf

#endif //GRAPHY_STATUSBAR_H


////////////////////////////////////////////////////////////
/// \class xsf::StatusBar
///
/// sfx::StatusBar provides a simple status bar at the bottom
/// of a render window which allows a line of text to be 
/// displayed.
///
/// Usage example:
/// \code
/// sf::Window window(sf::VideoMode(800, 600), "StatusBar Example"); //Create SFML window
/// StatusBar sbar(window, 60, font); //Create a status bar 60 pixels high
/// sbar.text = "Hello world, from the status bar!";
///
/// while (window.isOpen()) {
///    // Event processing
///    sf::Event event;
///    while (window.pollEvent(event)) {
///        if (event.type == sf::Event::Closed)
///            window.close();
///    }
///
///    window.clear();
///    sbar.draw();
///    window.display();
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
