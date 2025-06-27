#include "phone_number.h"

bool phone_number::phone_number::isValid() {
	if (n.size() < 10 || n.size() > 11) return false;
	
	if (n.size() == 11) {
		if (n.compare(0, 1, "1") != 0) return false;
		n = n.substr(1);
	}

	if (stoi(area_code()) < 200 || stoi(exchange_code()) < 2000) return false;

	return true;
}

string phone_number::phone_number::format() {
	return '(' + area_code() + ") " + n.substr(3, 3) + '-' + n.substr(6, 4);
}

string phone_number::phone_number::number() {
	return n;
}

string phone_number::phone_number::area_code() {
	return n.substr(0, 3);
}

string phone_number::phone_number::exchange_code() {
	return n.substr(3, 4);
}

phone_number::phone_number::phone_number(string num) {
	n = regex_replace(num, regex("[^0-9]"), "");

	if (!isValid()) throw domain_error("tsk tsk");

	append(format());
}