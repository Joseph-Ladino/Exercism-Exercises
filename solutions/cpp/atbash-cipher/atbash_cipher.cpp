#include "atbash_cipher.h"

namespace atbash_cipher {

	std::string decode(std::string s) { return encode(s, true); }
	
	std::string encode(std::string s, bool d) {
		std::string out;
		unsigned int space_count = 0;
		for (auto c : s) {
			bool space = true;
			if (isalpha(c))
				out.push_back(char('a' + ('z' - tolower(c))));
			else if (isdigit(c))
				out.push_back(c);
			else
				space = false;
		
			if (!d && space && (out.size() - space_count) % 5 == 0) {
				out.push_back(' ');
				space_count++;
			}
		}

		if (out.back() == ' ') out.pop_back();

		return out;
	}

}  // namespace atbash_cipher
