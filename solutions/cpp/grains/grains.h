#if !defined(GRAINS_H)
#define GRAINS_H

namespace grains {

	unsigned long long square(unsigned int num) { return 1ULL << num - 1; }

	unsigned long long total() { return 0xffffffffffffffff; }

}  // namespace grains

#endif // GRAINS_H