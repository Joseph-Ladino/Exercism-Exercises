#include "bob.h"

namespace bob {
	
	std::string hey(std::string msg) {
		
		// leave only letters, numbers, and question marks
		msg = std::regex_replace(msg, std::regex("[^A-z0-9?]"), "");
		
		if (msg.size() == 0) return "Fine. Be that way!";

		// true only if the string has letters and they are lowercase
		bool yelling = !(std::regex_search(msg, std::regex("[a-z]"))) && (std::regex_search(msg, std::regex("[A-z]")));
		
		if (msg.back() == '?')
			return ((yelling) ? "Calm down, I know what I'm doing!" : "Sure.");

		return ((yelling) ? "Whoa, chill out!" : "Whatever.");
	}

}  // namespace bob
