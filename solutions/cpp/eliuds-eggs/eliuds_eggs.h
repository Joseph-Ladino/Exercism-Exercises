#pragma once

namespace chicken_coop {

	template <class num_type>
	inline num_type positions_to_quantity(num_type egg_positions) {
		static_assert(std::is_integral_v<num_type> == true);

		num_type egg_count = 0;

		auto num_bits = sizeof(egg_positions) * 8;
		for (auto i = 0; i < num_bits; i++) {
			egg_count += (egg_positions >> i) & 1;
		}

		return egg_count;
	}

}  // namespace chicken_coop
