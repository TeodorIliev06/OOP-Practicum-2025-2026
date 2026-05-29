#pragma once

#include <iostream>
#include <vector>
#include "IAdmissionRequirement.h";

class AdmissionService {
	std::vector<std::unique_ptr<IAdmissionRequirement>> requirements_;

public:
	AdmissionService() = default;
	void addRequirement(const IAdmissionRequirement& requirement);
	std::vector<std::string> checkAdmission(const Student& student) const;

	void copyFrom();
};