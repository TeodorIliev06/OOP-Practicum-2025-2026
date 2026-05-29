#pragma once

#include "ICriteria.h"

class MaxContractCriteria : public ICriteria {
	double maxContractDemand_;

public:
	explicit MaxContractCriteria(double maxContractDemand);
	std::optional<std::string> evaluate(const Application& app) const override;

	std::unique_ptr<ICriteria> clone() const override;

};