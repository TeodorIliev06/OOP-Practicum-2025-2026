#pragma once

#include <iostream>
#include <functional>
#include "IAdmissionRequirement.h"

class PredicateRequirement : public IAdmissionRequirement {
	std::function<bool(const Student&)> predicate_;
	std::string errorMessage_;

public:
	std::optional<std::string> check(const Student& student) override;
	std::unique_ptr<IAdmissionRequirement> clone() const override;
};