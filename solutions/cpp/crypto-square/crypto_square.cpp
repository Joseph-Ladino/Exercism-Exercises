#include "crypto_square.h"

namespace crypto_square {
	
	std::vector<std::string> cipher::plain_text_segments() {
		std::vector<std::string> out;

		if (size == 0) return out;

		for (auto i = 0; i < size; i += cols)
			out.push_back(formatted.substr(i, cols));

		auto& t = out[rows - 1];
		t.erase(std::remove(t.begin(), t.end(), ' '), t.end());
		return out;
	}

	std::string cipher::normalize_plain_text() {
		return plain;
	}

	std::string cipher::cipher_text() {
		auto t = normalized_cipher_text();
		t.erase(std::remove(t.begin(), t.end(), ' '), t.end());
		return t;
	}

	std::string cipher::normalized_cipher_text() {
		std::string out;
		for (auto x = 0; x < cols; x++) {
			for (auto y = 0; y < rows; y++)
				out.push_back(formatted[y * cols + x]);
			out.push_back(' ');
		}

		if (out.size() != 0) out.pop_back();

		return out;
	}

	cipher::cipher(std::string s) {
		
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		plain = std::regex_replace(s, std::regex("[^a-z0-9]"), "");
		size = plain.size();

		if (size == 0) {
			formatted = "";
			return;
		}

		for (size_t i = 1; i <= size; i++) {
			if (i * (i - 1) >= size) {
				cols = i;
				rows = i - 1;
				break;
			} else if (i * i >= size) {
				cols = i;
				rows = i;
				break;
			}
		}

		formatted = plain;
		size = rows * cols;

		for (auto i = size - formatted.size(); i > 0; i--) formatted.push_back(' ');
	}

}  // namespace crypto_square
