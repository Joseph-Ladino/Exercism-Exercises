#include "pangram.h"

namespace pangram {

	bool is_pangram(std::string s) {
		std::string o = "";
		for (auto c : s) {
			c = std::toupper(c);
			if (o.find(c) == std::string::npos && (c >= 65 && c <= 90)) o.push_back(c);
		}
		return o.size() == 26;
	}

}  // namespace pangram
