#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H
#include <string>
#include <map>

namespace roman_numerals {

	static std::map<unsigned int, char> numerals {
		{1000, 'M'},
		{500, 'D'},
		{100, 'C'},
		{50, 'L'},
		{10, 'X'},
		{5, 'V'},
		{1, 'I'}
	};

	std::string convert(unsigned int);

}  // namespace roman_numerals

#endif // ROMAN_NUMERALS_H