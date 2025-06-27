#include "word_count.h"

namespace word_count {

	map<string, int> words(string str) {
		map<string, int> out;
        regex filter("\\b[\\w']+\\b");
        smatch res;

        while(regex_search(str, res, filter)) {
            string word = res[0].str();
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            out[word]++;
            str = res.suffix().str();
        }

		return out;
	}

}  // namespace word_count
