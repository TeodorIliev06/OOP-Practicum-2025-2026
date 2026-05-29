#pragma once
#include <iostream>
#include <vector>
class Application {
	std::string codeName_;
	std::string realName_;
	std::string email_;
	int age_;
	int compoundVDosage_;
	std::vector<std::string> powers_;
	double contractDemand_;

public:
	Application(std::string codeName, std::string realName, std::string email, int age, int compoundVDosage, std::vector<std::string> powers, double contractDemand);

	const std::string& getCodeName() const;
	const std::string& getRealName() const;
	const std::string& getEmail() const;
	int getAge() const;
	int getCompoundVDosage() const;
	const std::vector<std::string>& getPowers() const;
	double getContractDemand() const;
};