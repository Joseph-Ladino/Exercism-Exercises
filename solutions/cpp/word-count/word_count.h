#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H
#include <string>
#include <map>
#include <regex>

using namespace std;

namespace word_count {

	map<string, int> words(string str);

}  // namespace word_count

#endif // WORD_COUNT_H