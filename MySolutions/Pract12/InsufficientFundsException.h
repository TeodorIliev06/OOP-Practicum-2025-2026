#pragma once
#include "BankException.h"
class InsufficientFundsException : public BankException {
private:
	double requested_;
	double available_;

public:
	InsufficientFundsException(double requested, double available) : requested_(requested), available_(available),
		BankException(std::format("Insufficient funds: requested {}, available {}", requested_, available_)) {}
};
