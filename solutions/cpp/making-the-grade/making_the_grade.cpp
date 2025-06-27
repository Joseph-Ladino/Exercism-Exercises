#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores(student_scores.size());
    // auto& out_it = rounded_scores.begin();
    // for (auto& in_it = student_scores.begin(); in_it != student_scores.end(); in_it++, out_it++) {
    //     *out_it = static_cast<int>(*in_it);
    // }

    for (auto i = 0; i < student_scores.size(); i++) 
        rounded_scores[i] = static_cast<int>(student_scores[i]);

    return rounded_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failed_students { 0 };

    for (auto i = 0; i < student_scores.size(); i++) 
        failed_students += static_cast<int>(student_scores[i] <= 40);

    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    
    std::array<int, 4> thresholds;

    int thresh_step = (highest_score - 40) / 4;
    for (int i = 0; i < 4; i++)
        thresholds[i] = i * thresh_step + 41;

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> score_pairs;

    for (int i = 0; i < student_names.size(); i++)
        score_pairs.emplace_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    
    return score_pairs;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    
    for (int i = 0; i < student_scores.size(); i++)
        if (student_scores[i] == 100) 
            return student_names[i];

    return "";
}
