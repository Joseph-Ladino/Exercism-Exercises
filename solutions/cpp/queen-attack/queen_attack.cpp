#include "queen_attack.h"

namespace queen_attack {

	std::pair<int, int> chess_board::white() const { return w; }

	std::pair<int, int> chess_board::black() const { return b; }

	bool chess_board::can_attack() const { return w.first == b.first || w.second == b.second || abs(w.second - b.second) == abs(w.first - b.first); }

	chess_board::operator std::string() const {
		std::string out = "_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n_ _ _ _ _ _ _ _\n";
		out[w.first * size_t(16) + w.second * size_t(2)] = 'W';
		out[b.first * size_t(16) + b.second * size_t(2)] = 'B';
		return out;
	}

	chess_board::chess_board(std::pair<int, int> _w, std::pair<int, int> _b) {
		if (_w == _b) throw std::domain_error("Positions can't be the same");
		
		w = _w;
		b = _b;
	}

	chess_board::chess_board() {
		w = std::pair<int, int>(0, 3);
		b = std::pair<int, int>(7, 3);
	}

}  // namespace queen_attack
