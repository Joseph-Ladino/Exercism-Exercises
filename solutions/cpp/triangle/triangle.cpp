#include "triangle.h"

namespace triangle {

	flavor kind(float s1, float s2, float s3) {
		if ( s1 == 0 || s1 + s2 < s3 || s2 + s3 < s1 || s3 + s1 < s2) throw std::domain_error("That ain't a triangle");
		else if (s1 == s2 && s2 == s3) return flavor::equilateral;
		else if (s1 == s2 || s2 == s3 || s3 == s1) return flavor::isosceles;
		else return flavor::scalene;
	}

}  // namespace triangle
