#include "prime_factors.h"

namespace prime_factors {

	std::vector<int> of(int num) {
		std::vector<int> out;
		for (int i = 2; num > 1;) {
			if (num % i == 0) {
				out.push_back(i);
				num /= i;
			} else i++;
		}
		return out;
	}

}  // namespace prime_factors
