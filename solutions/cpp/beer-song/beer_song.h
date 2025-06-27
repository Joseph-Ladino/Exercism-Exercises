#if !defined(BEER_SONG_H)
#define BEER_SONG_H
#include <string>

namespace beer_song {

	static std::string edges[3] = { 
		"No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n", 
		"1 bottle of beer on the wall, 1 bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n", 
		"2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n" 
	};

	std::string verse(unsigned int num);

	std::string sing(unsigned int begin, unsigned int end = 0);

}  // namespace beer_song

#endif // BEER_SONG_H