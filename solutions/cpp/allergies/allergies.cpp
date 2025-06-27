#include "allergies.h"

namespace allergies {

	std::unordered_set<std::string> allergy_test::get_allergies() const { return allergies; }

	bool allergy_test::is_allergic_to(std::string s) { return allergies.find(s) != allergies.end(); }

	allergy_test::allergy_test(unsigned int _n) : n(_n) {

		for (int i = 0; i < 8; i++)
			if ((n >> i) & 0x1) allergies.insert(possible[i]);
	
	}

}  // namespace allergies
