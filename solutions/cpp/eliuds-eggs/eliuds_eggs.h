#pragma once
#include <type_traits>

namespace chicken_coop {

	template <class num_type>
	inline num_type positions_to_quantity(num_type egg_positions) {
		static_assert(std::is_integral_v<num_type> == true);

		num_type egg_count;

		// std::size_t num_bits = sizeof(egg_positions) * 8;
		// for (std::size_t i = 0; i < num_bits; i++) {
		// 	egg_count += (egg_positions >> i) & 1;
		// }

        for(egg_count = 0; egg_positions != 0; egg_positions >>= 1)
            egg_count += egg_positions & 1;
            
        
		return egg_count;
	}

}  // namespace chicken_coop
