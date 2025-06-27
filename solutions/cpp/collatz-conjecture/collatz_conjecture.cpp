#include "collatz_conjecture.h"

namespace collatz_conjecture {

	unsigned int steps(int num) {

		if (num < 1) throw std::domain_error("number has to be >= 1");

		unsigned int i = 0;
		for (i; num != 1; i++) {
			if (num % 2) {
				num *= 3;
				num += 1;
			}
			else num /= 2;
		}

		return i;
	}

}  // namespace collatz_conjecture
