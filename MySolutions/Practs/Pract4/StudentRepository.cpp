#include "StudentRepository.h"
#include <fstream>

StudentRepository::StudentRepository(const std::string& fileName) 
	: fileName_(fileName) 
{
	if (fileName.empty()) return;

	std::ifstream file(fileName_);
	if (!file.is_open()) return;

	int id;
	std::string name;
	std::string facultyNumber;

	while (file >> id >> name >> facultyNumber) 
	{
		students_.emplace_back(id, name, facultyNumber);

		if (id >= nextId_) 
		{
			nextId_ = id + 1;
		}
	}
}

void StudentRepository::addStudent(const std::string& name, const std::string& facultyNumber)
{
	Student student(nextId_++, name, facultyNumber);
	students_.push_back(student);
}

std::optional<Student> StudentRepository::findById(int id) const
{
	for (const auto& student : students_) {
		if (student.getId() == id) {
			return student;
		}
	}
}

bool StudentRepository::updateStudent(int id, const std::string& name, const std::string& facultyNumber)
{
	std::optional<Student> student = findById(id);
	
	student->setName(name);
	student->setFacultyNumber(facultyNumber);
}

bool StudentRepository::deleteStudent(int id)
{
	for (auto student = students_.begin(); student != students_.end(); student++) {
		if (student->getId() == id) {
			students_.erase(student);
			return true;
		}
	}
	return false;
}

void StudentRepository::save()
{
	
}

//void StudentRepository::load()

std::vector<Student> StudentRepository::getAll() const
{
	return students_;
}