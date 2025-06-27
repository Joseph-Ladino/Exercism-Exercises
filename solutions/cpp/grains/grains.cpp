#include "grains.h"

namespace grains {

	unsigned long long square(unsigned int num) { return 1ULL << num - 1; }

	unsigned long long total(unsigned int num) { return 0xffffffffffffffff >> 64 - num; }

}  // namespace grains
