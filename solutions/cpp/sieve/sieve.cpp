#include "sieve.h"

namespace sieve {

	std::vector<int> primes(int num) {
		std::vector<int> out;
		std::vector<bool> temp(num + size_t(1));
		std::fill(temp.begin(), temp.end(), true);

		double root = sqrt(num);

		for (size_t i = 2; i < root; i++) 
			if (temp[i]) 
				for (size_t j = i * i; j <= num; j += i) 
					temp[j] = false;

		for (int i = 2; i < temp.size(); i++)
			if (temp[i]) out.push_back(i);
		
		return out;
	}

}  // namespace sieve
