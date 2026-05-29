#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class TakenCoursesByNameRequirement : public IAdmissionRequirement {
	std::vector<std::string> courseNames_;

public:
	TakenCoursesByNameRequirement(std::vector<std::string> courseNames) : courseNames_(std::move(courseNames))
	{
		if (courseNames_.empty())
		{
			throw std::invalid_argument("Course names cannot be empty");
		}
	}

	std::optional<std::string> check(const Student& student) override;
	std::unique_ptr<IAdmissionRequirement> clone() const override;

};