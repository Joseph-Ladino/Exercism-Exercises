namespace targets {
// TODO: Insert the code for the alien class here
	class Alien {
		int health;
	public:
		int x_coordinate = 0;
		int y_coordinate = 0;

		int get_health() {
			return health;
		}

		bool is_alive() {
			return health > 0;
		}

		bool hit() {
			if (is_alive()) health -= 1;

			return true;
		}

		bool teleport(int x_new, int y_new) {
			x_coordinate = x_new;
			y_coordinate = y_new;

			return true;
		}

		bool collision_detection(Alien& other_alien) {
			return x_coordinate == other_alien.x_coordinate && y_coordinate == other_alien.y_coordinate;
		}

		Alien(int x, int y) : x_coordinate(x), y_coordinate(y) {
			health = 3;
		}
	};
}  // namespace targets