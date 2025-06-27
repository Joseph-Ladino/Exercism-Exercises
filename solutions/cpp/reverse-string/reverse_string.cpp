#include "reverse_string.h"

namespace reverse_string {

	string reverse_string(string str) {
		string out;

		for(auto& i : str) out.insert(0, 1, i);
		
		return out;
	}

}  // namespace reverse_string
