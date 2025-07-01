#include "minesweeper.h"

namespace minesweeper {

// TODO: add your solution here

	std::vector<std::string> annotate(std::vector<std::string> board) {

		if (board.empty() || board[0] == "") return board;

		std::size_t y_size = board.size();
		std::size_t x_size = board[0].size();

		for (std::size_t y = 0; y < y_size; y++) {
			for (std::size_t x = 0; x < x_size; x++) {
				char& c = board[y][x];

				if (c != ' ') continue;

				std::size_t x_sweep_min = x > 0 ? x - 1 : 0;
				std::size_t x_sweep_max = x < x_size - 1 ? x + 1 : x_size - 1;

				std::size_t y_sweep_min = y > 0 ? y - 1 : 0;
				std::size_t y_sweep_max = y < y_size - 1 ? y + 1 : y_size - 1;

				int mine_count = 0;

				for (std::size_t y_sweep = y_sweep_min; y_sweep <= y_sweep_max; y_sweep++) {
					for (std::size_t x_sweep = x_sweep_min; x_sweep <= x_sweep_max; x_sweep++) {
						if (board[y_sweep][x_sweep] == '*') 
							mine_count++;
					}
				}

				if(mine_count > 0) 
					c = '0' + mine_count;
			}
		}

		return board;
	}

}  // namespace minesweeper
