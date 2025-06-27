#if !defined(CLOCK_H)
#define CLOCK_H
#include <string>
#include <cmath>

namespace date_independent {

	namespace clock {

		struct at {
			int h, m;

			at plus(int) const;
			operator std::string() const;
			bool operator==(const at&) const;
			bool operator!=(const at&) const;

			at(int, int);
		};
		
	}

}  // namespace date_independent

#endif // CLOCK_H