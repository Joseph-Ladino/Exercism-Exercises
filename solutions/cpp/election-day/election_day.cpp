#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.

int vote_count(ElectionResult& election_result) {
    return election_result.votes;
}

// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.

void increment_vote_count(ElectionResult& election_result, int vote_increment) {
    election_result.votes += vote_increment;
}

// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

ElectionResult& determine_result(std::vector<ElectionResult>& final_count) {
    ElectionResult* president = &final_count.front();

    for (auto& election_result : final_count) {
        if (election_result.votes > president->votes) president = &election_result;
    }

    president->name.insert(0, "President ");

    return *president;
}

}  // namespace election