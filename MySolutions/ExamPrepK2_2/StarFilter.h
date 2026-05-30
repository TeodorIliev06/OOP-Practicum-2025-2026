#pragma once

#include "Star.h"
class StarFilter {
public:
	virtual ~StarFilter() = default;
	virtual bool filter(const Star& star) const = 0;
	virtual std::unique_ptr<StarFilter> clone() const = 0;
};