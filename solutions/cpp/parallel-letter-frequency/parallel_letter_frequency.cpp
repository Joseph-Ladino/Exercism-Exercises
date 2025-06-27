#include "parallel_letter_frequency.h"

#include <algorithm>
#include <execution>
#include <mutex>
#include <locale>

namespace parallel_letter_frequency {


	MapType frequency(std::vector<std::string_view> texts) {

		MapType out;
        std::mutex mut;

        char capDif = 'a' - 'A';

        std::for_each(
            std::execution::par,
            texts.begin(),
            texts.end(),
            [&](std::string_view text)
            {
                MapType temp;

                for (auto& c : text) {
                    if (!isalpha(c)) continue;
                    
                    if (c >= 'a') temp[c]++;
                    else temp[c + capDif]++; // convert to lower case
                }
                
                for (const auto& i : temp) {
                    const std::lock_guard<std::mutex> lock(mut);
                    out[i.first] += i.second;
                }
            });

		return out;
	}
}
