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

#ifndef GRAPHY_REGRESSION_H
#define GRAPHY_REGRESSION_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <vector>
#include <iosfwd>
#include <iomanip>
#include "DataSet.h"
#include "bind_array.h"
#include "linalg.h"


namespace graphy
{
	class DataSet;

	////////////////////////////////////////////////////////////
	/// \brief Performs multi-variate regression on a data set
	///
	////////////////////////////////////////////////////////////
	struct Regression
	{
		////////////////////////////////////////////////////////////
		/// \brief Constructor from function pointer
		///
		/// \param func The function with variables paramaters to fit to the data
		/// \param data The data to which the function should be fitted
		///
		////////////////////////////////////////////////////////////
		template <typename... Params>
		Regression(double(*func)(double, Params...), const DataSet& data) :
			Regression(std::function<double(double, Params...)>(func), data)
		{
		}

		////////////////////////////////////////////////////////////
		/// \brief Constructor from pointer to member function
		///
		/// \param func The function with variables paramaters to fit to the data
		/// \param data The data to which the function should be fitted
		///
		////////////////////////////////////////////////////////////
		template <typename T, typename Ret, typename ParamA, typename... Params>
		Regression(Ret(T::*func)(ParamA, Params...), const DataSet& data) :
			Regression(std::function<double(double, Params...)>(func), data)
		{
		}

		////////////////////////////////////////////////////////////
		/// \brief Constructor from poitner to const member function
		///
		/// \param func The function with variables paramaters to fit to the data
		/// \param data The data to which the function should be fitted
		///
		////////////////////////////////////////////////////////////
		template <typename T, typename Ret, typename ParamA, typename... Params>
		Regression(Ret(T::*f)(ParamA, Params...) const, const DataSet& data) :
			Regression(std::function<double(double, Params...)>(func), data)
		{
		}

		////////////////////////////////////////////////////////////
		/// \brief Constructor from std::function
		///
		/// \param func The function with variables paramaters to fit to the data
		/// \param data The data to which the function should be fitted
		///
		////////////////////////////////////////////////////////////
		template <typename... Params>
		Regression(const std::function<double(double, Params...)>& func, const DataSet& data)
		{
			regress(func, data);
		}

		std::vector<double> params; ///< Ordered array of the paramaters containing their estimated values
		std::vector<double> params_error; ///< Ordered array of the paramaters containing their estimated standard errors
		boost::numeric::ublas::matrix<double> covariance; ///< Matrix containing the covariace between paramaters
		std::function<double(double)> function; ///< The bind_arrayd function that fits the data points
		double r2; ///< The r^2 value of the fit
		double variance; ///< The total variance of the regression

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes a constant regression line
		///
		////////////////////////////////////////////////////////////
		static double constant(double x, double a)
		{
			return a;
		}

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes a linear regression line
		///
		////////////////////////////////////////////////////////////
		static double linear(double x, double a, double b)
		{
			return a*x + b;
		}

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes a quadratic regression line
		///
		////////////////////////////////////////////////////////////
		static double quadratic(double x, double a, double b, double c)
		{
			return a*x*x + b*x + c;
		}

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes a cubic regression line
		///
		////////////////////////////////////////////////////////////
		static double cubic(double x, double a, double b, double c, double d)
		{
			return a*x*x*x + b*x*x + c*x + d;
		}

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes a rational function regression line
		///
		////////////////////////////////////////////////////////////
		static double rational(double x, double a, double b, double c, double d)
		{
			return (a*x + b) / (c*x + d);
		}

		////////////////////////////////////////////////////////////
		/// \brief Default function that computes an exponential regression line
		///
		////////////////////////////////////////////////////////////
		static double exponential(double x, double a, double b)
		{
			return a * std::pow(b, x);
		}

