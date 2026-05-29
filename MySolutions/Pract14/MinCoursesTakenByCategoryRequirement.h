#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class MinCoursesTakenByCategoryRequirement : public IAdmissionRequirement {
	Category category_;
	int minCourses_;

public:
	MinCoursesTakenByCategoryRequirement(Category category, int minCourses) : category_(category), minCourses_(minCourses)
	{
		if (minCourses_ < 0)
		{
			throw std::invalid_argument("Minimum courses cannot be negative");
		}
	}

	std::optional<std::string> check(const Student& student) override;

	std::unique_ptr<IAdmissionRequirement> clone() const override;

};