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

#ifndef GRAPHY_LINALG_H
#define GRAPHY_LINALG_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <boost/numeric/ublas/matrix_vector.hpp>
#include <boost/numeric/ublas/exception.hpp>

namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Construct a matrix from a list of its elements
	///
	/// \param size1 Number of rows in the matrix
	/// \param size2 Number of columns in the matrix
	/// \param m Initializer list containing the elements of the matrix
	///
	/// \return A matrix containing the elements in m
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	boost::numeric::ublas::matrix<T> make_matrix(unsigned int size1, unsigned int size2, std::initializer_list<T> m)
	{
		if (size1 * size2 != m.size())
			throw boost::numeric::ublas::bad_size("Number of matrix elements not equal to number of elements provided");

		boost::numeric::ublas::matrix<T> r(size1, size2); //Construct output matrix
		unsigned int i = 0; //Current element
		for (auto it = m.begin(), end = m.end(); it != m.end(); ++i, ++it)
			r(i / size1, i % size1) = *it; //Assign current element to position in matrix
		return r;
	}

	////////////////////////////////////////////////////////////
	/// \brief Functions which returns a minor matrix from a matrix
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	boost::numeric::ublas::matrix<T> matrix_minor(const boost::numeric::ublas::matrix<T>& m, unsigned int row, unsigned int col)
	{
		boost::numeric::ublas::matrix<T> mm(m.size1() - 1, m.size2() - 1);
		for (unsigned int i = 0; i < m.size1(); ++i) {
			for (unsigned int j = 0; j < m.size2(); ++j) {
				mm(i, j) = m(i >= row ? i + 1 : i, j >= col ? j + 1 : j);
			}
		}
		return mm;
	}

	////////////////////////////////////////////////////////////
	/// \brief Applys a small perturbation to a vector element
	///
	/// \param vec The vector to perturb
	/// \param element The index of the element to perturb
	/// \epsilon The perturbation to apply
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	boost::numeric::ublas::vector<T> perturb(boost::numeric::ublas::vector<T> vec, unsigned int element, T epsilon)
	{
		vec[element] += epsilon;
		return vec;
	}

	////////////////////////////////////////////////////////////
	/// \brief Returns the inverse matrix
	///
	/// \param A The matrix to invert
	///
	/// \return The inverted matrix on success, or a matrix of inf on failure
	///
	////////////////////////////////////////////////////////////
	template <typename T>
	boost::numeric::ublas::matrix<T> inverse(boost::numeric::ublas::matrix<T> A)
	{
		namespace ublas = boost::numeric::ublas;
		//Gauss-Jordan method of matrix inversion

		//Can only invert a square matrix
		if (A.size1() != A.size2())
			throw ublas::bad_size("Cannot invert a non-square matrix");

		//Append the identity matrix to the right of A

		//Specify size of altered matrix
		const unsigned int rows = A.size1();
		const unsigned int cols = A.size2() * 2;

		//Resize
		A.resize(A.size1(), A.size2() * 2, true);

		//Fill new elements with identity matrix
		ublas::subrange(A, 0, A.size1(), A.size1(), A.size2()) = ublas::identity_matrix<T>(A.size1());

		//Loop through all rows
		for (unsigned int y = 0; y < rows; ++y) {
			//Find pivot row
			int max_row = y;
			for (unsigned int y2 = y + 1; y2 < rows; ++y2) {
				if (std::abs(A(y2, y)) > std::abs(A(max_row, y)))
					max_row = y2;
			}
			//Swap current row and pivot row
			if (max_row != y) {
				for (unsigned int x = 0; x < cols; ++x)
					std::swap(A(y, x), A(max_row, x));
			}
			//Eliminate the yth column
			for (unsigned int y2 = y + 1; y2 < rows; ++y2) {
				T c = A(y2, y) / A(y, y);
				for (unsigned int x = 0; x < cols; ++x) {
					A(y2, x) -= A(y, x) * c;
				}
			}
		}
		//Backsubstitute
		for (unsigned int y = rows - 1; y + 1 != 0; --y) {
			//Normalise the leading value in each row
			T c = A(y, y);
			for (unsigned int x = y; x < cols; ++x)
				A(y, x) /= c;
			for (unsigned int y2 = 0; y2 < y; ++y2) {
				c = A(y2, y);
				for (unsigned int x = 0; x < cols; ++x)
					A(y2, x) -= c * A(y, x);
			}
		}

		//Return the right hand side of A
		return ublas::matrix<T>(ublas::subrange(A, 0, rows, rows, cols));
	}

	////////////////////////////////////////////////////////////
	/// \brief Calcaulate the determinant of the matrix
	///
	/// \param A The matrix to calculate the determinant of
	/// \param i The row along which to calculate the determinant
	////////////////////////////////////////////////////////////
	template <typename T>
	T det(const boost::numeric::ublas::matrix<T>& A, unsigned int i = 0)
	{
		if (A.size1() != A.size2())
			throw boost::numeric::ublas::bad_size("Matrix must be square to find determinant");

		unsigned int n = A.size1(); //Size of the matrix
		T d = 0; //Value of the determinant

		if (n == 1) //Determinant of 1x1 is just the value
			d = A(0, 0);
		else if (n == 2) //Special formula for 2x2
			d = A(0, 0) * A(1, 1) - A(1, 0) * A(0, 1);
		else { //In the general case recursively reduce the determinant into a sum of 2x2 matrix determinants
			for (unsigned int j = 0; j < n; ++j)
				d += static_cast<T>((j % 2 == 0 ? 1 : -1) * A(i, j) * det(matrix_minor(A, i, j)));
		}
		return d;
	}

} // namespace graphy

#endif //GRAPHY_LINALG_H