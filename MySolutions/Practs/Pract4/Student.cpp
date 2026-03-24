#include "Student.h"
#include <print>

Student::Student(int id, const std::string& name, const std::string& facultyNumber) : id_(id), name_(name), facultyNumber_(facultyNumber) {}

int Student::getId() const {
	return id_;
}

void Student::setName(const std::string& name)
{
	name_ = name;
}

void Student::setFacultyNumber(const std::string& facultyNumber)
{
	facultyNumber_ = facultyNumber;
}

void Student::print() const {
	std::print("ID: {}, Name: {}, Faculty Number: {}", id_, name_, facultyNumber_);
}