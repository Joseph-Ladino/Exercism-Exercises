#include "trinary.h"

namespace trinary {

	unsigned int to_decimal(std::string s) {
		s = std::string(s.rbegin(), s.rend());
		unsigned int out = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] < '0' || s[i] > '9') return 0;
			out += (double(s[i]) - double(48)) * pow(3, i);
		}

		return out;
	}

}  // namespace trinary
