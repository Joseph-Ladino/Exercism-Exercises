#if !defined(ANAGRAM_H)
#define ANAGRAM_H
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace anagram {
	class anagram {
		private:
			string str;
			map<char, int> charCount;
		
		public:
			vector<string> matches(vector<string> s);

		anagram(string s);
	};
}  // namespace anagram

#endif // ANAGRAM_H