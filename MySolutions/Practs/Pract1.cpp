#include <iostream>

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

int main()
{
	ComplexNum test1 = { 1, 1 };
	ComplexNum test2 = { 2, 2 };

	//test1.print();
	//test1.sum(test2).print();
	//test1.multiply(test2).print();
	test1.divide(test2).print();
}
