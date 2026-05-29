#pragma once
#include "ICriteria.h"

class MinDosageCriteria : public ICriteria {
	int minDosage_;

public:
	MinDosageCriteria(int minDosage);

	std::optional<std::string> evaluate(const Application& app) const override;
	std::unique_ptr<ICriteria> clone() const override;
};