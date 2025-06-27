#pragma once

#include <vector>
#include <string>
#include <stdexcept>

namespace resistor_color {

	
inline std::vector<std::string> colors() {
	return std::vector<std::string> {
		"black",   // 0
		"brown",   // 1
		"red",     // 2
		"orange",  // 3
		"yellow",  // 4
		"green",   // 5
		"blue",    // 6
		"violet",  // 7
		"grey",    // 8
		"white"    // 9
	};
}

inline int color_code(std::string color) {
	
	auto color_codes = colors();
	
	for (std::size_t i = 0; i < color_codes.size(); i++) {
		if (color_codes[i] == color) {
			return static_cast<int>(i);
		}
	}

	throw std::invalid_argument("Invalid color: " + color);
}

}  // namespace resistor_color
