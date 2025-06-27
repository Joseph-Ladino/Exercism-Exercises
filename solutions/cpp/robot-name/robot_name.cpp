#include "robot_name.h"

namespace robot_name {

	void robot::reset() {
		n = "";
		n += char('A' + std::rand() % 26);
		n += char('A' + std::rand() % 26);
		n += char('0' + std::rand() % 10);
		n += char('0' + std::rand() % 10);
		n += char('0' + std::rand() % 10);
	}

	std::string robot::name() const {
		return n;
	}

	robot::robot() {
		reset();
	}

}  // namespace robot_name
