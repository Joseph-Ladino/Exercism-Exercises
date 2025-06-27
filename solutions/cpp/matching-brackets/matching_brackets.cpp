#include "matching_brackets.h"

namespace matching_brackets {

	bool is_opening(char c) { return c == '{' || c == '[' || c == '('; }
	bool is_closing(char c) { return c == '}' || c == ']' || c == ')'; }
	bool ops(char o, char c) { return (o == '{' && c == '}') || (o == '[' && c == ']') || (o == '(' && c == ')'); }

	bool check(std::string s) {
		std::stack<char> opening;
		std::queue<char> closing;

		for (size_t i = 0, oc = 0; i < s.size(); i++) {
			oc = s[i];

			while (i + 1 < s.size() && !is_opening(s[i + 1]) && !is_closing(s[i + 1]))
				s.erase(i + 1, 1);

			if (i < s.size() - 1 && ops(oc, s[i + 1])) { i++; continue; }
			else if (is_opening(oc)) opening.push(oc);
			else if (is_closing(oc)) closing.push(oc);

			if (closing.size() > opening.size()) return false;
		}

		if (opening.size() != closing.size()) return false;

		while (!opening.empty()) {

			if (!ops(opening.top(), closing.front())) return false;

			opening.pop(); closing.pop();
		}

		return true;
	}

}  // namespace matching_brackets
