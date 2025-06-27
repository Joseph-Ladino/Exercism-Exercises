#include "protein_translation.h"

namespace protein_translation {

	std::vector<std::string> proteins(std::string s) {
		std::vector<std::string> out;

		for (int i = 0; i < s.size(); i += 3) {
			for (auto p : strands) {
				if (std::find(p.second.begin(), p.second.end(), s.substr(i, 3)) != p.second.end()) {
					if (p.first == "ABORT") goto end;
					else out.push_back(p.first);
				}
			}
		}

		end:
		return out;
	}

}  // namespace protein_translation
