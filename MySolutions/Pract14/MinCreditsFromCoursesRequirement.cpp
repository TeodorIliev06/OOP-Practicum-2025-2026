#include "MinCreditsFromCoursesRequirement.h"

std::optional<std::string> MinCreditsFromCoursesRequirement::check(const Student& student)
{
	int totalCreditsFromCourses = 0;

	for (const auto& course : student.getCourses())
	{
		totalCreditsFromCourses += course.getCredits();
	}

	if (totalCreditsFromCourses < this->getMinCreditsFromCourses())
	{
		return "Student does not meet the minimum credits from courses requirement";
	}

	return std::nullopt;
}

std::unique_ptr<IAdmissionRequirement> MinCreditsFromCoursesRequirement::clone() const
{
    return std::make_unique<MinCreditsFromCoursesRequirement>(*this);
}
