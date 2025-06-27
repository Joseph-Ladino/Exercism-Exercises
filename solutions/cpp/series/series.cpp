#include "series.h"

namespace series {

	std::vector<int> digits(std::string s) {
		std::vector<int> out;
		
		for (auto c : s)
			if (isdigit(c)) out.push_back(c - '0');
		
		return out;
	}
	
	std::vector<std::vector<int>> slice(std::string s, unsigned int grouping) {
		
		if (s.size() < grouping) throw std::domain_error("grouping's too big!");
		
		std::vector<std::vector<int>> out;
		auto nums = digits(s);
			
		for (int i = 0; i <= nums.size() - grouping; i++)
			out.emplace_back(nums.begin() + i, nums.begin() + i + grouping);

		return out;
	}

}  // namespace series
