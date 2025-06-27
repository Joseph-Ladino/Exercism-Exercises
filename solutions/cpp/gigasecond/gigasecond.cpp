#include "gigasecond.h"

namespace gigasecond {

	ptime advance(ptime time) {
		int64_t g = 1000000000;
		
		int64_t hours = (g - (g % 3600));
		g -= hours;
		int64_t minutes = (g - (g % 60));
		g -= minutes;
		int64_t seconds = g;

		return time + time_duration(hours / 3600, minutes / 60, seconds);
	}

}  // namespace gigasecond
