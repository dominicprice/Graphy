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

#ifndef GRAPHY_HISTOGRAM_H
#define GRAPHY_HISTOGRAM_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Graphy/Graphable.hpp>
#include <Graphy/Graphables/Bin.hpp>

namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a histogram
	///
	////////////////////////////////////////////////////////////
	struct Histogram : public Graphable
	{
		typedef std::vector<Bin>::iterator iterator; ///< Convenience typedef for an iterator pointing to Bins in the Histogram

		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs an empty histogram
		///
		////////////////////////////////////////////////////////////
		Histogram();

		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a histogram of bins, each of equal width
		///
		/// \param bin List of pairs containing the name and height of each bin (which are constructed with equal width)
		///
		////////////////////////////////////////////////////////////
		Histogram(std::initializer_list<std::pair<std::string, double>> bins);
		
		////////////////////////////////////////////////////////////
		/// \brief Returns a reference to a bin
		///
		/// \param Label of the bin to get
		///
		/// \return A reference to the bin with name \a label
		////////////////////////////////////////////////////////////
		Bin& get_bin(const std::string& label);

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing to the first bin
		///
		////////////////////////////////////////////////////////////
		iterator begin();

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing past the last bin
		///
		////////////////////////////////////////////////////////////
		iterator end();

		bool normalise; ///< When true the total area of the histogram is normalized to 1
		std::vector<Bin> bins; ///< Map containing all bins in the histogram

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();
	};

} // namespace graphy

#endif //GRAPHY_HISTOGRAM_H
