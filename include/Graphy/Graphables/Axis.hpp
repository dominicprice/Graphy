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

#ifndef GRAPHY_AXIS_H
#define GRAPHY_AXIS_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <Graphy/Graphable.hpp>
#include <Graphy/Graphables/Styles/AxisStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a coordinate axis
	///
	////////////////////////////////////////////////////////////
	struct Axis : public Graphable
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructor
		///
		/// Constructs a default axis.
		///
		////////////////////////////////////////////////////////////
		Axis(AxisStyle style = AxisStyle());

		////////////////////////////////////////////////////////////
		/// \brief Sets the spacing between ticks in pixels
		///
		/// \param spacing The spacing in pixels between ticks
		///
		////////////////////////////////////////////////////////////
		void set_ticks_spacing(float spacing);

		////////////////////////////////////////////////////////////
		/// \brief Interval in graph coordinates between ticks
		///
		/// \param interval The interval in graph coordinates between ticks
		///
		////////////////////////////////////////////////////////////
		void set_ticks_interval(double interval);

		////////////////////////////////////////////////////////////
		/// \brief Set the ticks to be displayed
		///
		/// \param ticks A vector holding all the ticks to be displayed along the axis
		///
		////////////////////////////////////////////////////////////
		void set_ticks(std::vector<double> ticks = {});

		////////////////////////////////////////////////////////////
		/// \brief Contains the styling information about the axis
		///
		////////////////////////////////////////////////////////////
		AxisStyle style;

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Pure virtual function which can be overriden to define how the axis should be drawn
		///
		////////////////////////////////////////////////////////////
		virtual void draw() = 0;

		////////////////////////////////////////////////////////////
		/// \brief Virtual function which defines how ticks should be calculated along the axis
		///
		/// Any class derived from graphy::Axis should can define its own recalculate function
		/// which calls this function with appropriate parameters.
		///
		/// \param low_bound Lowest possible value that can be shown on the axis
		/// \param high_bound Highest possible value that can be shown on the axis
		/// \param win_size The size in pixels of the axis
		///
		////////////////////////////////////////////////////////////
		virtual void recalculate(double low_bound, double high_bound, float win_size);

		std::vector<double> tick_list; ///< Vector containing all ticks to be drawn along the axis
		double tick_interval; ///< Interval in graph coordinates betweeen ticks on the axis
		float tick_spacing; ///< Spacing in pixels between ticks on the axis
		enum class TickMode : char { interval, spacing, list } tick_mode; ///< Stores which mode of calculating ticks is being used

	};

	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a coordinate x-axis
	///
	////////////////////////////////////////////////////////////
	struct XAxis : public Axis
	{
	public:
		XAxis(AxisStyle style = AxisStyle());
	private:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();

		////////////////////////////////////////////////////////////
		/// \brief Recalculates the ticks to be shown on the graph
		///
		////////////////////////////////////////////////////////////
		void recalculate();
	};

	////////////////////////////////////////////////////////////
	/// \brief Graphable representing a coordinate y-axis
	///
	////////////////////////////////////////////////////////////
	struct YAxis : public Axis
	{
	public:
		YAxis(AxisStyle style = AxisStyle());
	private:
		////////////////////////////////////////////////////////////
		/// \brief Defines how the graphable is drawn to the graph
		///
		////////////////////////////////////////////////////////////
		void draw();

		////////////////////////////////////////////////////////////
		/// \brief Recalculates the ticks to be shown on the graph
		///
		////////////////////////////////////////////////////////////
		void recalculate();
	};

	////////////////////////////////////////////////////////////
	/// \brief Struct containing an x and y axis
	///
	////////////////////////////////////////////////////////////
	struct Axes
	{
		////////////////////////////////////////////////////////////
		/// \brief Convenience typedef of the Axes iterator type.
		///
		////////////////////////////////////////////////////////////
		typedef std::vector<std::reference_wrapper<Axis>>::iterator iterator;

		////////////////////////////////////////////////////////////
		/// \brief Construct from single style
		///
		/// Default constructs both x and y axes, and makes them iterable over.
		///
		////////////////////////////////////////////////////////////
		Axes(AxisStyle style = AxisStyle());

		////////////////////////////////////////////////////////////
		/// \brief Construct from individual styles
		///
		/// Default constructs both x and y axes, and makes them iterable over.
		///
		////////////////////////////////////////////////////////////
		Axes(AxisStyle x_style, AxisStyle y_style);

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator to the first axis
		///
		/// \return An iterator pointing to the first axis
		////////////////////////////////////////////////////////////
		iterator begin();

		////////////////////////////////////////////////////////////
		/// \brief Returns an iterator past the last axis
		///
		/// \return An iterator pointing past the last axis
		////////////////////////////////////////////////////////////
		iterator end();

		XAxis x; ///< The x axis
		YAxis y; ///< The y axis

	private:
		std::vector<std::reference_wrapper<Axis>> iterable_axes;
	};

} // namespace graphy

#endif //GRAPHY_AXIS_H
