#pragma once
#include <iostream>
#include <vector>
#include "Course.h"

class Student {
	std::string facultyNumber_;
	std::string name_;
	std::vector<Course> courses_;
	int credits_;
	double averageGrade_;

public:
	Student(std::string facultyNumber, std::string name, const std::vector<Course>& courses, int credits, double averageGrade);

	std::string getFacultyNumber() const;
	std::string getName() const;
	std::vector<Course> getCourses() const;
	int getCredits() const;
	double getAverageGrade() const;
};