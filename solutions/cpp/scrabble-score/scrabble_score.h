#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H
#include <string>
#include <algorithm>

namespace scrabble_score {

	static std::string points[] = {"AEIOULNRST", "DG", "BCMP", "FHVWY", "K"};

	int score(std::string word);

}  // namespace scrabble_score

#endif // SCRABBLE_SCORE_H