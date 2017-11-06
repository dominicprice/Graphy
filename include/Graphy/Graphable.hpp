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

#ifndef GRAPHY_GRAPHABLE_H
#define GRAPHY_GRAPHABLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <functional>
#include <Graphy/Utils/Vector2d.hpp>
#include <Graphy/Utils/DoubleRect.hpp>


namespace graphy
{

	class Graph;

	////////////////////////////////////////////////////////////
	/// \brief Pure virtual class defining the interface for a graphable object
	///
	////////////////////////////////////////////////////////////
	struct Graphable
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Default Constructor
		///
		/// Constructs a new graphable
		///
		////////////////////////////////////////////////////////////
		Graphable();

	protected:
		////////////////////////////////////////////////////////////
		/// \brief Pure virtual function which can be overriden to define how the graphable should be drawn
		///
		////////////////////////////////////////////////////////////
		virtual void draw() = 0;

		////////////////////////////////////////////////////////////
		/// \brief Returns the current bounds of the graph in graph coordinates
		///
		////////////////////////////////////////////////////////////
		sf::DoubleRect& bounds();


		sf::Vector2f map(double x, double y); ///< Maps a position in graph coordinates to a position in window coordinates
		sf::Vector2f map(sf::Vector2d p); ///< Maps a position vector in graph coordinates to a position in window coordinates
		float map_x(double x); ///< Maps an x-position in graph coordinates to a position in window coordinates
		float map_y(double y); ///< Maps a y-position in graph coordinates to a position in window coordinates
		sf::Vector2f rmap(double x, double y); ///< Maps a distance in graph coordinates to a distance in window coordinates
		sf::Vector2f rmap(sf::Vector2d p); ///< Maps a distance vector in graph coordinates to a distance in window coordinates
		float rmap_x(double x); ///< Maps an x-distance in graph coordinates to a distance in window coordinates
		float rmap_y(double y); ///< Maps a y-distance in graph coordinates to a distance in window coordinates
		sf::Vector2d amap(float x, float y); ///< Maps a position in window coordinates to a position in graph coordinates
		sf::Vector2d amap(sf::Vector2f p); ///< Maps a position vector in window coordinates to a position in graph coordinates
		double amap_x(float x); ///< Maps an x-position in window coordinates to a position in graph coordinates
		double amap_y(float y); ///< Maps a yposition in window coordinates to a position in graph coordinates
		sf::Vector2d armap(float x, float y); ///< Maps a distance in window coordinates to a distance in graph coordinates
		sf::Vector2d armap(sf::Vector2f p); ///< Maps a distance vector in window coordinates to a distance in graph coordinates
		double armap_x(float x); ///< Maps an x-distance in window coordinates to a distance in graph coordinates
		double armap_y(float y); ///< Maps a y-distance in window coordinates to a distance in graph coordinates

		////////////////////////////////////////////////////////////
		/// \brief Proxy object providing basic drawing tools
		///
		////////////////////////////////////////////////////////////
		struct Canvas
		{
			////////////////////////////////////////////////////////////
			/// \brief Defines the layer of the canvas on which to draw
			///
			////////////////////////////////////////////////////////////
			enum Layer : signed char
			{
				Background, ///< Layer furthest back, used for large colour fills
				Axes, ///< Layer on which axes and other scales are drawn
				Objects, ///< Layer on which lines and points are drawn
				Labels ///< Foremost layer where text is drawn
			};

			////////////////////////////////////////////////////////////
			/// \brief Returns the default font used by the graph
			///
			////////////////////////////////////////////////////////////
			sf::Font& font();

			////////////////////////////////////////////////////////////
			/// \brief Returns the width in pixels of the graph window
			///
			////////////////////////////////////////////////////////////
			float width();

			////////////////////////////////////////////////////////////
			/// \brief Returns the height in pixels of the graph window
			///
			////////////////////////////////////////////////////////////
			float height();

			////////////////////////////////////////////////////////////
			/// \brief Draws an array of vertices to the graph
			///
			/// \param vertices Pointer to the first vertex in an array of vertices
			/// \param vertex_count Number of vertices in the array
			/// \param type Primitive type to draw vertices
			/// \param states Render states to draw vertices
			///
			////////////////////////////////////////////////////////////
			void draw(Layer layer, const sf::Vertex* vertices, size_t vertex_count, sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default);

			////////////////////////////////////////////////////////////
			/// \brief Draws a drawable object to the graph
			///
			/// \param drawable The object to be drawn
			/// \param states Render states to draw object
			///
			////////////////////////////////////////////////////////////
			void draw(Layer layer, const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

		private:
			friend Graphable;
			Canvas(Graphable* graphable);
			Graphable* graphable;
		} canvas; ///< Provides a minimal public interface to drawing functions for the graph's canvas
	private:
		friend Graph;
		Graph* graph;
	};

} // namespace graphy

#endif //GRAPHY_GRAPHABLE_H
