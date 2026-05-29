#include "MinAgeCriteria.h"
#include <format>
MinAgeCriteria::MinAgeCriteria(int minAge)
    : minAge_(minAge)
{
    if (minAge_ < 0)
    {
        throw std::invalid_argument("Min age must be positive");
    }
}

std::optional<std::string> MinAgeCriteria::evaluate(const Application& app) const
{
    if (app.getAge() < this->minAge_)
    {
		std::format("Application {} does not meet the minimum age requirement of {}.", app.getCodeName(), this->minAge_);
    }

    std::nullopt;
}

std::unique_ptr<ICriteria> MinAgeCriteria::clone() const
{
    return std::make_unique<MinAgeCriteria>(*this);
}
