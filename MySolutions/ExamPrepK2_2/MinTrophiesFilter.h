#pragma once

#include "StarFilter.h"
class MinTrophiesFilter : public StarFilter {
	int minTrophies_;

public:
	explicit MinTrophiesFilter(int minTrophies);

	bool filter(const Star& star) const override;
	std::unique_ptr<StarFilter> clone() const override;
};