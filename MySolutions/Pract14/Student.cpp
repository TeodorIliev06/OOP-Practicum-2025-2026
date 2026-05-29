#include "Student.h"

Student::Student(std::string facultyNumber, std::string name, const std::vector<Course>& courses, int credits, double averageGrade) : facultyNumber_(std::move(facultyNumber)), name_(std::move(name)), courses_(courses), credits_(credits), averageGrade_(averageGrade)
{
	if (facultyNumber_.length() != 10 || name_.empty())
	{
		throw std::invalid_argument("Invalid faculty number or name");
	}
	if (credits_ < 0)
	{
		throw std::invalid_argument("Credits cannot be negative");
	}
	if (averageGrade_ < 2.0 || averageGrade_ > 6.0)
	{
		throw std::invalid_argument("Average grade must be between 2.0 and 6.0");
	}
}
