#include "armstrong_numbers.h"

namespace armstrong_numbers {

	bool is_armstrong_number(unsigned int num) {
		std::string s = std::to_string(num);
		unsigned int total = 0;

		for (auto& c : s)
			total += pow(double(c) - '0', s.size());
		
		return total == num;
	}

}  // namespace armstrong_numbers
