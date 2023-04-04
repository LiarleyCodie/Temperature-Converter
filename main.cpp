#include <iostream>
#include <cctype>
#include <conio.h>

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
  void printTemperatureType()
  {
    std::cout << "Which temperature do you want to converter?\n";
    std::cout << "[C]: Celsius\n";
    std::cout << "[K]: Kelvin\n";
    std::cout << "[F]: Fahrenheit\n";
    std::cout << "Type a letter: ";
  }
  class Formulas
  {
  public:
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
};



int main()
{
  Converter converter;
  Converter::Formulas formulas;
  char temperatureFormula;
  bool waitingChooseTemperature {true};
  char c;

  while (waitingChooseTemperature)
  {
    converter.printTitle();
    converter.printTemperatureType();
    std::cin >> temperatureFormula;
    c = toupper(temperatureFormula);

    switch (c)
    {
      case 'C':
        waitingChooseTemperature = false;
      break;
      case 'F':
        waitingChooseTemperature = false;
      break;
      case 'K':
        waitingChooseTemperature = false;
      break;
      default:
        std::cout << "Wrong Entry!";
        std::cout << "\nPress any key to continue...";
        while (!kbhit()) {};
        converter.clearConsole();
    }
  }

  return 0;
}














