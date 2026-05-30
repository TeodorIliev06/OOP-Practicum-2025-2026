#pragma once

#include "StarFilter.h"
class RarityFilter : public StarFilter {
	Rarity rarity_;

public:
	explicit RarityFilter(Rarity rarity);

	bool filter(const Star& star) const override;

	std::unique_ptr<StarFilter> clone() const override;

};