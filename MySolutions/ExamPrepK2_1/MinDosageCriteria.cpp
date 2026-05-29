#include "MinDosageCriteria.h"
#include <format>

MinDosageCriteria::MinDosageCriteria(int minDosage)
    : minDosage_(minDosage)
{
	if (minDosage_ < 0)
	{
		throw std::invalid_argument("Min dosage must be positive");
	}
}

std::optional<std::string> MinDosageCriteria::evaluate(const Application& app) const
{
	if (app.getCompoundVDosage() < this->minDosage_)
	{
		return std::format("Application {} does not meet the minimum dosage requirement of {}.", app.getCodeName(), this->minDosage_);
	}

	return std::nullopt;
}

std::unique_ptr<ICriteria> MinDosageCriteria::clone() const
{
    return std::make_unique<MinDosageCriteria>(*this);
}
