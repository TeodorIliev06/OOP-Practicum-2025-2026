#pragma once
#include <iostream>

enum class Category {
	Programming,
	Mathematics,
	AppliedMathematics,
	Other
};

class Course {
	std::string name_;
	int credits_;
	Category category;
	bool isMandatory_;
	
public:
	Course(std::string name, int credits, Category category, bool isMandatory) : name_(std::move(name)), credits_(credits), category(category), isMandatory_(isMandatory)
	{
		if (name_.empty())
		{
			throw std::invalid_argument("Course name cannot be empty");
		}
		if (credits_ < 0)
		{
			throw std::invalid_argument("Credits cannot be negative");
		}
	}

	std::string getName() const;
	int getCredits() const;
	Category getCategory() const;
};