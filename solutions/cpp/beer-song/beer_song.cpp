#include "beer_song.h"

namespace beer_song {

	std::string verse(unsigned int num) {
		if (num <= 2) return edges[num];

		std::string out;
		std::string strung = std::to_string(num);
		std::string wall = " bottles of beer on the wall";

		out += strung + wall + ", " + strung + " bottles of beer.\n";
		out += "Take one down and pass it around, " + std::to_string(num - 1) + wall + ".\n";

		return out;
	}

	std::string sing(unsigned int begin, unsigned int end) {
		std::string out;
		for (auto i = begin + 1; i > end; i--)
			out += verse(i - 1) + "\n";
		
		out.pop_back();
		return out;
	}

}  // namespace beer_song
