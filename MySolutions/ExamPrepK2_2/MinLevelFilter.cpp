#include "MinLevelFilter.h"

MinLevelFilter::MinLevelFilter(int minLevel) : minLevel_(minLevel)
{
    if (this->minLevel_ < 0 || this->minLevel_ > 11)
    {
        throw std::runtime_error("...");
	}
}

bool MinLevelFilter::filter(const Star& star) const
{
	return this->minLevel_ <= star.getLevel();
}

std::unique_ptr<StarFilter> MinLevelFilter::clone() const
{
    return std::unique_ptr<StarFilter>();
}
