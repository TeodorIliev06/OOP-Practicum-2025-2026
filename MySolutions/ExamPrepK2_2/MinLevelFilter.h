#pragma once

#include "StarFilter.h"
class MinLevelFilter : public StarFilter {
	int minLevel_;

public:
	explicit MinLevelFilter(int minLevel);

	bool filter(const Star& star) const override;
	std::unique_ptr<StarFilter> clone() const override;
};