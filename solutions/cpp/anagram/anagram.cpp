#include "anagram.h"


vector<string> anagram::anagram::matches(vector<string> s) {
	vector<string> out;
				
	for(auto& i : s) {
		string otherString;
		map<char, int> otherCharCount;
					
		for(auto c : i) {
			c = tolower(c);
			otherString.push_back(c);
			otherCharCount[c]++;
		}

		if(str != otherString && charCount == otherCharCount) out.push_back(i);
	}

	return out;
}

anagram::anagram::anagram(string s) {
	for(auto& c : s) {
		c = tolower(c);
		str.push_back(c);
		charCount[c]++;
	}
}
