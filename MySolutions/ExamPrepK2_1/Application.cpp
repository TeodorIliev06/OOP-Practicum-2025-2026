#include "Application.h"

Application::Application(std::string codeName, std::string realName, std::string email, int age, int compoundVDosage, std::vector<std::string> powers, double contractDemand)
    : codeName_(std::move(codeName)), realName_(std::move(realName)), email_(std::move(email)), age_(age), compoundVDosage_(compoundVDosage), powers_(std::move(powers)), contractDemand_(contractDemand)
{
}

const std::string& Application::getCodeName() const
{
	return this->codeName_;
}

const std::string& Application::getRealName() const
{
	return this->realName_;
}

const std::string& Application::getEmail() const
{
	return this->email_;
}

int Application::getAge() const
{
	return this->age_;
}

int Application::getCompoundVDosage() const
{
    return this->compoundVDosage_;
}

const std::vector<std::string>& Application::getPowers() const
{
	return this->powers_;
}

double Application::getContractDemand() const
{
	return this->contractDemand_;
}
