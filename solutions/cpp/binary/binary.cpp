#include "binary.h"

namespace binary {

	unsigned int convert(std::string s) {
		s = std::string(s.rbegin(), s.rend());
		unsigned int out = 0;

		for (double i = 0; i < s.size(); i++) {
			if (s[i] < '0' || s[i] > '9') return 0;
			out += (double(s[i]) - double(48)) * pow(2, i);
		}

		return out;
	}

}  // namespace binary
