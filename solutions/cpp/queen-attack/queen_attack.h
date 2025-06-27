#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H
#include <stdexcept>
#include <string>

namespace queen_attack {

	struct chess_board {
		std::pair<int, int> w, b;
		std::pair<int, int> white() const;
		std::pair<int, int> black() const;

		bool can_attack() const;
		operator std::string() const;

		chess_board(std::pair<int, int>, std::pair<int, int>);
		chess_board();
	};

}  // namespace queen_attack

#endif // QUEEN_ATTACK_H