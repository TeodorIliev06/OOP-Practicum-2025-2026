#include "Course.h"

std::string Course::getName() const
{
    return this->name_;
}

int Course::getCredits() const
{
    return this->credits_;
}

Category Course::getCategory() const
{
    return this->category;
}
