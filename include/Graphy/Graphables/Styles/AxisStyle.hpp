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

#ifndef GRAPHY_AXISSTYLE_H
#define GRAPHY_AXISSTYLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <Graphy/Graphables/Styles/LabelStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Struct to hold styling attributes for graphy::Axis class
	///
	////////////////////////////////////////////////////////////
	struct AxisStyle
	{
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a default style.
		///
		////////////////////////////////////////////////////////////
		AxisStyle() :
			thickness(3),
			axis_color(sf::Color::Red),
			tick_color(sf::Color::Red),
			tick_length(5),
			tick_thickness(1),
			precision(3),
			grid(false),
			label()
		{}

		float thickness; ///< Number of pixels wide to draw the axis
		sf::Color axis_color; ///< Colour of the axis
		sf::Color tick_color; ///< Colour of the ticks along the axis
		float tick_length; ///< Length in pixels of the ticks along the axis
		float tick_thickness; ///< Thickness in pixels of the ticks along the axis
		unsigned int precision; ///< Number of decimal places to show on labels
		bool grid; ///< If true, at each tickpoint a line will span the window
		LabelStyle label; ///< Style of label displayed at each tick

		////////////////////////////////////////////////////////////
		/// \brief Returns a thin turquoise grid AxisStyle
		///
		////////////////////////////////////////////////////////////
		static AxisStyle GraphPaper()
		{
			AxisStyle s;
			s.thickness = 2;
			s.axis_color = sf::Color(64, 224, 208);
			s.tick_color = sf::Color(64, 224, 208);
			s.grid = true;
			return s;
		}

		////////////////////////////////////////////////////////////
		/// \brief Returns a thin grey grid AxisStyle
		///
		////////////////////////////////////////////////////////////
		static AxisStyle LinedPaper()
		{
			AxisStyle s;
			s.thickness = 4;
			s.axis_color = sf::Color::Black;
			s.tick_color = sf::Color(150, 150, 150);
			s.grid = true;
			return s;
		}
	};

} // namespace graphy

#endif //GRAPHY_AXISSTYLE_H
