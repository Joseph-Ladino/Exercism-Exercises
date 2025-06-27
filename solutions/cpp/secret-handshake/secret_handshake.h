#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H
#include <vector>
#include <string>

namespace secret_handshake {

	static std::vector<std::string> code = {"wink", "double blink", "close your eyes", "jump"};
	std::vector<std::string> commands(unsigned int);

}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