	private:
		template <typename... Params>
		void regress(const std::function<double(double, Params...)>& func, const DataSet& data)
		{
			namespace ublas = boost::numeric::ublas;
			const unsigned int n = sizeof...(Params); //Number of parameters to guess
			const unsigned int m = data.points.size(); //Number of data points
			const double delta = 0.0001; //Constant used for numeric differentiation
			unsigned int iterations = 10; //Number of times to repeat the algorithm

			if (m < n) //Jacobian is not invertible if m < n
				throw std::logic_error("Data set must be at least as big as numer of paramaters to guess");

			ublas::matrix<double> J(m, n); //Jacobian matrix, m x n
			ublas::vector<double> B(n, 1); //Parameters vector, size n - defaults to guess 1
			ublas::vector<double> r(m); //Residues vector, size m


			while (--iterations) {
				std::function<double(double)> cur_f = bind_array(func, B);
				//Calculate the residues
				for (unsigned int i = 0; i < m; ++i) {
					r(i) = cur_f(data.points[i].x) - data.points[i].y;
				}

				//Calculate the Jacobian and residues
				for (unsigned int i = 0; i < m; ++i) {
					for (unsigned int j = 0; j < n; ++j)
						J(i, j) = (bind_array(func, perturb(B, j, delta))(data.points[i].x) - cur_f(data.points[i].x)) / delta;
				}

				//Calculate the next iteration of the parameters
				ublas::matrix<double> J_pi = inverse(ublas::matrix<double>(ublas::prod(ublas::trans(J), J)));
				J_pi = ublas::prod(J_pi, ublas::trans(J));
				B -= ublas::prod(J_pi, r);
			}

			function = bind_array(func, B);
			params.assign(B.begin(), B.end());

			//Find other values of interest

			/////////////////////////////////
			//Coefficient of determination
			/////////////////////////////////
			
			//Calculate mean of the data
			double mean = 0;
			for (const Point& point : data)
				mean += point.y;
			mean /= data.points.size();
			//Calculate total sum of squares and residual sum of squares
			double ss_tot = 0;
			double ss_res = 0;
			for (const Point& point : data) {
				ss_tot += (point.y - mean) * (point.y - mean);
				ss_res += (point.y - function(point.x)) * (point.y - function(point.x));
			}
			r2 = 1 - ss_res / ss_tot;

			/////////////////////////////////
			//Covariance matrix and standard error of parameters
			/////////////////////////////////

			//Calculate the variance of errors
			variance = ss_res / (m - n);

			//Calculate the matrix of coefficients
			covariance.resize(m, n);
			for (unsigned int j = 0; j < n; ++j) {
				B = ublas::unit_vector<double>(n, j);
				std::function<double(double)> cur_f = bind_array(func, B);
				for (unsigned int i = 0; i < m; ++i) {
					covariance(i, j) = cur_f(data.points[i].x);
				}
			}
			//Left-multiply the transpose with the matrix
			covariance = ublas::prod(ublas::trans(covariance), covariance);
			//Invert
			covariance = inverse(covariance);
			//Scalar multiply by the variance
			covariance *= variance;
	
			//Fill error vector with the sqrt of diagonal elements
			params_error.resize(n);
			for (unsigned int i = 0; i < n; ++i)
				params_error[i] = std::sqrt(covariance(i, i));
		}
	};

	////////////////////////////////////////////////////////////
	/// \brief Prints the values of the regression class to a stream
	///
	////////////////////////////////////////////////////////////
	std::ostream& operator << (std::ostream& stream, const Regression& rhs)
	{
		//Print paramaters with their error
		stream << " Parameter |   Value   | Standard Error\n";
		for (unsigned int i = 0; i < rhs.params.size(); ++i)
			stream << "     " << static_cast<char>('a' + i) << "     | " << std::setw(9) << std::setprecision(3) << rhs.params[i] << " | " << rhs.params_error[i] << '\n';

		//Print r2 and variance
		stream << "\n   r^2 = " << rhs.r2 << "\n   Var = " << rhs.variance << "\n\n";

		//Print the covariance matrix
		stream << "Covariance matrix of paramaters:\n\n";
		for (unsigned int i = 0; i < rhs.covariance.size1(); ++i) {
			for (unsigned int j = 0; j < rhs.covariance.size2(); ++j) {
				stream << std::setw(13) << std::setprecision(3) << rhs.covariance(i, j);
			}
			stream << "\n\n";
		}
		return stream;
	}

} // namespace graphy

#endif //GRAPHY_REGRESSION_H