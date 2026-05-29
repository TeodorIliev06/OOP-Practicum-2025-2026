#include "MinAverageGradeRequirement.h"

std::optional<std::string> MinAverageGradeRequirement::check(const Student& student)
{
	if (student.getAverageGrade() < this->minAverageGrade_)
	{
		return "Student does not meet the minimum average grade requirement";
	}

	return std::nullopt;
}

std::unique_ptr<IAdmissionRequirement> MinAverageGradeRequirement::clone() const
{
    return std::make_unique<MinAverageGradeRequirement>(*this);
}
