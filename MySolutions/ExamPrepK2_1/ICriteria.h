#pragma once
#include "Application.h"
#include <iostream>
#include <optional>

struct ICriteria {
	virtual std::optional<std::string> evaluate(const Application& app) const = 0;
	virtual std::unique_ptr<ICriteria> clone() const = 0;
	virtual ~ICriteria() = default;
};