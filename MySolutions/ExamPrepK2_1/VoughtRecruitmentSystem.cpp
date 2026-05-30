#include "VoughtRecruitmentSystem.h"

void VoughtRecruitmentSystem::free() {
	this->criterias.clear();
}

void VoughtRecruitmentSystem::copyFrom(const VoughtRecruitmentSystem& other)
{
	for (const auto& criteria : other.criterias) {
		this->criterias.push_back(criteria->clone());
	}
}

VoughtRecruitmentSystem::VoughtRecruitmentSystem(const VoughtRecruitmentSystem& other)
{
	copyFrom(other);
}

VoughtRecruitmentSystem& VoughtRecruitmentSystem::operator=(const VoughtRecruitmentSystem& other)
{
	if (this!= &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}


void VoughtRecruitmentSystem::addCriteria(const ICriteria* criteria)
{
	this->criterias.push_back(criteria->clone());
}

SubmissionResult VoughtRecruitmentSystem::submitApplication(const Application& application)
{
	std::vector<std::string> errors;

	if (this->lookupByEmail(application.getEmail()))
	{
		errors.push_back("An application with the same email already exists.");
	}

	for(const auto& criteria : this->criterias)
	{
		auto result = criteria->evaluate(application);

		if (result.has_value())
		{
			errors.push_back(result.value());
		}
	}

	if (!errors.empty())
	{
		return SubmissionResult(errors);
	}

	this->collection.enlist(application);
	return SubmissionResult(application.getCodeName());
}

std::optional<Application> VoughtRecruitmentSystem::lookupByEmail(const std::string& email)
{
	return this->collection.findByEmail(email);
}

void VoughtRecruitmentSystem::revokeByEmail(const std::string& email)
{
	if (!this->lookupByEmail(email).has_value())
	{
		throw std::runtime_error("Email not found");
	}
	
	this->collection.discharge([&email](const Application& app) {
		return app.getEmail() == email;
	});
}

const RosterCollection& VoughtRecruitmentSystem::getCollection() const
{
	return this->collection;
}
