#include "MinTrophiesFilter.h"

MinTrophiesFilter::MinTrophiesFilter(int minTrophies) : minTrophies_(minTrophies)
{
	if (this->minTrophies_ < 0)
	{
		throw std::runtime_error("...");
	}
}

bool MinTrophiesFilter::filter(const Star& star) const
{
	return star.getTrophies() >= this->minTrophies_;
}

std::unique_ptr<StarFilter> MinTrophiesFilter::clone() const
{
    return std::make_unique<MinTrophiesFilter>(*this);
}
