#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H
#include <cctype>
#include <string>

namespace atbash_cipher {
	
	std::string decode(std::string);
	std::string encode(std::string, bool d = false);

}  // namespace atbash_cipher

#endif // ATBASH_CIPHER_H