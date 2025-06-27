#include "grade_school.h"

namespace grade_school {
	
	void school::add(std::string name, int grade) {
		if (db.find(grade) != db.end()) {
			auto& v = db.at(grade);
			v.push_back(name);
			std::sort(v.begin(), v.end());
		} else {
			db.insert(std::pair<const int, std::vector<std::string>>(grade, { name }));
		}
	}

	std::vector<std::string> school::grade(int grade) const {
		if (db.find(grade) != db.end()) return db.at(grade);
		else return std::vector<std::string>();
	}

	std::map<int, std::vector<std::string>> school::roster() const {
		return db;
	}

}  // namespace grade_school
