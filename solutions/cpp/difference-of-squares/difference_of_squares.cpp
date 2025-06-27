#include "difference_of_squares.h"

namespace difference_of_squares {
	
	int square_of_sum(int n) {
		int total = 0;

		for(int i = 1; i <= n; i++) total += i;
		
		return total * total;
	}

	int sum_of_squares(int n) {
		int total = 0;

		for(int i = 1; i <= n; i++) total += i * i;

		return total;
	}

	int difference(int n) {

		int sum_total = 0;
		int square_total = 0;

		for(int i = 1; i <= n; i++) {
			sum_total += i;
			square_total += i * i;
		}

		return (sum_total * sum_total) - square_total;

		// return square_of_sum(n) - sum_of_squares(n)
	}

}  // namespace difference_of_squares
