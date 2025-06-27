#include "etl.h"

namespace etl {

	std::map<char, int> transform(std::map<int, std::vector<char>> old) {
		std::map<char, int> out;
		for (auto& i : old) 
			for (auto& j : i.second)
				out[tolower(j)] = i.first;

		return out;
	}

}  // namespace etl
