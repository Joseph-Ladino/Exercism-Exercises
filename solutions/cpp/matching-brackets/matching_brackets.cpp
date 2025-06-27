#include "matching_brackets.h"

namespace matching_brackets {

	bool is_opening(char c) { return c == '{' || c == '[' || c == '('; }
	bool is_closing(char c) { return c == '}' || c == ']' || c == ')'; }
	bool ops(char o, char c) { return (o == '{' && c == '}') || (o == '[' && c == ']') || (o == '(' && c == ')'); }

	bool check(std::string s) {
		std::stack<char> openings;

		for (auto c : s) {
			if (is_opening(c)) openings.push(c);
			else if (is_closing(c)) {
				if (openings.empty() || !ops(openings.top(), c)) return false;
				else openings.pop();
			}
		}

		return openings.empty();
	}

}  // namespace matching_brackets
