#include "sum_of_multiples.h"

int sum_of_multiples::to(std::vector<int> list, int num) {
	if (list.size() == 0) return 0;
    int out = 0, old = 0;
    for (int i = 1; i < num; i++) {
        for (auto& j : list) {
            if (i % j == 0 && i != old) {
                out += i;
                old = i;
            }
        }
    }
	return out;
}