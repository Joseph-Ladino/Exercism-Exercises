#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    return scores;
}

int HighScores::latest_score() {
    return scores.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores.begin(), scores.end());
}

std::vector<int> HighScores::top_three() {
    
    std::vector<int> top_scores{ scores.begin(), scores.end() };
    std::sort(top_scores.begin(), top_scores.end(), [](int a, int b) {return a > b; });

    if(top_scores.size() > 3) top_scores.erase(
        top_scores.begin() + 3, top_scores.end()
	);  // Keep only the top 3 scores

    return top_scores;
}

}  // namespace arcade
