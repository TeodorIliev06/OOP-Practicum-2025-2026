#include <iostream>
#include <iomanip>
#include <fstream>

constexpr double ABSOLUTE_ZERO = -273.15;
constexpr double CELSIUS_TO_FAHRENHEIT_RATE = 1.8;
constexpr double FAHRENHEIT_ZERO = 32.0;

class Thermometer {
private:
    double temperature;

    double getFahrenheit() const {
        return this->temperature * CELSIUS_TO_FAHRENHEIT_RATE + FAHRENHEIT_ZERO;
    }

public:
    Thermometer() : temperature(0) {};

    void setTemperature(double temp) {
        if (temp < ABSOLUTE_ZERO)
        {
            return;
        }

        this->temperature = temp;
    }

    void logTemperature(const std::string& fileName) const {
        std::ofstream out(fileName, std::ios::app);

        if (!out.is_open())
        {
            std::cout << "Can not open this file!" << std::endl;
        }

        out << "In Celsius: " << std::setprecision(2) << this->temperature << "°C" << std::endl;
        out << "In Fahrenheit: " << std::setprecision(2) << this->getFahrenheit() << "°F" << std::endl;
    }
};

class BankAccount {
private:
    std::string accountNumber_;
    std::string ownerName_;
    double balance_;

public:
    //BankAccount() : accountNumber_()

    void deposit(double amount) {
        if (amount <= 0)
        {
            std::cout << "Please enter a positive amount!";
            return;
        }

        this->balance += amount;
    }

    void withdraw(double amount) {
        if (this->balance < amount)
        {
            std::cout << "Please enter an amount less or equal than " << this->balance;
            return;
        }

        this->balance -= amount;
    }

    void exportStatement(const std::string& fileName) const {
        std::ofstream out(fileName, std::ios::app);

        if (!out.is_open())
        {
            std::cout << "Can not open this file!" << std::endl;
        }

        out << "Account holder: " << this->ownerName << std::endl;
        out << "Account number: " << this->accountNumber << std::endl;
        out << "Current balance: " << this->balance << " EUR" << std::endl;
    }
};

int main()
{
    // 1
    Thermometer thermometer = Thermometer();
    thermometer.setTemperature(24);
    thermometer.logTemperature("data.txt");

    // 2
}
