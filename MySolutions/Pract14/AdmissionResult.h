#pragma once

#include <iostream>
#include "IAdmissionRequirement.h"

class AdmissionResult {
	std::vector<std::string> errors_;
	bool isAdmitted_;

public:
	AdmissionResult(std::vector<std::string> errors, bool isAdmitted) : errors_(std::move(errors)), isAdmitted_(isAdmitted)
	{
	}

	void showResult() const;
};