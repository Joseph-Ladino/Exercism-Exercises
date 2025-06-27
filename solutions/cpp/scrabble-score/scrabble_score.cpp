#include "scrabble_score.h"

namespace scrabble_score {

	int score(std::string word) {
		transform(word.begin(), word.end(), word.begin(), ::toupper);

		int out = 0;
		for (auto& c : word) {
			if (c == 'J' || c == 'X') {
				out += 8;
				continue;
			} else if (c == 'Q' || c == 'Z') {
				out += 10;
				continue;
			}

			for (int i = 0; i < 5; i++)
				if (points[i].find(c) != std::string::npos) out += i + 1;
			
		}

		return out;
	}

}  // namespace scrabble_score
