#include <iostream>
#include<vector>
#include<string>

struct ComplexNum {
	int real;
	int imaginary;

	ComplexNum(int real, int imaginary)
	{
		this->real = real;
		this->imaginary = imaginary;
	}

	ComplexNum sum(const ComplexNum& num) {
		int realRes = this->real + num.real;
		int imaginaryRes = this->imaginary + num.imaginary;

		return  ComplexNum{
			real = realRes,
			imaginary = imaginaryRes
		};
	}

	ComplexNum multiply(const ComplexNum& num) {
		int realRes = this->real * num.real - this->imaginary * num.imaginary;
		int imaginaryRes 
			= this->imaginary * num.real + this->real * num.imaginary;

		return  ComplexNum{
			real = realRes,
			imaginary = imaginaryRes
		};
	}

	ComplexNum divide(ComplexNum& num) {
		ComplexNum multiplier = { num.real, -num.imaginary };

		ComplexNum numerator = this->multiply(multiplier);
		ComplexNum denominator = num.multiply(multiplier);

		int realRes = numerator.real / denominator.real;

		int imaginaryRes = denominator.imaginary > 0 
			? numerator.imaginary / denominator.imaginary
			: 0;

		return  ComplexNum{
			real = realRes,
			imaginary = imaginaryRes
		};
	}

	void print() {
		char _operator = ' ';

		if (this->real > 0 && this->imaginary > 0)
		{
			_operator = '+';
			std::cout << this->real << " " << _operator << " "
				<< this->imaginary << "i";
		}
		else if (this->imaginary > 0)
		{
			std::cout << this->imaginary << "i";
		}
		else if (this->real > 0)
		{
			std::cout << this->real;
		}
	}
};

struct Triangle {
	int a, b, c;

	int getPerimeter() {
		return this->a + this->b + this->c;
	}

	int getArea() {
		int halfPerimeter = getPerimeter() / 2;

		return (int)round(sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c)));
	}
};

enum class Major {
	SE,
	IS,
	CS,
	AM,
	M,
	I
};

Major parseMajor(const std::string& majorString) 
{
	if (majorString == "SE") return Major::SE;
	else if (majorString == "IS") return Major::IS;
	else if (majorString == "CS") return Major::CS;
	else if (majorString == "AM") return Major::AM;
	else if (majorString == "M") return Major::M;
	else if (majorString == "I") return Major::I;
	 /* TODO throw an error*/
}

template <typename T, typename Comparator>
void bubbleSort(std::vector<T>& vector, Comparator comparator) {

	for (size_t i = 0; i < vector.size(); i++)
	{
		bool flag = false;
		for (size_t j = 0; j < vector.size() - i - 1; j++)
		{
			if (comparator(vector[j], vector[j + 1]))
			{
				std::swap(vector[j], vector[j + 1]);
				flag = true;
			}
		}

		if (!flag)
		{
			break;
		}
	}
}

struct Student {
	std::string facultyNum;
	std::string name_;
	double grade;
	Major major;
};

struct Group {
	std::vector<Student> students;
	double averageGrade;
};

Group createGroup(Group group) {
	int count;
	std::cin >> count;

	for (size_t i = 0; i < count; i++)
	{
		Student student;
		std::string majorString;
		std::cin >> student.facultyNum >> student.name_ >> student.grade >> majorString;

		student.major = parseMajor(majorString);

		group.students.push_back(student);
	}

	double gradesSum = 0;
	for (size_t i = 0; i < group.students.size(); i++)
	{
		gradesSum += group.students[i].grade;
	}

	group.averageGrade = gradesSum / group.students.size();

	return group;
}

int getScholarshipsCount(Group group, int minGrade) {
	int scholarshipsCount = 0;
	for (size_t i = 0; i < group.students.size(); i++)
	{
		if (group.students[i].grade >= minGrade)
		{
			scholarshipsCount++;
		}
	}

	return scholarshipsCount;
}

std::vector<Student> getEligibleStudents(Group group, int minGrade) {
	std::vector<Student> eligibleStudents;
	for (size_t i = 0; i < group.students.size(); i++)
	{
		if (group.students[i].grade >= minGrade)
		{
			eligibleStudents.push_back(group.students[i]);
		}
	}

	bubbleSort(group.students, [](const Student& first, const Student& second) {
		return first.facultyNum < second.facultyNum;
	});

	return eligibleStudents;
}

bool findStudent(Group group, std::string& facultyNumber) {
	int left = 0;
	int right = group.students.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		const Student& currentStudent = group.students[mid];

		if (currentStudent.facultyNum == facultyNumber)
		{
			return true;
		}
		else if (currentStudent.facultyNum > facultyNumber)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return false;
}

struct Point {
	int x;
	int y;

	void print() {
		std::cout << '(' << this->x << ';' << this->y << ')';
	}

	double calculateDistanceFromCenter() {
		return calculateDistance(0, 0);
	}

	double calculateDistance(int secondX, int secondY) {
		return (double)sqrt(pow((this->x - secondX), 2) + pow((this->y - secondY), 2));
	}

	int getQuadrant(Point point) {
		if (point.x > 0)
		{
			if (point.y > 0)
			{
				return 1;
			}
			else if (point.y < 0)
			{
				return 4;
			}
			else 
			{
				return 0;
			}	
		}
		else if (point.x < 0)
		{
			if (point.y > 0)
			{
				return 2;
			}
			else if (point.y < 0)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	bool isInsideCircle(Point point, int radius) {
		if (pow(point.x, 2) + pow(point.y, 2) <= pow(radius, 2))
		{
			return true;
		}

		return false;
	}
};

int main()
{
	// 1
	//ComplexNum test1 = { 1, 1 };
	//ComplexNum test2 = { 2, 2 };

	//test1.print();
	//test1.sum(test2).print();
	//test1.multiply(test2).print();
	//test1.divide(test2).print();

	// 2
	/*int count;
	std::cin >> count;

	std::vector<int> areas;
	for (size_t i = 0; i < count; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		Triangle triangle = { a, b, c };
		areas.push_back(triangle.getArea());
	}

	bubbleSort(areas, [](int a, int b) {
		return a < b;}
	);*/

	// 3
	//Group group = createGroup()
}
