#include "robot_simulator.h"

namespace robot_simulator {

	Position Robot::get_position() const { return p; }
	Bearing Robot::get_bearing() const { return b; }

	void Robot::execute_sequence(std::string s) {
		for (auto c : s) {
			switch (c) {
				case 'R':
					turn_right();
					break;
				case 'L':
					turn_left();
					break;
				case 'A':
					advance();
					break;
			}
		}
	}

	void Robot::turn_right() { b = static_cast<Bearing>((static_cast<int>(b) + 1) % 4); }
	void Robot::turn_left() { b = static_cast<Bearing>((static_cast<int>(b) + 3) % 4); }
	
	void Robot::advance() {
		switch (static_cast<int>(b)) {
			case 0:
				p.second++;
				break;
			case 1:
				p.first++;
				break;
			case 2:
				p.second--;
				break;
			case 3:
				p.first--;
		}
	}

	Robot::Robot() {
		p = Position(0, 0);
		b = Bearing::NORTH;
	}

	Robot::Robot(Position _p, Bearing _b) {
		p = _p;
		b = _b;
	}

}  // namespace robot_simulator
