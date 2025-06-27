#include "binary_search.h"

namespace binary_search {

	size_t find(const std::vector<int>& v, const int& val, int b, int e) {
		int m = (e + b) / 2;
		if (v[m] == val) return m;
		else if (m == b) throw std::domain_error("not in vector");
		else if (v[m] > val) return find(v, val, b, m);
		else return find(v, val, m + 1, e);
	}

	size_t find(const std::vector<int>& v, const int& val) {
		if (v.size() == 0 || val < v.front() || val > v.back()) throw std::domain_error("not gonna work like that buddy");
		else return find(v, val, 0, v.size() - 1);
	}

}  // namespace binary_search
