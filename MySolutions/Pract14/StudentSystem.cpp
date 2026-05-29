#include "StudentSystem.h"
#include "AdmissionResult.h"
#include <algorithm>
void StudentSystem::addStudent(const Student& student)
{
	for (const auto& existingStudent : this->students_)
	{
		if (student.getFacultyNumber() == existingStudent->getFacultyNumber())
		{
			throw std::invalid_argument("Student with the same faculty number already exists");
		}
	}
	
	this->students_.push_back(std::make_unique<Student>(student));
}

void StudentSystem::removeStudent(const std::string& facultyNumber)
{
	std::erase_if(this->students_, [&facultyNumber](const std::unique_ptr<Student>& student) {
		return student->getFacultyNumber() == facultyNumber;
	});
}

AdmissionResult StudentSystem::isAdmitted(const Student& student) const
{
	std::vector<std::string> errors = this->admissionService_->checkAdmission(student);

	return AdmissionResult(errors, errors.empty());
}

std::vector<Student> StudentSystem::filter(std::function<bool(const Student&)> predicate) const
{
	
}

const Student& StudentSystem::operator[](const std::string& facultyNumber) const
{
	for (const auto& student : this->students_)
	{
		if (student->getFacultyNumber() == facultyNumber)
		{
			return *student;
		}
	}

	throw std::out_of_range("Student with the given faculty number does not exist");
}
