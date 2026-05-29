#include "AdmissionResult.h"

void AdmissionResult::showResult() const
{
	if (isAdmitted_)
	{
		std::cout << "Student is admitted to the state exam." << std::endl;
		return;
	}

	std::cout << "Student is not admitted to the state exam: " << std::endl;

	for(const auto& error : this->errors_)
	{
		std::cout << "- " << error << std::endl;
	}
}
