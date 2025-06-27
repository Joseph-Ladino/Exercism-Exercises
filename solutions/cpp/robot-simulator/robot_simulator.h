#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H
#include <utility>
#include <string>

namespace robot_simulator {
	using Position = std::pair<int, int>;

	enum class Bearing {
		NORTH,
		EAST,
		SOUTH,
		WEST
	}; 

	struct Robot {
		Position p;
		Bearing b;

		Position get_position() const;
		Bearing get_bearing() const;

		void execute_sequence(std::string);
		void turn_right();
		void turn_left();
		void advance();

		Robot();
		Robot(Position, Bearing);
	};

}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H