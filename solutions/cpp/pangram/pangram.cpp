#include "pangram.h"

namespace pangram {

	bool is_pangram(std::string s) {
		std::string o = "";
		for (auto c : s) {
			c = std::toupper(c);
			if (std::isalpha(c) && o.find(c) == std::string::npos) o.push_back(c);
		}
		return o.size() == 26;
	}

}  // namespace pangram
