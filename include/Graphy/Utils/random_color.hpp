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

#ifndef GRAPHY_RANDOM_COLOR
#define GRAPHY_RANDOM_COLOR

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Color.hpp>


namespace xsf
{
	////////////////////////////////////////////////////////////
	/// \brief Make a random colour
	///
	/// Produces a random colour with all primary components in
	/// the ranges specified
	///
	/// \param r_min The minimum red component
	/// \param r_max The maximum red component
	/// \param g_min The minimum green component
	/// \param g_max The maximum green component
	/// \param b_min The minimum blue component
	/// \param b_max The maximum blue component
	/// \param a_min The minimum alpha component
	/// \param a_max The maximum alpha component
	///
	/// \return A random colour
	///
	////////////////////////////////////////////////////////////
	sf::Color random_color(
		unsigned int r_min = 0, unsigned int r_max = 200,
		unsigned int g_min = 0, unsigned int g_max = 200,
		unsigned int b_min = 0, unsigned int b_max = 200,
		unsigned int a_min = 255, unsigned int a_max = 255);

} // namespace xsf

#endif //GRPAHY_RANDOM_COLOR