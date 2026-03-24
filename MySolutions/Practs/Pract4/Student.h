#pragma once
#include <string>
#include <print>

class Student {
private:
	int id_;
	std::string name_;
	std::string facultyNumber_;

public:
	Student() = default;

	Student(int id, const std::string& name, const std::string& facultyNumber);

	int getId() const;

	void setName(const std::string& name);
	void setFacultyNumber(const std::string& facultyNumber);

	void print() const;
};