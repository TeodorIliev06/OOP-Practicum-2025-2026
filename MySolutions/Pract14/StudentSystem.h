#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include "Student.h"
#include "AdmissionService.h"
#include "AdmissionResult.h"

class StudentSystem {
	std::vector<std::unique_ptr<Student>> students_;
	std::shared_ptr<AdmissionService> admissionService_;

public:
	void addStudent(const Student& student);
	void removeStudent(const std::string& facultyNumber);
	AdmissionResult isAdmitted(const Student& student) const;
	std::vector<Student> filter(std::function<bool(const Student&)> predicate) const;

	const Student& operator[](const std::string& facultyNumber) const;
};