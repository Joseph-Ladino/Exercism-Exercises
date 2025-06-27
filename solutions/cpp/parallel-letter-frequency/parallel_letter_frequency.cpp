#include "parallel_letter_frequency.h"

#include <algorithm>
#include <execution>
#include <mutex>
#include <locale>

namespace parallel_letter_frequency {
    constexpr bool basicIsAlpha(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    bool AlphaMap::empty() {
        for (auto num : map) {
            if (num != 0) return false;
        }

        return true;
    }

    unsigned& AlphaMap::operator[](char c) {
        static unsigned UNSET = 0;

        if (!basicIsAlpha(c)) return UNSET;
        
        if (c >= 'a') return map[c - 'a'];
        else return map[c - 'A'];
    }

	MapType frequency(std::vector<std::string_view> texts) {

        auto policy = std::execution::par;

		MapType out;
        std::mutex mut;

        std::for_each(
            policy,
            texts.begin(),
            texts.end(),
            [&](std::string_view text)
            {
                MapType temp;

                for (auto& c : text) {
                    if (!basicIsAlpha(c)) continue;
                    
                    temp[c]++;
                }

                for (char i = 0; i < 26; i++) {
                    out.map[i] += temp.map[i];
                }
            });

		return out;
	}
}
