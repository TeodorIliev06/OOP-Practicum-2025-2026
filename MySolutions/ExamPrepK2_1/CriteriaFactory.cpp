#include "CriteriaFactory.h"
#include "MinDosageCriteria.h"
#include <string>
#include "RequiredPowerCriteria.h"
#include "MinAgeCriteria.h"
#include "MaxContractCriteria.h"
std::unique_ptr<ICriteria> CriteriaFactory::create(const std::string& criteriaType, const std::string& parameter)
{
	if (criteriaType == "min_dosage") return std::make_unique<MinDosageCriteria>(std::stoi(parameter));
	if (criteriaType == "required_power") return std::make_unique<RequiredPowerCriteria>(std::stoi(parameter));
	if (criteriaType == "min_age") return std::make_unique<MinAgeCriteria>(std::stoi(parameter));
	if (criteriaType == "max_contract") return std::make_unique<MaxContractCriteria>(std::stod(parameter));

	throw std::runtime_error("The criteriaType " + criteriaType + " is invalid.");
}
