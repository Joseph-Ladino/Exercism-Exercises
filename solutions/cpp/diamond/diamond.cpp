#include "diamond.h"
#include <stdexcept>

namespace diamond {

	std::vector<std::string> rows(char c) {
		std::vector<std::string> diamond;

		if(c < 'A' || c > 'Z') {
			throw std::domain_error("Input must be an uppercase letter A-Z");
		}

		// number of characters in each row (also number of rows)
		int center = c - 'A';
		int row_width = 2 * center + 1;

		diamond.resize(row_width);

		for(int i = 0; i <= center; i++) {
			std::string row(row_width, ' ');

			char letter = 'A' + i;

			row[center - i] = letter;
			row[center + i] = letter;

			// duplicate the row for the bottom half of the diamond
			diamond[i] = row;
			diamond[row_width - i - 1] = row;
		}

		return diamond;
	}

}  // namespace diamond
