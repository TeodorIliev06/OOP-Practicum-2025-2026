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

template <typename T, typename Comparator>
void bubbleSort(std::vector<T>& vector, Comparator comparator) {

	for (size_t i = 0; i < vector.size(); i++)
	{
		bool flag = false;
		for (size_t j = 0; j < vector.size() - i - 1; j++)
		{
			if (comparator(vector[j] < vector[j + 1]))
			{
				std::swap(vector[j], vector[j+1]);
				flag = true;
			}
		}

		if (!flag)
		{
			break;
		}
	}
}

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
	int count;
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
	);

	// 3

}
