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

#ifndef GRAPHY_INEQUALITYSTYLE_H
#define GRAPHY_INEQUALITYSTYLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <Graphy/Utils/random_color.hpp>


namespace graphy
{

	struct InequalityStyle
	{
		////////////////////////////////////////////////////////////
		/// \brief Enumeration defining which region should be filled
		///
		////////////////////////////////////////////////////////////
		enum Region
		{
			greater_than, ///< Inequality holds for all values y > f(x)
			less_than ///< Inequality holds for all values y < f(x)
		};

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a default style.
		///
		////////////////////////////////////////////////////////////
		InequalityStyle() :
			enabled(false),
			color(xsf::random_color() * sf::Color(255, 255, 255, 126)),
			region(greater_than)
		{}

		bool enabled; ///< Inequalities will only display if this is set to true
		sf::Color color; ///< Colour to fill inequality region with
		Region region; ///< Region to fill
	};

} // namespace graphy

#endif //GRAPHY_INEQUALITYSTYLE_H
