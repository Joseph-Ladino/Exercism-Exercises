#include "isbn_verifier.h"

namespace isbn_verifier {

	bool is_valid(std::string s) {
		size_t length = s.length();
		
		// immediately return if length isn't correct
		if (length != 10 && length != 13) return false;
		
		char checkDigit = s.at(length - 1);
		int sum = 0;

		// invalid check digit
		if ((checkDigit != 'X' && checkDigit < '0' && checkDigit > '9')) return false;
		
		int j = 10;

		// loop through all characters except for last
		for (size_t i = 0; i < length - 1; i++) {
			char c = s.at(i);

			// skip dashes
			if (c == '-') continue;

			// fail if character isn't a number
			if (c < '0' && c > '9') return false;

			// subtract ascii zero for crude char to int conversion
			sum += (c - '0') * j;

			j--;
		}

		if (checkDigit == 'X') sum += 10;
		else sum += checkDigit - '0';

		return sum % 11 == 0;
	}

}  // namespace isbn_verifier