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

#ifndef GRAPHY_COLORMAP_H
#define GRAPHY_COLORMAP_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Graphy/Graphable.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a color map
	///
	////////////////////////////////////////////////////////////
	class ColorMap : public Graphable
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a color map from a function defining the 
		/// color at each point
		///
		/// \param eq An equation returning a color for each (x, y)
		///
		////////////////////////////////////////////////////////////
		ColorMap(std::function<sf::Color(double, double)> eq);

		std::function<sf::Color(double, double)> eq; ///< Equation of the color map
		float grain_size; ///< Distance in pixels between points at which the equation is evaluated

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();
	};

} // namespace graphy

#endif //GRAPHY_COLORMAP_H
