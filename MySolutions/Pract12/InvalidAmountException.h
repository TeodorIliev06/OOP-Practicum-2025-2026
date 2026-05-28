#pragma once
#include "BankException.h"

class InvalidAmountException : public BankException {
private:
	double invalidAmount_;

public:
	InvalidAmountException(double invalidAmount) : invalidAmount_(invalidAmount),
		BankException(std::format("Invalid amount: {}.", invalidAmount_)) {
	}
};