#include "largest_series_product.h"
#include <stdexcept>

namespace largest_series_product {

	int string_product(std::string_view str, size_t start_index, size_t span) {
		int product = 1;
		for (auto i = start_index; i < (start_index + span); i++) {

			char c = str[i];

			if (c < '0' || c > '9') 
				throw std::domain_error("Non-numeric character encountered.");

			product *= (c - '0');
		}

		return product;
	}

	int largest_product(std::string str, size_t span) {
		int max_product = 0;
		auto str_size = str.size();

		if (span > str_size) 
			throw std::domain_error("Span cannot be larger than string length.");

		if (span < 0)
			throw std::domain_error("Span cannot be negative.");

		if (span == str_size) 
			return string_product(str, 0, str_size);

		for (auto i = 0; i <= str_size - span; i++) {
			int local_product = string_product(str, i, span);

			if (local_product > max_product) max_product = local_product;
		}

		return max_product;
	}

}  // namespace largest_series_product