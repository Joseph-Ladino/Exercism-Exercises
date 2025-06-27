#include "clock.h"

namespace date_independent {

	namespace clock {

		at at::plus(int b) const { return at(h, m + b); }
		
		at::operator std::string() const {
			std::string out;
			
			if (h < 10) out.push_back('0');
			out += std::to_string(h) + ":";
			if (m < 10) out.push_back('0');
			out += std::to_string(m);

			return out;
		}

		bool at::operator==(const at& b) const { return h == b.h && b.m == m; }
		bool at::operator!=(const at& b) const { return h != b.h || b.m != m; }

		at::at(int _h, int _m) {
			m = (60 + (_m % 60)) % 60;

			if (_m < 0) _h -= std::ceil(-_m / 60.0f);
			else _h += _m / 60;

			h = (24 + (_h % 24)) % 24;
		}

	}

}  // namespace date_independent
