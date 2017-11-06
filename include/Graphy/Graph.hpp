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


#ifndef GRAPHY_GRAPH_H
#define GRAPHY_GRAPH_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <Graphy/Utils/StatusBar.hpp>
#include <Graphy/Utils/Vector2d.hpp>
#include <Graphy/Utils/DoubleRect.hpp>

namespace graphy
{

	struct Graphable;

	////////////////////////////////////////////////////////////
	/// \brief Master class that provides a canvas for graphables to be drawn
	///
	////////////////////////////////////////////////////////////
	class Graph
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief Constructs a new graph
		///
		/// This constructor creates the graph with the size and title
		/// defined by the parameters. 
		///
		/// \param title			The title of the graph displayed in the titlebar
		/// \param fullscreen	When true the \a width and \a height arguments are ignored and the graph window is made fullscreen
		/// \param width			Width of the graph window
		/// \param height		Height of the graph window
		///
		////////////////////////////////////////////////////////////
		Graph(const std::string& title = "Graphy", bool fullscreen = false, unsigned int width = 800, unsigned int height = 800);
		
		////////////////////////////////////////////////////////////
		/// \brief Destructor
		///
		/// Closes the graph and frees all the resources attached to it.
		///
		////////////////////////////////////////////////////////////
		~Graph();

		////////////////////////////////////////////////////////////
		/// \brief Modifies the graph's viewport
		///
		/// \param x_min	x-value at left boundary of graph
		/// \param x_max	x-value at right boundary of graph
		/// \param y_min	y-value at bottom boundary of graph
		/// \param y_max	y-value at top boundary of graph
		///
		////////////////////////////////////////////////////////////
		void zoom_to(double x_min, double x_max, double y_min, double y_max);

		////////////////////////////////////////////////////////////
		/// \brief Uniformly scales the graph's viewport
		///
		/// \param factor	Factor by which to scale the graph viewport
		///
		////////////////////////////////////////////////////////////
		void zoom_by(float factor);

		////////////////////////////////////////////////////////////
		/// \brief Scales the graph's viewport
		///
		/// \param x_factor	Factor by which to scale the graph viewport horizontally
		/// \param y_factor Factor by which to scale the graph viewport vertically
		///
		////////////////////////////////////////////////////////////
		void zoom_by(double x_factor, double y_factor);

		////////////////////////////////////////////////////////////
		/// \brief Shifts the graph's viewport relative to the current viewport in graph coordinates
		///
		/// \param x	Number of graph units to shift by horizontally
		/// \param y	Number of graph units to shift by vertically
		///
		////////////////////////////////////////////////////////////
		void shift_by(double x, double y);

		////////////////////////////////////////////////////////////
		/// \brief Shifts the graph's viewport relative to the current viewport in window coordinates
		///
		/// \param x	Number of pixels to shift by horizontally
		/// \param y	Number of pixels to shift by vertically
		///
		////////////////////////////////////////////////////////////
		void shift_px(float x, float y);

		////////////////////////////////////////////////////////////
		/// \brief Set the scrolling speed when moving around the graph in interactive mode
		///
		/// \param v Pixels to move per second
		///
		////////////////////////////////////////////////////////////
		void set_scroll_speed(float v);

		////////////////////////////////////////////////////////////
		/// \brief Set the zoom speed when moving around the graph in interactive mode
		///
		/// \param v Fraction of viewport to zoom per second
		///
		////////////////////////////////////////////////////////////
		void set_zoom_speed(float v);

		////////////////////////////////////////////////////////////
		/// \brief Add a graphable to the graph
		///
		/// Adds a reference of a graphable to the graph so that it
		/// will be drawn every time the graph is updated.
		///
		/// \param graphable The graphable to add to the graph
		///
		////////////////////////////////////////////////////////////
		void add(Graphable& graphable);

