#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <stdexcept>
#include <string>
#include <map>

namespace nucleotide_count {

	struct counter {

		std::map<char, int> m = { {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };

		std::map<char, int> nucleotide_counts() const;
		int count(char c) const;

		counter(std::string s);
	};

}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H