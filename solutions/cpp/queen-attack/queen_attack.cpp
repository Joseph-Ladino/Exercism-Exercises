#include "queen_attack.h"

namespace queen_attack {

	std::pair<int, int> chess_board::white() const { return w; }

	std::pair<int, int> chess_board::black() const { return b; }

	bool chess_board::can_attack() const { return w.first == b.first || w.second == b.second || abs(w.second - b.second) == abs(w.first - b.first); }

	chess_board::chess_board(std::pair<int, int> _w, std::pair<int, int> _b) {
		if (_w == _b) throw std::domain_error("Positions can't be the same");
		
		w = _w;
		b = _b;

		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (y == w.first && x == w.second) append("W");
				else if (y == b.first && x == b.second) append("B");
				else append("_");

				if (x != 7) append(" ");
				else append("\n");
			}
		}
	}

	chess_board::chess_board() {
		w = std::pair<int, int>(0, 3);
		b = std::pair<int, int>(7, 3);
	}

}  // namespace queen_attack
