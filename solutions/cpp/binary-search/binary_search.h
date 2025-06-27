#if !defined(BINARY_SEARCH_H)
#define BINARY_SEARCH_H
#include <stdexcept>
#include <vector>

namespace binary_search {

	size_t find(const std::vector<int>& v, const int& val, int b, int e);
	size_t find(const std::vector<int>& v, const int& val);

}  // namespace binary_search

#endif // BINARY_SEARCH_H