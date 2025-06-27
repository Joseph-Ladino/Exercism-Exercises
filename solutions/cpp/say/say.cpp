#include "say.h"

#define ADD_INFORMAL_AND false

using namespace std;

string say::two_digits(int num) {
	string out = ((num < 0) ? "negative " : "");
	num = abs(num);

	if (num <= 9) out += single_digits[num];

	else if (num >= 13 && num <= 19 && num != 14) {
		string* to_use = &double_digits[num % 10];
		out += to_use->substr(0, to_use->size() - 2) + "teen";
	}

	else if (num >= 20) {
		int ones_place = num % 10;
		int tens_place = (num - ones_place) / 10;

		out += double_digits[tens_place];
		if (ones_place > 0) out += "-" + single_digits[ones_place];
	}

	// edge cases
	else if (num == 14) out += "fourteen";
	else if (num == 12) out += "twelve";
	else if (num == 11) out += "eleven";
	else if (num == 10) out += "ten";

	return out;
}

string say::three_digits(int num, bool add_and) {
	string out = ((num < 0) ? "negative " : "");
	num = abs(num);

	int ones_tens_place = num % 100;
	int hundreds_place = (num - ones_tens_place) / 100;

	if (ones_tens_place == 0 && hundreds_place == 0) return "";
	if (hundreds_place > 0) out += single_digits[hundreds_place] + " hundred" + ((add_and && ones_tens_place > 0) ? " and " : " ");
	if (ones_tens_place > 0) out += two_digits(ones_tens_place) + " ";

	out.pop_back();

	return out;
}

string say::in_english(unsigned long long num) {

	if (num >= 1000000000000 || num < 0) throw domain_error("number outside range");

	string out;

	int cur;
	for(int x = 0; num != 0; x++) {
		cur = num % 1000;
		string seg = three_digits(cur, x == 0 && ADD_INFORMAL_AND);

		if (seg.size() > 0) {
			if (x > 0) out.insert(0, suffixes[x] + " ");
			out.insert(0, seg + " ");
		}

		num = (num - cur) / 1000;
	}

	if (out.size() == 0) return "zero";
	
	out.pop_back();

	return out;
}
