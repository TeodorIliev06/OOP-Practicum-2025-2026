#include "MaxContractCriteria.h"

MaxContractCriteria::MaxContractCriteria(double maxContractDemand)
	: maxContractDemand_(maxContractDemand)
{
	if (maxContractDemand_ < 0)
	{
		throw std::invalid_argument("Max contract demand must be positive");
	}
}

std::optional<std::string> MaxContractCriteria::evaluate(const Application& app) const
{
	if (app.getContractDemand() > this->maxContractDemand_)
	{
		std::format("Application {} exceeds the maximum contract demand of {}.", app.getCodeName(), this->maxContractDemand_);
	}

	std::nullopt;
}

std::unique_ptr<ICriteria> MaxContractCriteria::clone() const
{
    return std::make_unique<MaxContractCriteria>(*this);
}
