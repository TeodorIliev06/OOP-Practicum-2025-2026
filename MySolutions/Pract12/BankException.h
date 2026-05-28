#pragma once
#include <exception>
#include <iostream>

class BankException : public std::exception {
protected:
	std::string message_;

public:
	BankException(const std::string& message);

	const char* what() const noexcept override;
};