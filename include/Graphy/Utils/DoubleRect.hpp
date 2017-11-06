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

#ifndef GRAPHY_DOUBLERECT_H
#define GRAPHY_DOUBLERECT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Rect.hpp>
#include <iosfwd>

namespace sf
{

	////////////////////////////////////////////////////////////
	/// \brief Convenience typedef for a sf::Rect<T> with T=double
	///
	////////////////////////////////////////////////////////////
	typedef sf::Rect<double> DoubleRect;

} // namespace sf


template <typename T>
bool operator < (const sf::Rect<T>& lhs, const sf::Rect<T>& rhs) ///< Returns true if rhs contains lhs
{
	return (lhs.left > rhs.left) && (lhs.top > rhs.top) && (lhs.left + lhs.width < rhs.left + rhs.width) && (lhs.top + lhs.height < rhs.top + rhs.height);
}

template <typename T>
bool operator > (const sf::Rect<T>& lhs, const sf::Rect<T>& rhs) ///< Returns true if lhs contains rhs
{
	return (lhs.left < rhs.left) && (lhs.top < rhs.top) && (lhs.left + lhs.width > rhs.left + rhs.width) && (lhs.top + lhs.height > rhs.top + rhs.height);
}

template <typename T>
bool operator <= (const sf::Rect<T>& lhs, const sf::Rect<T>& rhs) ///< Returns true if rhs contains or is equal to lhs
{
	return (lhs.left >= rhs.left) && (lhs.top >= rhs.top) && (lhs.left + lhs.width <= rhs.left + rhs.width) && (lhs.top + lhs.height <= rhs.top + rhs.height);
}

template <typename T>
bool operator >= (const sf::Rect<T>& lhs, const sf::Rect<T>& rhs) ///< Returns true is lhs contains or is equal to rhs
{
	return (lhs.left <= rhs.left) && (lhs.top <= rhs.top) && (lhs.left + lhs.width >= rhs.left + rhs.width) && (lhs.top + lhs.height >= rhs.top + rhs.height);
}

template <typename T>
sf::Rect<T>& operator += (sf::Rect<T>& lhs, const sf::Vector2<T> rhs) ///< Shifts lhs by rhs
{
	lhs.top += rhs.y;
	lhs.left += rhs.x;
	return lhs;
}

template <typename T>
sf::Rect<T>& operator -= (sf::Rect<T>& lhs, const sf::Vector2<T> rhs) ///< Shifts lhs by the negative of rhs
{
	lhs.top -= rhs.y;
	lhs.left -= rhs.x;
	return lhs;
}

template <typename T>
sf::Rect<T> operator + (sf::Rect<T> lhs, const sf::Vector2<T> rhs) ///< Returns the result of shifting lhs by rhs
{
	return lhs += rhs;
}

template <typename T>
sf::Rect<T> operator - (sf::Rect<T> lhs, const sf::Vector2<T> rhs) ///< Returns the result of shifting lhs by the negatie of rhs
{
	return lhs -= rhs;
}

template <typename T>
sf::Rect<T>& operator *= (sf::Rect<T>& lhs, const sf::Vector2<T> rhs) ///< Increase the scale of lhs by rhs in each direction leaving the center point invariant
{
	T dx = lhs.width * (rhs.x - 1);
	T dy = lhs.height * (rhs.y - 1);

	lhs.width -= dx;
	lhs.height -= dy;
	lhs.left += dx / 2;
	lhs.top -= dy / 2;

	return lhs;
}

template <typename T>
sf::Rect<T>& operator *= (sf::Rect<T>& lhs, T rhs) ///< Increase the scale of lhs by rhs in each direction leaving the center point invariant
{
	T dx = lhs.width * (rhs - 1);
	T dy = lhs.height * (rhs - 1);

	lhs.width -= dx;
	lhs.height += dy;
	lhs.left += dx / 2;
	lhs.top -= dy / 2;

	return lhs;
}

template <typename T>
sf::Rect<T>& operator /= (sf::Rect<T>& lhs, const sf::Vector2<T> rhs) ///< Increase the scale of lhs by rhs in each direction leaving the center point invariant
{
	T dx = lhs.width * (1 / rhs.x - 1);
	T dy = lhs.height * (1 / rhs.y - 1);

	lhs.width += dx;
	lhs.height += dy;
	lhs.left -= dx / 2;
	lhs.top -= dy / 2;

	return lhs;
}

template <typename T>
sf::Rect<T>& operator /= (sf::Rect<T>& lhs, T rhs) ///< Decreases the scale of lhs by rhs in each direction leaving the center point invariant
{
	T dx = lhs.width * (1 / rhs - 1);
	T dy = lhs.height * (1 / rhs - 1);

	lhs.width += dx;
	lhs.height += dy;
	lhs.left -= dx / 2;
	lhs.top -= dy / 2;

	return lhs;
}

template <typename T>
sf::Rect<T> operator * (sf::Rect<T> lhs, const sf::Vector2<T>& rhs) ///< Increases the scale of lhs by rhs in each direction leaving the center point invariant
{
	return lhs *= rhs;
}

template <typename T>
sf::Rect<T> operator * (sf::Rect<T> lhs, T rhs) ///< Increases the scale of lhs by rhs in each direction leaving the center point invariant
{
	return lhs *= rhs;
}

template <typename T>
sf::Rect<T> operator / (sf::Rect<T> lhs, const sf::Vector2<T>& rhs) ///< Decreases the scale of lhs by rhs in each direction leaving the center point invariant
{
	return lhs /= rhs;
}

template <typename T>
sf::Rect<T> operator / (sf::Rect<T> lhs, T rhs) ///< Decreases the scale of lhs by rhs in each direction leaving the center point invariant
{
	return lhs /= rhs;
}

template <typename T>
std::ostream& operator << (std::ostream& stream, sf::Rect<T> rhs) ///< Prints a rect to an output stream
{
	stream << "("
		<< rhs.left << (rhs.width > 0 ? " + " : " - ") << std::abs(rhs.width) << ", "
		<< rhs.top << (rhs.height > 0 ? " + " : " - ") << std::abs(rhs.height) << ")";
	return stream;
}

#endif //GRAPHY_DOUBLERECT_H