#pragma once
#include <vector>
#include "Application.h"
#include "ICriteria.h"
#include "RosterCollection.h"
#include "SubmissionResult.h"

class VoughtRecruitmentSystem {
	std::vector<std::unique_ptr<ICriteria>> criterias;
	RosterCollection collection;

public:
	void addCriteria(const ICriteria* criteria);
	
	std::optional<Application> lookupByEmail(const std::string& email);
	void revokeByEmail(const std::string& email);
	const RosterCollection& getCollection() const;
};