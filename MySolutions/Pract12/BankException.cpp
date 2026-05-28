#include "BankException.h"

BankException::BankException(const std::string& message) : message_(message)
{
}

const char* BankException::what() const noexcept
{
	return message_.c_str();
}