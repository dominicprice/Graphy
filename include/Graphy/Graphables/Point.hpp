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

#ifndef GRAPHY_POINT_H
#define GRAPHY_POINT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <Graphy/Utils/Vector2d.hpp>
#include <Graphy/Graphables/Styles/PointStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Object representing a data-point
	///
	////////////////////////////////////////////////////////////
	class Point : public sf::Vector2d
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a data point at the origin (0, 0) with a
		/// default style
		///
		////////////////////////////////////////////////////////////
		Point() {}

		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a data point at the coordinates \a x and \a y
		/// with a default style
		///
		/// \param x The x coordinate of the point
		/// \param y The y coordinate of the point 
		///
		////////////////////////////////////////////////////////////
		Point(double x, double y) : sf::Vector2d(x, y) {}

		////////////////////////////////////////////////////////////
		/// \brief Returns the parsed data point's label
		///
		/// Parses the label text in the data point's style struct
		/// and returns a string containing the parsed text
		///
		////////////////////////////////////////////////////////////
		std::string resolve_label() const;

		PointStyle style; ///< Contains styling information for the data point
	};

} // namespace graphy

#endif //GRAPHY_POINT_H
