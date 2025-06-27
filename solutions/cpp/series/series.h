#if !defined(SERIES_H)
#define SERIES_H
#include <string>
#include <vector>
#include <stdexcept>

namespace series {

	std::vector<int> digits(std::string);
	std::vector<std::vector<int>> slice(std::string, unsigned int);

}  // namespace series

#endif // SERIES_H