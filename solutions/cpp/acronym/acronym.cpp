#include "acronym.h"
#include <cstring>

namespace acronym {

	string acronym(string str) {
		
		string acr;
		acr.push_back(str[0]);

		for(size_t i = 1; i < str.size(); i++) {
			if(str[i - 1] == ' ' || str[i - 1] == '-') {
				acr.push_back(toupper(str[i]));
			}
		}

		return acr;
	}

}  // namespace acronym
