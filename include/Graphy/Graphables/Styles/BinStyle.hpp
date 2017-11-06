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

#ifndef GRAPHY_HISTOGRAMSTYLE_H
#define GRAPHY_HISTOGRAMSTYLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <Graphy/Utils/random_color.hpp>
#include <Graphy/Graphables/Styles/LabelStyle.hpp>


namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Struct to hold styling attributes for graphy::Bin class
	///
	////////////////////////////////////////////////////////////
	struct BinStyle
	{
		////////////////////////////////////////////////////////////
		/// \brief Default constructor
		///
		/// Constructs a default style.
		///
		////////////////////////////////////////////////////////////
		BinStyle() :
			color(xsf::random_color()),
			label()
		{}

		sf::Color color; ///< Colour of the bin
		LabelStyle label; ///< Label style

		////////////////////////////////////////////////////////////
		/// \brief Returns a red BinStyle
		///
		/// \param text The label of the bin
		////////////////////////////////////////////////////////////
		static BinStyle Red(std::string text)
		{
			BinStyle b;
			b.color = sf::Color::Red;
			b.label.text = text;
			b.label.enabled = true;
			return b;
		}

		////////////////////////////////////////////////////////////
		/// \brief Returns a blue BinStyle
		///
		/// \param text The label of the bin
		////////////////////////////////////////////////////////////
		static BinStyle Blue(std::string text)
		{
			BinStyle b;
			b.color = sf::Color::Blue;
			b.label.text = text;
			b.label.enabled = true;
			return b;
		}

		////////////////////////////////////////////////////////////
		/// \brief Returns a green BinStyle
		///
		/// \param text The label of the bin
		////////////////////////////////////////////////////////////
		static BinStyle Green(std::string text)
		{
			BinStyle b;
			b.color = sf::Color::Green;
			b.label.text = text;
			b.label.enabled = true;
			return b;
		}

		////////////////////////////////////////////////////////////
		/// \brief Returns a yellow BinStyle
		///
		/// \param text The label of the bin
		////////////////////////////////////////////////////////////
		static BinStyle Yellow(std::string text)
		{
			BinStyle b;
			b.color = sf::Color::Yellow;
			b.label.text = text;
			b.label.enabled = true;
			return b;
		}
	};

} // namespace graphy

#endif //GRAPHY_HISTOGRAMSTYLE_H
