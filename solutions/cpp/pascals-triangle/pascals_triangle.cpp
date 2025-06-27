#include "pascals_triangle.h"

namespace pascals_triangle {

	std::vector<std::vector<int>> generate_rows(unsigned int num) {
		std::vector<std::vector<int>> out;
		
		if (num >= 1) out.push_back({ 1 });
		
		for (size_t i = 1; i < num; i++) {
			std::vector<int> temp = { 1 };
			for (size_t j = 1; j < i; j++)
				temp.push_back(out[i - 1][j - 1] + out[i - 1][j]);
			
			temp.push_back(1);
			out.push_back(temp);
		}

		return out;
	}

}  // namespace pascals_triangle
