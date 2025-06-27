#include "collatz_conjecture.h"

namespace collatz_conjecture {

	unsigned int steps(int num) {

		if (num < 1) throw std::domain_error("num has to be >= 1");

		unsigned int i;
		for (i = 0; num != 1; i++) 
			num = (num % 2) ? num * 3 + 1 : num / 2;

		return i;
	}

}  // namespace collatz_conjecture
