#if !defined(TRIANGLE_H)
#define TRIANGLE_H
#include <stdexcept>

namespace triangle {

	enum class flavor {
		equilateral,
		degenerate,
		isosceles,
		scalene
	};

	flavor kind(float s1, float s2, float s3);

}  // namespace triangle

#endif // TRIANGLE_H