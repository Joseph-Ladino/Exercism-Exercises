#include "nucleotide_count.h"

namespace nucleotide_count {
	
	std::map<char, int> counter::nucleotide_counts() const { return m; }
	int counter::count(char c) const {
		if (c == 'A' || c == 'T' || c == 'G' || c == 'C') return m.at(c);
		throw std::invalid_argument("that's not very cash money of you.");
	};

	counter::counter(std::string s) {
		for (auto c : s) {
			if (c == 'A' || c == 'T' || c == 'G' || c == 'C') m[c]++;
			else throw std::invalid_argument("that's not very cash money of you.");
		}
	}

}  // namespace nucleotide_count
