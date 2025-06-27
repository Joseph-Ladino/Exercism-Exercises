#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H
#include <stdexcept>
#include <vector>
#include <string>

namespace food_chain {

	std::string sing();
	std::string verse(int n);
	std::string verses(int b, int e = 0);

}  // namespace food_chain

#endif // FOOD_CHAIN_H