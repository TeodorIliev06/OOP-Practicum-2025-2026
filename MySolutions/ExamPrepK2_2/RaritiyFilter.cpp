#include "RaritiyFilter.h"

RarityFilter::RarityFilter(Rarity rarity) : rarity_(rarity)
{
    if (this->rarity_ < Rarity::Rare || this->rarity_ > Rarity::Legendary)
    {
        throw std::runtime_error("...");
	}
}

bool RarityFilter::filter(const Star& star) const
{
	return star.getRarity() >= this->rarity_;
}

std::unique_ptr<StarFilter> RarityFilter::clone() const
{
    return std::make_unique<RarityFilter>(*this);
}