		////////////////////////////////////////////////////////////
		/// \brief Remove a graphable from the graph
		///
		/// Removes the graphable from the graph's internal list of 
		/// graphables. If the graphable isn't found then no
		/// graphable will be removed.
		///
		/// \param graphable The graphable to remove from the graph
		///
		////////////////////////////////////////////////////////////
		void remove(Graphable& graphable);

		////////////////////////////////////////////////////////////
		/// \brief Removes all graphables from the graph
		///
		////////////////////////////////////////////////////////////
		void clear();

		////////////////////////////////////////////////////////////
		/// \brief Load a font from file and use it as the default font for labels
		///
		/// \param Filename of the font to load
		///
		////////////////////////////////////////////////////////////
		void set_font(const std::string& filename);

		////////////////////////////////////////////////////////////
		/// \brief Sets the default name of screenshots taken of the graph
		///
		/// If this is not set, the default filename defaults to the title
		/// of the graph as set in the constructor. If multiple screenshots 
		/// are taken, they are labelled filename 1, filename 2 etc...
		///
		/// \param filename Name to be given to screenshots
		///
		////////////////////////////////////////////////////////////
		void set_default_filename(const std::string& filename);

		////////////////////////////////////////////////////////////
		/// \brief Enters the graph into interactive mode
		///
		/// In interactive mode, the graph is displayed in a blocking
		/// window and can be traversed using the arrow keys etc...
		///
		////////////////////////////////////////////////////////////
		void mainloop();

		////////////////////////////////////////////////////////////
		/// \brief Updates the graph
		///
		/// Clears the canvas and then redraws all graphables currently
		/// bound to the graph.
		///
		////////////////////////////////////////////////////////////
		void update();

		////////////////////////////////////////////////////////////
		/// \brief Takes a screenshot of the current graph viewport
		///
		////////////////////////////////////////////////////////////
		void print(const std::string& filename);

	private:
		friend Graphable;

		//Display
		sf::RenderWindow window; ///< Render window that is shown in the mainloop
		sf::RenderTexture layers[4]; ///< Render textures to hold different layers of the graph
		xsf::StatusBar sbar;
		static sf::ContextSettings context;
		static float status_bar_height;
		sf::Color bg_color;
		sf::Font font;
		float scroll_speed, zoom_speed;
		float height(), width();
		unsigned int height(bool), width(bool);
		std::string default_filename;
		int print_counter;

		//Graphing elements
		std::vector<Graphable*> graphables;
		sf::DoubleRect bounds;

		//Convert from graph coordinates to window coordinates
		//Absolute coordinates
		sf::Vector2f map(double x, double y);
		sf::Vector2f map(sf::Vector2d p);
		float map_x(double x);
		float map_y(double y);
		//Relative coordinates
		sf::Vector2f rmap(double x, double y);
		sf::Vector2f rmap(sf::Vector2d p);
		float rmap_x(double x);
		float rmap_y(double y);

		//Convert from window coordinates to graph coordinates
		//Absolute coordinates
		sf::Vector2d amap(float x, float y);
		sf::Vector2d amap(sf::Vector2f p);
		double amap_x(float x);
		double amap_y(float y);
		//Relative coordinate
		sf::Vector2d armap(float x, float y);
		sf::Vector2d armap(sf::Vector2f p);
		double armap_x(float x);
		double armap_y(float y);

	};

} //namespace graphy

#endif //GRAPHY_GRAPH_H


////////////////////////////////////////////////////////////
/// \class graphy::Graph
///
/// graphy::Graph is the main class of Graphy. It defines a
/// canvas on which graphables can be placed and drawn. 
///
/// Usage example:
/// \code
/// //Declare and create a new graph
/// graphy::Graph graph;
/// 
/// //Make some graphables graphable
/// graphy::Axes axes;
/// graphy::Equation eq([] (double x) { return x*x; });
///
/// //Add the graphables to the graph
/// graph.add(axes.x);
/// graph.add(axes.y);
/// graph.add(eq);
///
/// //Enter the mainloop
/// graph.mainloop();
/// \endcode
///
////////////////////////////////////////////////////////////
