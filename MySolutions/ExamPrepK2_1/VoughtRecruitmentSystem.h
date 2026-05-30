#pragma once
#include <vector>
#include "Application.h"
#include "ICriteria.h"
#include "RosterCollection.h"
#include "SubmissionResult.h"

class VoughtRecruitmentSystem {
	std::vector<std::unique_ptr<ICriteria>> criterias;
	RosterCollection collection;

	void free();
	void copyFrom(const VoughtRecruitmentSystem& system);
public:
	VoughtRecruitmentSystem() = default;

	VoughtRecruitmentSystem(const VoughtRecruitmentSystem& other);
	VoughtRecruitmentSystem& operator=(const VoughtRecruitmentSystem& other);

	VoughtRecruitmentSystem(VoughtRecruitmentSystem&& other) noexcept = default;
	VoughtRecruitmentSystem& operator=(VoughtRecruitmentSystem&& other) noexcept = default;

	void addCriteria(const ICriteria* criteria);
	SubmissionResult submitApplication(const Application& application);
	std::optional<Application> lookupByEmail(const std::string& email);
	void revokeByEmail(const std::string& email);
	const RosterCollection& getCollection() const;
};