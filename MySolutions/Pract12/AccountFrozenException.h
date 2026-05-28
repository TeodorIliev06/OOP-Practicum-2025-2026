#pragma once
#include "BankException.h"
#include <iostream>

class AccountFrozenException : public BankException {
private:
	std::string accountNumber_;

public:
	AccountFrozenException(const std::string& accountNumber) : accountNumber_(accountNumber),
		BankException(std::format("Account {} is frozen.", accountNumber_)) {
	}
};