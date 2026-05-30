#pragma once

#include "ICriteria.h"

class CriteriaFactory {
public:
	CriteriaFactory() = delete;

	static std::unique_ptr<ICriteria> create(const std::string& criteriaType, const std::string& parameter);
};