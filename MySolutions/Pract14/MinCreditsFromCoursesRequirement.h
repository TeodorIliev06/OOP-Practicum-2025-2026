#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class MinCreditsFromCoursesRequirement : public IAdmissionRequirement {
	int minCreditsFromCourses_;

public:
	MinCreditsFromCoursesRequirement(int minCreditsFromCourses) : minCreditsFromCourses_(minCreditsFromCourses)
	{
		if (minCreditsFromCourses_ < 0)
		{
			throw std::invalid_argument("Minimum credits from courses cannot be negative");
		}
	}

	int getMinCreditsFromCourses() const;

	std::optional<std::string> check(const Student& student) override;
	std::unique_ptr<IAdmissionRequirement> clone() const override;
};