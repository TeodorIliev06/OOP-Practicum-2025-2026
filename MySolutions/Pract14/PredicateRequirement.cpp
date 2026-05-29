#include "PredicateRequirement.h"

std::optional<std::string> PredicateRequirement::check(const Student& student)
{
	if (this->predicate_(student))
	{
		return std::nullopt;
	}

	return this->errorMessage_;
}

std::unique_ptr<IAdmissionRequirement> PredicateRequirement::clone() const
{
    return std::make_unique<PredicateRequirement>(*this);
}
