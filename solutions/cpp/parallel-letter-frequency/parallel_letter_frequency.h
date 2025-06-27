#if !defined(PARALLEL_LETTER_FREQUENCY_H)
#define PARALLEL_LETTER_FREQUENCY_H

#include <unordered_map>
#include <string_view>
#include <vector>
#include <array>

namespace parallel_letter_frequency {

	struct AlphaMap {
		std::array<unsigned, 26> map{};

		bool empty();
		unsigned& operator[](char c);
	};

	//using MapType = std::unordered_map<char, unsigned>;
	using MapType = AlphaMap;

	MapType frequency(std::vector<std::string_view>);
}

#endif

