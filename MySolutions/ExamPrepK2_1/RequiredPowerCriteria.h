#pragma once
#include "ICriteria.h"

class RequiredPowerCriteria : public ICriteria {
	std::string requiredPower_;

public:
	explicit RequiredPowerCriteria(std::string requiredPower);

	std::optional<std::string> evaluate(const Application& application) const override;
	std::unique_ptr<ICriteria> clone() const override;
};