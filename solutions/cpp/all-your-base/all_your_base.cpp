#include "all_your_base.h"

namespace all_your_base {

	unsigned int to_decimal(std::vector<unsigned int> v, unsigned int b) {
		v = std::vector<unsigned int>(v.rbegin(), v.rend());
		unsigned int out = 0;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= b) throw std::invalid_argument("invalid digit");
			out += v[i] * pow(b, i);
		}
		
		return out;
	}

	std::vector<unsigned int> from_decimal(unsigned int n, unsigned int b) {
		std::vector<unsigned int> out;
		unsigned int t;
		while (n != 0) {
			t = n % b;
			out.insert(out.begin(), t);
			n -= t;
			n /= b;
		}
		return out;
	}
	
	std::vector<unsigned int> convert(unsigned int sb, std::vector<unsigned int> v, unsigned int eb) {
		if (sb <= 1 || eb <= 1) throw std::invalid_argument("that's not gonna work buddy");
		else return from_decimal(to_decimal(v, sb), eb);
	}

}  // namespace all_your_base
