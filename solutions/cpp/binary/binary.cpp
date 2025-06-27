#include "binary.h"

namespace binary {

	unsigned int convert(std::string s) {
		s = std::string(s.rbegin(), s.rend());
		unsigned int out = 0;

		for (unsigned int i = 0; i < s.size(); i++) {
			if (s[i] < '0' || s[i] > '9') return 0;
			out += (s[i] - '0') << i;
		}

		return out;
	}

}  // namespace binary
