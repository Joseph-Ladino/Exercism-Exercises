#include "nth_prime.h"

namespace nth_prime {
	
	unsigned int nth(unsigned int n) {
		if (n <= 0) throw std::domain_error("n has to be greater than 0");
		unsigned int last = 2;
		for (unsigned int j = 3, i = 1; i < n; j += 2) {
			bool is_prime = true;
			for (unsigned int k = 2; k < j; k++) {
				if (j % k == 0) is_prime = false;
			}

			if (is_prime) {
				last = j;
				i++;
			}
		}

		return last;
	}

}  // namespace nth_prime
