#include "perfect_numbers.h"
#include <stdexcept>

#include <cmath>

namespace perfect_numbers {

	classification classify(int num) {
		if (num < 1)
			throw std::domain_error("Only positive numbers are allowed.");

		// edge cases
		if (num == 1 || num == 4)
			return classification::deficient;

		int factor_bound = static_cast<int>(std::sqrt(num));
		int aliquot_sum = 1;

		// calculate factors as pairs e.g. 6 = 2 * 3
		for (int i = 2; i <= factor_bound; i++) {
			if (num % i == 0) 
				aliquot_sum += i + num / i;
		}

		if (aliquot_sum < num) 
			return classification::deficient;

		if (aliquot_sum > num) 
			return classification::abundant;

		return classification::perfect;
	}

}  // namespace perfect_numbers
