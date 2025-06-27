#pragma once
#include <cmath>
#include <string>
#include <stdexcept>

using namespace std;

namespace say {
	static string single_digits[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	static string double_digits[10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	static string suffixes[4] = { "", "thousand", "million", "billion" };

	string two_digits(int num);
	string three_digits(int num, bool add_and = false);
	string in_english(unsigned long long num);
}  // namespace say
