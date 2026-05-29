#pragma once

#include "ICriteria.h"

class MinAgeCriteria : public ICriteria {
	int minAge_;

public:
	MinAgeCriteria(int minAge);
	std::optional<std::string> evaluate(const Application& app) const override;
	std::unique_ptr<ICriteria> clone() const override;
};