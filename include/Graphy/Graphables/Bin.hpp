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

#ifndef GRAPHY_BIN_H
#define GRAPHY_BIN_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Graphy/Graphables/Styles/BinStyle.hpp>

namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Helper class representing a bin in the graphy::Histogram graphable
	///
	////////////////////////////////////////////////////////////
	struct Bin
	{
		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a bin of given dimension
		///
		/// \param x x-value to place bin at
		/// \param width Width of bin
		/// \param height Height of bin
		///
		////////////////////////////////////////////////////////////
		Bin(double x = 0, double width = 1, double height = 1);

		double x; ///< x-value to place bin at
		double width; ///< Width of bin
		double height; ///< Height of bin
		BinStyle style; ///< Styling information for bin

	};

} // namespace graphy

#endif //GRAPHY_BIN_H
