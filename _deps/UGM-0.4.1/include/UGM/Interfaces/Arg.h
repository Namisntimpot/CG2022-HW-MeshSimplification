#pragma once

#include <UTemplate/Typelist.h>
#include <UTemplate/Num.h>

namespace Ubpa {
	struct Arg_Empty {};

	template<typename ArgList>
	using Arg_T = At_t<At_t<ArgList, 0>, 0>;

	template<typename ArgList>
	constexpr size_t Arg_N = At_t<At_t<ArgList, 0>, 1>::value;

	template<typename ArgList>
	using Arg_F = At_t<ArgList, 1>;

	template<typename ArgList>
	using Arg_Vector = At_t<ArgList, 2>;

	template<typename ArgList>
	using Arg_Point = At_t<ArgList, 3>;
}
