#include "TakenCoursesByNameRequirement.h"

std::optional<std::string> TakenCoursesByNameRequirement::check(const Student& student)
{
	for (const auto& course: student.getCourses())
	{
		for (const auto& courseName : this->courseNames_)
		{
			if (course.getName() != courseName)
			{
				return "Student has not taken the required courses";
			}
		}
	}

	return std::nullopt;
}

std::unique_ptr<IAdmissionRequirement> TakenCoursesByNameRequirement::clone() const
{
    return std::make_unique<TakenCoursesByNameRequirement>(*this);
}
