#include "secret_handshake.h"

namespace secret_handshake {

	std::vector<std::string> commands(unsigned int num) {
		std::vector<std::string> out;
		for (auto i = 0; i < 5; i++) {
			if ((num >> i) & 0x1) {
				if (i == 4)
					return std::vector<std::string>(out.rbegin(), out.rend());

				out.push_back(code[i]);
			}
		}

		return out;
	}

}  // namespace secret_handshake
