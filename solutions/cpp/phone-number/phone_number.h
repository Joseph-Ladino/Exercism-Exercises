#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <regex>
#include <string>

using namespace std;

namespace phone_number {
	struct phone_number : string {
		string n;

		bool isValid();

		string format();
		string number();
		string area_code();
		string exchange_code();

		phone_number(string num);
	};
}  // namespace phone_number

#endif // PHONE_NUMBER_H