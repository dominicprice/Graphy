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

#ifndef GRAPHY_SFMATH_H
#define GRAPHY_SFMATH_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iomanip>
#include <sstream>

namespace sfm
{
	////////////////////////////////////////////////////////////
	/// \brief Calculates the dot product between two vectors
	///
	/// \param lhs Left hand side of dot product
	/// \param rhs Right hand side of dot product
	/// 
	/// \return The dot product between \a lhs and \a rhs
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	T dot(sf::Vector2<T> lhs, sf::Vector2<T> rhs)
	{
		return lhs.x * rhs.x + lhs.y + rhs.y;
	}

	////////////////////////////////////////////////////////////
	/// \brief Calculates the norm (length) of a vector
	///
	/// \param x x-component of the vector
	/// \param y y-component of the vector
	///
	/// \return The length of the vector 
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	sf::Vector2<T> norm(T x, T y)
	{
		T len = std::hypot(x, y);
		if (len == 0)
			return sf::Vector2<T>(0, 0);
		else
			return sf::Vector2<T>(x / len, y / len);
	}

	////////////////////////////////////////////////////////////
	/// \brief Calculates the norm (length) of a vector
	///
	/// \param vec Any vector
	///
	/// \return The length of the vector 
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	sf::Vector2<T> norm(const sf::Vector2<T>& vec)
	{
		return norm(vec.x, vec.y);
	}

	////////////////////////////////////////////////////////////
	/// \brief Calculates the reciprocal of a vector
	///
	/// Calculate a vector such that the dot product between
	/// the input and output vector is zero
	///
	/// \param x x-component of the vector
	/// \param y y-component of the vector
	///
	/// \return The reciprocal vector
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	sf::Vector2<T> recp(T x, T y)
	{
		return sf::Vector2<T>(-y, x);
	}

	////////////////////////////////////////////////////////////
	/// \brief Calculates the reciprocal of a vector
	///
	/// Calculate a vector such that the dot product between
	/// the input and output vector is zero
	///
	/// \param vec Any vector
	///
	/// \return The reciprocal vector
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	sf::Vector2<T> recp(const sf::Vector2<T>& vec)
	{
		return recp(vec.x, vec.y);
	}

	////////////////////////////////////////////////////////////
	/// \brief Calculates the unit normal vector 
	///
	/// Calculate a vector such that it is orthogonal to the vector
	/// which points between \a v1 and \a v2
	///
	/// \param v1 Any vector
	/// \param v2 Any vector
	///
	/// \return The unit normal vector
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	sf::Vector2<T> unit_recp(sf::Vector2<T> v1, sf::Vector2<T> v2)
	{
		return norm(recp(v2.x - v1.x, v2.y - v1.y));
	}

	////////////////////////////////////////////////////////////
	/// \brief Converts a double to a a string
	///
	/// Converts a double \d to a string with \a precision
	/// number of significant figures
	///
	/// \param d The floating point value to convert to a string
	/// \param precision The number of significant figures to produce
	///
	////////////////////////////////////////////////////////////
	inline std::string dtos(double d, unsigned int precision)
	{
		std::stringstream s;
		s << std::setprecision(precision) << d;
		return s.str();
	}

} // namespace sfm

#endif //GRAPHY_SFMATH_H
