#if !defined(ALL_YOUR_BASE_H)
#define ALL_YOUR_BASE_H
#include <vector>
#include <stdexcept>

namespace all_your_base {

	unsigned int to_decimal(std::vector<unsigned int> v, unsigned int b);
	std::vector<unsigned int> from_decimal(unsigned int n, unsigned int b);
	std::vector<unsigned int> convert(unsigned int sb, std::vector<unsigned int> v, unsigned int eb);

}  // namespace all_your_base

#endif // ALL_YOUR_BASE_H