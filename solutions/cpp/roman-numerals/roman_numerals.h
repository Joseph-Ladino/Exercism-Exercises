#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H
#include <string>
#include <map>

namespace roman_numerals {

	static std::map<unsigned int, const char*> numerals{
		{1000, "M"},
		{900, "CM"},
		{500, "D"},
		{100, "C"},
		{90, "XC"},
		{50, "L"},
		{10, "X"},
		{9, "IX"},
		{5, "V"},
		{1, "I"}
	};

	std::string convert(unsigned int);

}  // namespace roman_numerals

#endif // ROMAN_NUMERALS_H