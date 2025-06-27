#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <algorithm>
#include <string>
#include <vector>
#include <map>

namespace grade_school {

	struct school {
		private:
			std::map<int, std::vector <std::string>> db;

		public:
			void add(std::string name, int grade);
			std::vector<std::string> grade(int grade) const;
			std::map<int, std::vector<std::string>> roster() const;
	};

}  // namespace grade_school

#endif // GRADE_SCHOOL_H