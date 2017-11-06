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

#ifndef GRAPHY_EQUATION_H
#define GRAPHY_EQUATION_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <functional>
#include <SFML/Graphics.hpp>
#include <Graphy/Graphable.hpp>
#include <Graphy/Graphables/Styles/LineStyle.hpp>

namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing an equation
	///
	////////////////////////////////////////////////////////////
	struct Equation : public Graphable
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs an equation with the formula given by \a equation
		///
		/// \param equation A function representing the equation
		///
		////////////////////////////////////////////////////////////
		Equation(
			std::function<double(double)> equation = [](double x) { return x;},
			LineStyle style = LineStyle());

		////////////////////////////////////////////////////////////
		/// \brief Default destructor
		///
		/// Removes the equation and frees its resources.
		///
		////////////////////////////////////////////////////////////
		~Equation();

		////////////////////////////////////////////////////////////
		/// \brief Return the value of the equation at a given value of x
		///
		/// \param x x-value at which to evaulate the equation
		///
		////////////////////////////////////////////////////////////
		double y(double x) const;

		////////////////////////////////////////////////////////////
		/// \brief Estimate an x-value at which the equation has the value \a y
		///
		/// \param y y-value at which to find the corresponding x-value
		/// \param its Number of numerical iterations to perform when estimating the x-value
		///
		////////////////////////////////////////////////////////////
		double x(double y, unsigned int its = 5) const;

		////////////////////////////////////////////////////////////
		/// \brief Estimate an x-value at which the equation has the value \a y, given an initial guess \a x0
		///
		/// \param y y-value at which to find the corresponding x-value
		/// \param x0 Initial guess of the x-value
		/// \param its Number of numerical iterations to perform when estimating the x-value
		///
		////////////////////////////////////////////////////////////
		double x(double y, double x0, unsigned its = 5) const;

		////////////////////////////////////////////////////////////
		/// \brief Calculate the derivitive of the equation at a point
		///
		/// \param x x-value at which to evaulate the derivitive of the equation
		///
		////////////////////////////////////////////////////////////
		double dy(double x) const;

		////////////////////////////////////////////////////////////
		/// \brief Calculate the n-th derivitive of the equation at a point
		///
		/// \param x x-value at which to evaulate the n-th derivitive of the equation
		///
		////////////////////////////////////////////////////////////
		double dn_y(unsigned int n, double x) const;

		std::function<double(double)> equation; ///< The equation of the curve
		LineStyle style; ///< Styling information for the curve
		float grain_size; ///< Number of pixels between points where the curve is calculated

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();

		////////////////////////////////////////////////////////////
		/// \brief Recursively calculates the n-th derivative from an array of values in the region
		///
		/// \param n Current order of the derivative
		/// \param ys An array containing n values of the curve in the proximity of where the derivitive is being calculated
		///
		////////////////////////////////////////////////////////////
		double dn_rec(unsigned int n, double* ys) const;

		////////////////////////////////////////////////////////////
		/// \brief Interval used to calculate derivaties
		///
		////////////////////////////////////////////////////////////
		static const double delta;
	};

} // namespace graphy

#endif //GRAPHY_EQUATION_H
