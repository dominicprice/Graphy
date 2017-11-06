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

#ifndef GRAPHY_LABELSTYLE_H
#define GRAPHY_LABELSTYLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <SFML/Graphics/Color.hpp>


namespace graphy
{

	struct LabelStyle
	{
		////////////////////////////////////////////////////////////
		/// \brief Enumeration defining where the label should float relative to its position
		///
		////////////////////////////////////////////////////////////
		enum Float : signed char
		{
			above_right = 0, ///< Above and to the right of a point
			below_right = 1, ///< Below and to the right of a point
			above_left = 2, ///< Above and to the left of a point 
			below_left = 3, ///< Below and to the left of a point 
			_unset = -1 ///< Ambiguous, may be drawn anywhere
		};

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a default style.
		///
		////////////////////////////////////////////////////////////
		LabelStyle() :
			enabled(true),
			text(),
			color(sf::Color::Black),
			size(15),
			pos(Float::below_left),
			x(0),
			offset(0)
		{}

		bool enabled; ///< Labels will only display if this is set to true
		std::string text; ///< Label text
		sf::Color color; ///< Colour of label
		unsigned int size; ///< Height of label in pixels
		Float pos; ///< Placement of label relative to position
		double x; ///< x-coordinate of label for objects with extended length
		float offset; ///< offset of label from its position
	};

} // namespace graphy

#endif //GRAPHY_LABELSTYLE_H