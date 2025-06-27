#include "power_of_troy.h"

namespace troy {

	void give_new_artifact(human& person, std::string artifact_name) {
		person.possession = std::make_unique<artifact>(artifact_name);
	}

	void exchange_artifacts(std::unique_ptr<artifact>& artifact1, std::unique_ptr<artifact>& artifact2) {
		artifact1.swap(artifact2);
	}

	void manifest_power(human& person, std::string power_effect) {
		person.own_power = std::make_shared<power>(power_effect);
	}

	void use_power(human& caster, human& target) {
		target.influenced_by = caster.own_power;
	}

	int power_intensity(human& person) {
		return person.own_power.use_count();
	}

}  // namespace troy
