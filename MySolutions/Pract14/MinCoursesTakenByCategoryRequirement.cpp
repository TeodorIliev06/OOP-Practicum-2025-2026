#include "MinCoursesTakenByCategoryRequirement.h"

std::optional<std::string> MinCoursesTakenByCategoryRequirement::check(const Student& student)
{
	int takenCoursesInCategory = 0;

	for (const auto& course : student.getCourses())
	{
		if (course.getCategory() == this->category_)
		{
			takenCoursesInCategory++;
		}
	}

	if (takenCoursesInCategory < this->minCourses_)
	{
		return "Student does not meet the minimum courses taken by category requirement";
	}

	return std::nullopt;
}

std::unique_ptr<IAdmissionRequirement> MinCoursesTakenByCategoryRequirement::clone() const
{
    return std::make_unique<MinCoursesTakenByCategoryRequirement>(*this);
}
