#include "difference_of_squares.h"

namespace difference_of_squares {
	
	int square_of_sum(int n) {
		int total = n * (n + 1) / 2;
		
		return total * total;
	}

	int sum_of_squares(int n) {
		int total = 0;

		for(int i = 1; i <= n; i++) total += i * i;

		return total;
	}

	int difference(int n) {

		return square_of_sum(n) - sum_of_squares(n);
	}

}  // namespace difference_of_squares
