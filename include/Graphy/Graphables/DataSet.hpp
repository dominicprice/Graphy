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

#ifndef GRAPHY_DATASET_H
#define GRAPHY_DATASET_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Graphy/Graphables/Point.hpp>
#include <Graphy/Graphable.hpp>
#include <vector>
#include <Graphy/Graphables/Styles/LineStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a data set
	///
	////////////////////////////////////////////////////////////
	class DataSet : public Graphable
	{
	public:
		typedef std::vector<Point>::iterator iterator; ///< Convenience typedef for pseudo-iterators pointing to data points
		typedef std::vector<Point>::const_iterator const_iterator; ///< Convenience typedef for const psuedo-iterators pointing to data points

		////////////////////////////////////////////////////////////
		/// \brief Default Constructor
		///
		/// Constructs an empty data set
		///
		////////////////////////////////////////////////////////////
		DataSet();

		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a data set containing the points in \a point_set
		///
		/// \param point_set Vector containing points in the data set
		///
		////////////////////////////////////////////////////////////
		DataSet(std::vector<Point> point_set);

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing to the first data point
		///
		////////////////////////////////////////////////////////////
		iterator begin();

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing to the first data point
		///
		////////////////////////////////////////////////////////////
		const_iterator begin() const;

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing past the last data point
		///
		////////////////////////////////////////////////////////////
		iterator end();

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator pointing past the last data point
		///
		////////////////////////////////////////////////////////////
		const_iterator end() const;

		bool join;  ///< When set to true data points will be connected by a line
		LineStyle style; ///< Styling information for regression line
		std::vector<Point> points; ///< Vector containing all the points in the data set

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();
	};

} // namespace graphy

#endif //GRAPHY_DATASET_H
