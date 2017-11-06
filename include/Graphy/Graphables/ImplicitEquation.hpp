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

#ifndef GRAPHY_IMPLICITEQUATION_H
#define GRAPHY_IMPLICITEQUATION_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Graphy/Graphable.hpp>
#include <functional>
#include <Graphy/Graphables/Styles/LineStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing an implicitly defined equation
	///
	////////////////////////////////////////////////////////////
	struct ImplicitEquation : public Graphable
	{
		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs an equation with the formula given by \a equation
		///
		/// \param equation A function representing the equation that equals 0 along the curve
		///
		////////////////////////////////////////////////////////////
		ImplicitEquation(
			std::function<double(double, double)> equation = [](double x, double y) { return x*x + y*y - 1; },
			LineStyle style = LineStyle());

		std::function<double(double, double)> equation; ///< The equation of the curve
		LineStyle style;  ///< Styling information for the curve
		float grain_size;

		////////////////////////////////////////////////////////////
		/// \brief Reposition the label to be as close to the position defined in style as possible
		///
		////////////////////////////////////////////////////////////
		void reposition_label();

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();

	private:
		sf::Vector2d label_pos_; 
		bool label_pos_set;
	};

} // namespace graphy

#endif //GRAPHY_IMPLICITEQUATION_H
