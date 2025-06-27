#include "isogram.h"

bool isogram::is_isogram(std::string s) {

	s = std::regex_replace(s, std::regex("[^A-z]"), "");
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (strcmp(s.substr(i, 1).c_str(), s.substr(j, 1).c_str()) == 0 && i != j) return false;
		}
	}

	return true;
}