#include "hexadecimal.h"

namespace hexadecimal {

	unsigned int convert(std::string s) {
		unsigned int out = 0;
		
		for (auto i = s.rbegin(); i != s.rend(); i++) {
			if (*i >= 'a' && *i <= 'f')
				out += (size_t(10) + *i - size_t('a')) * std::pow(16, i - s.rbegin());
			else if (std::isdigit(*i))
				out += (*i - size_t('0')) * std::pow(16, i - s.rbegin());
			else
				return 0;
		}

		return out;
	}

}  // namespace hexadecimal
