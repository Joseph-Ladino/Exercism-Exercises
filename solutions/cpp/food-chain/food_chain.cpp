#include "food_chain.h"

namespace food_chain {

	std::vector<std::pair<std::string, std::string>> animals = {
		{"fly", "I don't know why she swallowed the fly. Perhaps she'll die."},
		{"spider", "It wriggled and jiggled and tickled inside her."},
		{"bird", "How absurd to swallow a bird!"},
		{"cat", "Imagine that, to swallow a cat!"},
		{"dog", "What a hog, to swallow a dog!"},
		{"goat", "Just opened her throat and swallowed a goat!"},
		{"cow", "I don't know how she swallowed a cow!"},
		{"horse", "She's dead, of course!"}
	};

	std::string sing() { return verses(1, 8); }

	std::string verse(int n) { 
		auto t = verses(n, 0); 
		if(n != 8) t.pop_back();
		return t;
	}

	std::string verses(int b, int e) {
		if (b < 1 || e > 8) throw std::domain_error("out of range");

		e = (e == 0) ? b : e;

		std::string out;

		for (int i = b - 1; i < e; i++) {
			out += "I know an old lady who swallowed a " + animals[i].first + ".\n";
			out += (i != 0) ? animals[i].second + "\n" : "";
			if (i == 7) break;
			for (size_t j = i; j > 0; j--) {
				out += "She swallowed the " + animals[j].first + " to catch the " + animals[j - 1].first;
				out += (j != 2) ? ".\n" : " that" + animals[j - 1].second.substr(2) + "\n";
			}
			out += animals[0].second + "\n\n";
		}

		return out;
	}
}  // namespace food_chain
