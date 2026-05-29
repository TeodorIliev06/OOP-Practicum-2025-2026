#pragma once
#include <vector>
#include <optional>
#include "Application.h"
#include "Collection.hpp"

class RosterCollection : public Collection<Application> {
public:
	std::optional<Application> findByEmail(const std::string& email) const;
	std::vector<Application> filterByPower(const std::string& power) const;
	double averageContractDemand() const;
};