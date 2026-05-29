#pragma once
#include <optional>
#include <iostream>
#include "Student.h"

struct IAdmissionRequirement {
	virtual std::optional<std::string> check(const Student& student) = 0;
	virtual std::unique_ptr<IAdmissionRequirement> clone() const = 0;
};