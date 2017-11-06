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

#ifndef GRAPHY_EVAL_H
#define GRAPHY_EVAL_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <functional>
#include <exception>

namespace graphy
{
	////////////////////////////////////////////////////////////
	/// \brief Binds an array of values to a function leaving it with only the first argument
	///
	/// \param func The function to bind
	/// \param begin Iterator pointing to the first item in the array
	/// \param end Iterator pointing to the last item in the array
	///
	////////////////////////////////////////////////////////////
	template <typename Ret, typename Arg1, typename... Args, typename It>
	std::function<Ret(Arg1)> bind_array(const std::function<Ret(Arg1, Args...)>& func, It begin, It end)
	{
		if (std::distance(begin, end) > sizeof...(Args))
			throw std::logic_error("Size of array is less than number of paramaters required to call function");
		return priv::collapse_impl<sizeof...(Args)>::call(func, begin);
	}

	////////////////////////////////////////////////////////////
	/// \brief Binds an array of values to a function leaving it with only the first argument
	///
	/// \param func The function to bind
	/// \param params Container holding the paramaters to bind to the function
	///
	////////////////////////////////////////////////////////////
	template <typename Ret, typename Arg1, typename... Args, typename Container>
	std::function<Ret(Arg1)> bind_array(const std::function<Ret(Arg1, Args...)>& func, const Container& params)
	{
		return bind_array(func, params.begin(), params.end());
	}

	namespace priv
	{
		template <unsigned int num_params>
		struct collapse_impl {};

		template <>
		struct collapse_impl<0>
		{
			template <typename Ret, typename Arg1, typename... Args, typename It>
			static std::function<Ret(Arg1)> call(const std::function<Ret(Arg1, Args...)>& func, It begin)
			{
				return std::bind(func, std::placeholders::_1);
			}
		};

		template <>
		struct collapse_impl<1>
		{
			template <typename Ret, typename Arg1, typename... Args, typename It>
			static std::function<Ret(Arg1)> call(const std::function<Ret(Arg1, Args...)>& func, It begin)
			{
				return std::bind(func, std::placeholders::_1, begin[0]);
			}
		};

		template <>
		struct collapse_impl<2>
		{
			template <typename Ret, typename Arg1, typename... Args, typename It>
			static std::function<Ret(Arg1)> call(const std::function<Ret(Arg1, Args...)>& func, It begin)
			{
				return std::bind(func, std::placeholders::_1, begin[0], begin[1]);
			}
		};

		template <>
		struct collapse_impl<3>
		{
			template <typename Ret, typename Arg1, typename... Args, typename It>
			static std::function<Ret(Arg1)> call(const std::function<Ret(Arg1, Args...)>& func, It begin)
			{
				return std::bind(func, std::placeholders::_1, begin[0], begin[1], begin[2]);
			}
		};

		template <>
		struct collapse_impl<4>
		{
			template <typename Ret, typename Arg1, typename... Args, typename It>
			static std::function<Ret(Arg1)> call(const std::function<Ret(Arg1, Args...)>& func, It begin)
			{
				return std::bind(func, std::placeholders::_1, begin[0], begin[1], begin[2], begin[3]);
			}
		};
	}
} // namespace graphy

#endif //GRAPHY_EVAL_H