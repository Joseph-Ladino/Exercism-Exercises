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
			
		for (size_t i = 0; i <= nums.size() - grouping; i++) {
			std::vector<int> temp;
			
			for (size_t j = 0; j < grouping; j++)
				temp.push_back(nums[i + j]);

			out.push_back(temp);
		}


		return out;
	}

}  // namespace series
