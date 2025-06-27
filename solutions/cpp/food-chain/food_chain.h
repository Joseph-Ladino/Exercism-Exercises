#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H
#include <stdexcept>
#include <vector>
#include <string>

namespace food_chain {

	static std::pair<std::string, std::string> animals[]{
		{"fly", "I don't know why she swallowed the fly. Perhaps she'll die."},
		{"spider", "It wriggled and jiggled and tickled inside her."},
		{"bird", "How absurd to swallow a bird!"},
		{"cat", "Imagine that, to swallow a cat!"},
		{"dog", "What a hog, to swallow a dog!"},
		{"goat", "Just opened her throat and swallowed a goat!"},
		{"cow", "I don't know how she swallowed a cow!"},
		{"horse", "She's dead, of course!"}
	};

	std::string sing();
	std::string verse(int n);
	std::string verses(int b, int e);

}  // namespace food_chain

#endif // FOOD_CHAIN_H