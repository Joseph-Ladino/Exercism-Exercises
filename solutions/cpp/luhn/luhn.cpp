#include "luhn.h"

namespace luhn {

	bool valid(std::string s) {

		s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
		if (s.size() <= 1) return false;

		bool flip = s.size() % 2 == 0;
		unsigned int out = 0, temp = 0;

		for (auto c : s) {
			if (c >= '0' && c <= '9') {
				temp = c - '0';
				if (flip) {
					temp *= 2;
					temp -= (temp > 9) ? 9 : 0;
				}
				out += temp;
				flip = !flip;
			} else return false;
		}

		return out % 10 == 0;
	}

}  // namespace luhn
