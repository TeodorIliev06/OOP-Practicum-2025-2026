#include <iostream>
#include <iomanip>
#include <fstream>

constexpr double ABSOLUTE_ZERO = -273.15;
constexpr double CELSIUS_TO_FAHRENHEIT_RATE = 1.8;
constexpr double FAHRENHEIT_ZERO = 32.0;

class Thermometer {
private:
    double temperature;

    double getFahrenheit() {
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

    void logTemperature(const std::string& fileName) {
        std::ofstream out(fileName, std::ios::app);

        if (!out.is_open())
        {
            std::cout << "Can not open this file!" << std::endl;
        }

        out << "In Celsius: " << std::setprecision(2) << this->temperature << "°C" << std::endl;
        out << "In Fahrenheit: " << std::setprecision(2) << this->getFahrenheit() << "°F" << std::endl;
    }
};

int main()
{
    // 1
    Thermometer thermometer = Thermometer();
    thermometer.setTemperature(24);
    thermometer.logTemperature("data.txt");
}
