#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

class Converter
{
public:
    void clearConsole()
    {
        #ifdef _WIN32
        system("cls");
        #else
        std::cout << "\033[2J\033[1;1H";
        #endif // _WIN32
    }
    void printTitle()
    {
        std::cout << "=====================================\n";
        std::cout << "        Temperature Converter        \n";
        std::cout << "=====================================\n";
        std::cout << std::endl;
    };
    double CelsiusToFahrenheit(double value)
    {
        return (9/5) * value + 32;
    };
    double FahrenheitToCelsius(double value)
    {
        return (5/9) * (value - 32);
    };
    double CelsiusToKelvin(double value)
    {
        return value + 273.15;
    };
    double KelvinToCelsius(double value)
    {
        return value - 273.15;
    };
    double FahrenheitToKelvin(double value)
    {
        return (5/9) * (value - 32) + 273.15;
    };
    double KelvinToFahrenheit(double value)
    {
        return (9/5) * (value - 273.15) + 32;
    };

};

int main()
{
    Converter converter;
    char temperatureFormula;

    converter.printTitle();

    std::cout << "Which temperature do you want to converter?\n";
    std::cout << "[C]: Celsius\n";
    std::cout << "[K]: Kelvin\n";
    std::cout << "[F]: Fahrenheit\n";
    std::cout << "Type a letter: ";

    std::cin >> temperatureFormula;

    converter.clearConsole();

    return 0;
}














