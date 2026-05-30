#include "Star.h"

Star::Star(std::string name, int trophies, int level, Rarity rarity) : name_(std::move(name)), trophies_(trophies), level_(level), rarity_(rarity)
{
	if (level < 0 || level > 11)
	{
		throw std::invalid_argument("Max contract demand must be positive");
	}

	if (trophies < 0)
	{
		throw std::invalid_argument("Trophies must be positive");
	}

	if (this->rarity_ < Rarity::Rare || this->rarity_ > Rarity::Legendary)
	{
		throw std::invalid_argument("Rarity must be in bounds");
	}
}

const std::string& Star::getName() const
{
	return name_;
}

const int Star::getTrophies() const
{
	return trophies_;
}

const int Star::getLevel() const
{
	return level_;
}

const Rarity Star::getRarity() const
{
	return this->rarity_;
}

void Star::addTrophies(int trophies)
{
	this->trophies_ += trophies;
}
