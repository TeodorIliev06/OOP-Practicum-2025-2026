#include "RosterCollection.h"

std::optional<Application> RosterCollection::findByEmail(const std::string& email) const
{
    return this->locateFirst([&email](const Application& app) {
        return app.getEmail() == email;
	});
}

std::vector<Application> RosterCollection::filterByPower(const std::string& power) const
{
	return this->where([&power](const Application& app) {
		const auto& powers = app.getPowers();
		return std::find(powers.begin(), powers.end(), power) != powers.end();
	});
}

double RosterCollection::averageContractDemand() const
{
	if (this->isEmpty())
	{
		return 0;
	}

	int total = 0;

	for (const auto& item : this->items_) {
		total += item.getContractDemand();
	}

	return total / this->count();
}
