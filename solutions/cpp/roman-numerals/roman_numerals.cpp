#include "roman_numerals.h"

namespace roman_numerals {

	std::string convert(unsigned int num) {
		std::string out;
		unsigned int temp;
		auto temp2 = numerals.rbegin();
		for (auto i = numerals.rbegin(); i != numerals.rend() && num != 0; i++) {
			if (num >= i->first) {
				temp = num / i->first;
				if (temp != 4) {
					for (auto j = 0; j < temp; j++)
						out += i->second;
				} else {
					temp2 = i;
					temp2--;
					out += i->second;
					out += temp2->second;
				}

				num -= temp * i->first;
			} else if (num >= 9) {
				temp2 = i;
				temp2++; temp2++;
				temp = (num / temp2->first) * temp2->first;
				if ((temp == 9 || temp % 2 == 0) && i->first - temp == temp2->first) {
					out += temp2->second;
					out += i->second;
					num -= temp;
				}
			}
		}
		return out;
	}

}  // namespace roman_numerals
