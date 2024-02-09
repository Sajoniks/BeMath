#pragma once
#include <type_traits>
#include <cmath>

namespace BeMath
{
	template<typename T, typename Y>
	auto Pow(T a, Y b)
	{
		return static_cast<std::common_type_t<T, Y>>(std::pow(a, b));
	}

	template<typename T>
	auto Sqr(T a)
	{
		return Pow(a, 2);
	}

	template<typename T>
	auto Sqrt(T a)
	{
		return std::sqrt(a);
	}
}
