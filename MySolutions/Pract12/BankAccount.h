#pragma once
#include "BankException.h"
#include <iostream>

class BankAccount {
	std::string accountNumber_;
	std::string ownerName_;
	double balance_;
	bool isFrozen_;

public:
	BankAccount(const std::string& accountNumber, const std::string& ownerName, double initialBalance);

	void deposit(double amount);
	void withdraw(double amount);
	void transfer(BankAccount& dest, double amount);
};