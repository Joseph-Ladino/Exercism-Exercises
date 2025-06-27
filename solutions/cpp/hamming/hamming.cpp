#include "hamming.h"

namespace hamming {

	int compute(std::string s1, std::string s2) {
		if (s1.size() != s2.size()) throw std::domain_error("strings must be same length!");

		int out = 0;

		for (int i = 0; i < s1.size(); i++)	if(s1.compare(i, 1, s2.substr(i, 1)) != 0) out++;
		
		return out;
	}

}  // namespace hamming
