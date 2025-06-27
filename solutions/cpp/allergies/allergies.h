#if !defined(ALLERGIES_H)
#define ALLERGIES_H
#include <string>
#include <unordered_set>

namespace allergies {

	struct allergy_test {
		
		unsigned int n = 0;
		const std::string possible[8] = { "eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats" };
		std::unordered_set<std::string> allergies;

		std::unordered_set<std::string> get_allergies() const;
		bool is_allergic_to(std::string);
		
		allergy_test(unsigned int);
	};

}  // namespace allergies

#endif // ALLERGIES_H