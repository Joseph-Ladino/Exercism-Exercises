#include "run_length_encoding.h"

namespace run_length_encoding {
	static constexpr bool isNum(char c) {
		return c >= '0' && c <= '9';
	}

	string encode(string raw) {

		if (raw.size() == 0) return "";

		char lastChar = raw[0];
		int countSameChar = 0;

		string out;

		for (auto c : raw) {

			if (c == lastChar) {
				countSameChar++;
				continue;
			}
			
			if (countSameChar > 1)
				out += std::to_string(countSameChar) + lastChar;
			else
				out += lastChar;

			lastChar = c;
			countSameChar = 1;
		}

		if (countSameChar > 1)
			out += std::to_string(countSameChar) + lastChar;
		else
			out += lastChar;

		return out;
	}

	string decode(string encoded) {
		string out;

		auto count = 1;
		size_t i = 0;

		while (i < encoded.size()) {
			auto c = encoded.at(i);
			if (!isNum(c)) {
				out += string(count, c);
				count = 1;
				i++;
				continue;
			}

			// atoi runs until nonnumeric char is reached
			count = std::atoi(encoded.c_str() + i);
			
			// skip until next nonnumeric char
			while (isNum(encoded.at(i))) {
				i++;
			}
		}

		return out;
	}
}  // namespace run_length_encoding
