#include <iostream>
#include "MinCreditsRequirement.h"

MinCreditsRequirement::MinCreditsRequirement(int minCredits) : minCredits_(minCredits)
{
	if (minCredits_ < 0)
	{
		throw std::invalid_argument("Minimum credits cannot be negative");
	};
}

int MinCreditsRequirement::getMinCredits() const
{
    return this->minCredits_;
}

std::optional<std::string> MinCreditsRequirement::check(const Student& student)
{
	if (this->getMinCredits() < student.getCredits())
	{
		return "Student does not meet the minimum credits requirement";
	}

	return std::nullopt;
}

std::unique_ptr<IAdmissionRequirement> MinCreditsRequirement::clone() const
{
	return std::make_unique<MinCreditsRequirement>(*this);
}
