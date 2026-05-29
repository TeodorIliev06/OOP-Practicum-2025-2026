#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class MinAverageGradeRequirement : public IAdmissionRequirement {
	double minAverageGrade_;

public:
	MinAverageGradeRequirement(double minAverageGrade) : minAverageGrade_(minAverageGrade)
	{
		if (minAverageGrade_ < 2.0 || minAverageGrade_ > 6.0)
		{
			throw std::invalid_argument("Minimum average grade must be between 2.0 and 6.0");
		}
	}

	int getMinAverageGrade() const;

	std::optional<std::string> check(const Student& student) override;
	std::unique_ptr<IAdmissionRequirement> clone() const override;
};