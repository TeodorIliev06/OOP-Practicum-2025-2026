#include "BankAccount.h"
#include "InvalidAmountException.h"
#include "AccountFrozenException.h"
#include "InsufficientFundsException.h"
#include "algorithm"

BankAccount::BankAccount(const std::string& accountNumber, const std::string& ownerName, double initialBalance)
{
	if (accountNumber.length() != 10 || ownerName.empty())
	{
		throw std::invalid_argument("");
	}

	if (std::all_of(accountNumber.begin(), accountNumber.end(), !isdigit))
	{
		throw std::invalid_argument("");
	}

	if (initialBalance < 0.0)
	{
		throw InvalidAmountException(initialBalance);
	}
}

void BankAccount::deposit(double amount)
{
	if (this->isFrozen_)
	{
		throw AccountFrozenException(accountNumber_);
	}

	if (amount <= 0.0)
	{
		throw InvalidAmountException(amount);
	}
	else if (amount > 1000000)
	{
		throw std::overflow_error("Deposit exceeds max limit");
	}

	balance_ += amount;
}

void BankAccount::withdraw(double amount)
{
	if (this->isFrozen_)
	{
		throw AccountFrozenException(accountNumber_);
	}
	if (amount <= 0.0)
	{
		throw InvalidAmountException(amount);
	}
	else if (amount > balance_)
	{
		throw InsufficientFundsException(amount, balance_);
	}

	balance_ -= amount;
}

void BankAccount::transfer(BankAccount& dest, double amount)
{
	if (this == dest)
	{

	}

	if (this->isFrozen_ || dest.isFrozen_)
	{
		throw AccountFrozenException(this->accountNumber_);
	}
}
