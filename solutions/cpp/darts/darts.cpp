#include "darts.h"

namespace darts {
	int score(double x, double y) {
		//  0 points >  10
		//  1 points <= 10
		//  5 points <= 5
		// 10 points <= 1

		double distSq = x * x + y * y;

		if (distSq > 10 * 10) return 0;
		if (distSq > 5 * 5) return 1;
		if (distSq > 1) return 5;
		return 10;
	}
} // namespace darts