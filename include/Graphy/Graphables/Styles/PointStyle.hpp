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

#ifndef GRAPHY_DATASETSTYLE_H
#define GRAPHY_DATASETSTYLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <Graphy/Utils/random_color.hpp>
#include <Graphy/Graphables/Styles/LabelStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Struct to hold styling attributes for graphy::Point class
	///
	////////////////////////////////////////////////////////////
	struct PointStyle
	{
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a default style.
		///
		////////////////////////////////////////////////////////////
		PointStyle() :
			color(xsf::random_color()),
			shape(PointStyle::dot(5)),
			outline(0),
			label()
		{}

		sf::Color color; ///< Colour of the data points
		sf::ConvexShape shape; ///< Shape of the data points. Can be any sf::ConvexShape. The origin of the shape will be placed at the data point.
		float outline; ///< If zero, data points will be solid filled. If greater than zero, data points will be shells with given thickness.
		LabelStyle label; ///< Style of labels displayed next to data points

		////////////////////////////////////////////////////////////
		/// \brief Produces a dot of given radius
		///
		/// This constructs an sf::ConvexShape of a dot which can be
		/// stored in the \a shape. 
		///
		/// \param radius Radius of the produced dot
		///
		/// \return A dot of given radius
		///
		////////////////////////////////////////////////////////////
		static sf::ConvexShape dot(float radius)
		{
			static const float pi = 3.1415926f;
			unsigned int point_count = 30;
			sf::ConvexShape s(point_count);
			for (unsigned int i = 0; i < point_count; ++i)
				s.setPoint(i, sf::Vector2f(
					radius * std::cos(i * 2 * pi / point_count),
					radius * std::sin(i * 2 * pi / point_count)
				));

			return s;
		}

		////////////////////////////////////////////////////////////
		/// \brief Produces a square of given side length
		///
		/// This constructs an sf::ConvexShape of a square which can be
		/// stored in the \a shape. 
		///
		/// \param size Side length of the produced square
		///
		/// \return A square of given side length
		///
		////////////////////////////////////////////////////////////
		static sf::ConvexShape square(float size)
		{
			sf::ConvexShape s(4);
			s.setPoint(0, { 0,0 });
			s.setPoint(1, { size, 0 });
			s.setPoint(2, { size, size });
			s.setPoint(3, { 0, size });
			s.setOrigin(
				s.getLocalBounds().width / 2,
				s.getLocalBounds().height / 2);
			return s;
		}

		////////////////////////////////////////////////////////////
		/// \brief Produces a cross of given dimensions
		///
		/// This constructs an sf::ConvexShape of a cross which can be
		/// stored in the \a shape. 
		///
		/// \param length Total height and width of the cross
		/// \param thickness Thickness of spokes
		///
		/// \return A cross of given dimenions
		///
		////////////////////////////////////////////////////////////
		static sf::ConvexShape cross(float length, float thickness)
		{
			sf::ConvexShape s(12);
			float width = (length - thickness) / 2;

			s.setPoint(0, { 0, width });
			s.setPoint(1, { width, width });
			s.setPoint(2, { width, 0 });
			s.setPoint(3, { width + thickness, 0 });
			s.setPoint(4, { width + thickness, width });
			s.setPoint(5, { length, width });
			s.setPoint(6, { length, width + thickness });
			s.setPoint(7, { width + thickness, width + thickness });
			s.setPoint(8, { width + thickness, length });
			s.setPoint(9, { width, length });
			s.setPoint(10, { width, width + thickness });
			s.setPoint(11, { 0, width + thickness });
			s.setOrigin(
				s.getLocalBounds().width / 2,
				s.getLocalBounds().height / 2);
			return s;
		}
	};

} // namespace graphy

#endif //GRAPHY_DATASETSTYLE_H
