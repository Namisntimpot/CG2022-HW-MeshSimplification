#pragma once

#include "mat.h"

namespace Ubpa {
	// vector in surface coordinate system (right-hand)
	// most functions assert(normalized())
	// x: tangent
	// y: bitangent
	// z: normal
	// stheta : angle between vector and normal(z) [0 - pi], 's' means [s]urface
	// sphi : angle between vector and tangent(x) [0 - 2pi], 's' means [s]urface
	template<typename T>
	struct svec : SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, svec<T>, TypeList<TypeList<T, Size<3>>, T>> {
		using SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, svec<T>, TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;

		// TBN matrix : local(surface) to world
		// require: n is perpendicular to t
		static const mat<T, 3> TBN(const vec<T, 3>& n, const vec<T, 3>& t) noexcept;

		static const svec mid(const svec<T>& x, const svec<T>& y) noexcept;
		const svec mid(const svec<T>& y) const noexcept;

		T cos_stheta() const noexcept; // assert(normalized())

		T sin_stheta() const noexcept; // assert(normalized())

		// if this is normal, return 1
		T cos_sphi() const noexcept; // assert(normalized())

		// if this is normal, return 0
		T sin_sphi() const noexcept; // assert(normalized())

		// z > 0
		bool is_above() const noexcept;

		// [summary]
		// this is inward direction (**outward** from surface), maybe under the surface
		// reflected direction is outward direction (**outward** from surface) on the same side
		// [return]
		// - outward (this->norm() == result.norm())
		const svec reflect() const noexcept;
		
		// [summary]
		// - `this` is inward direction (**outward** from surface), maybe under surface
		// - refracted direction is outward direction (**outward** from surface) on the other side of the surface
		// - **total internal reflection** may occur
		// [argument]
		// - etai : refractive index of the media on the incident side
		// - etao : refractive index of the media on the transmitted side
		// [return]
		// - bool: whether refract is success
		// - svec: normalized outward
		const std::tuple<bool, svec> refract(T etai, T etao) const noexcept; // assert(normalized())
		
		// [summary]
		// - call `refract(T, T)` internally
		// - use `is_above()` to distinguish `etai` and `etao`
		// [argument]
		// - eta : refractive index of material (refractive index of air is 1 as default)
		// [return]
		// - bool: whether refract is success
		// - svec: normalized outward
		const std::tuple<bool, svec> refract(T eta) const noexcept; // assert(normalized())
	};

	// local to world
	// m is generated by svec<T>::TBN()
	template<typename T>
	const vec<T, 3> operator*(const mat<T, 3>& m, const svec<T>& sv) noexcept; // assert(normalized())

	using svecf = svec<float>;

	// maybe error in editor, but no compile error
	static_assert(sizeof(svecf) == 3 * sizeof(float));
}

#include "detail/svec.inl"
