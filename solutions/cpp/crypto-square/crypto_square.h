#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H
#include <string>
#include <vector>
#include <regex>

namespace crypto_square {

	struct cipher {
		size_t cols = 0, rows = 0, size = 0;
		std::string plain, formatted;

		std::vector<std::string> plain_text_segments();
		std::string normalize_plain_text();
		std::string cipher_text();
		std::string normalized_cipher_text();

		cipher(std::string s);
	};

}  // namespace crypto_square

#endif // CRYPTO_SQUARE_H