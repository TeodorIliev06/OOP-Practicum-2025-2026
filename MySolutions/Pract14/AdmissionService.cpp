#include "AdmissionService.h"

void AdmissionService::addRequirement(const IAdmissionRequirement& requirement)
{
	this->requirements_.push_back(requirement.clone());
}

std::vector<std::string> AdmissionService::checkAdmission(const Student& student) const
{
	std::vector<std::string> errors;

	for (const auto& requirement : this->requirements_) {
		if (requirement->check(student).has_value())
		{
			errors.push_back(requirement->check(student).value());
		}
	}

	return errors;
}
