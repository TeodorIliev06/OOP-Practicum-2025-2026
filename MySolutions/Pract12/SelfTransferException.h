#pragma once
#include "BankException.h"

class SelfTransferException : public BankException {
	SelfTransferException() : BankException("Cannot transfer to the same account.") {}
};