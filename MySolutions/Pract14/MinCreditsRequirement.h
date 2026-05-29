#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class MinCreditsRequirement : public IAdmissionRequirement {
	int minCredits_;

public:
	MinCreditsRequirement(int minCredits);

	int getMinCredits() const;

	std::optional<std::string> check(const Student& student) override;
	std::unique_ptr<IAdmissionRequirement> clone() const override;
};