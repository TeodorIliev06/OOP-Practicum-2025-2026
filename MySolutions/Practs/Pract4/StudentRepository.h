#pragma once
#include "Student.h"
#include <vector>
#include <string>
#include <optional>

class StudentRepository {
private:
	std::vector<Student> students_;
	std::string fileName_;
	static int nextId_;

public:
	StudentRepository(const std::string& fileName);

	void addStudent(const std::string& name, const std::string& facultyNumber);

	std::optional<Student> findById(int id) const;

	bool updateStudent(int id, const std::string& name, const std::string& facultyNumber);

	bool deleteStudent(int id);

	void save();

	void load();

	std::vector<Student> getAll() const;
};