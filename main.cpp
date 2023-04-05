#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

using std::string;

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
  };
  void printTitle()
  {
      std::cout << "=====================================\n";
      std::cout << "        Temperature Converter        \n";
      std::cout << "=====================================\n";
      std::cout << std::endl;
  };
  void waitForKey()
  {
    std::cout << "\nPress any key to continue...";
    while (!kbhit()) {};
  };
  void printChooseTemperature()
  {
    std::cout << "Which temperature do you want to converter?\n";
    std::cout << "[C]: Celsius\n";
    std::cout << "[K]: Kelvin\n";
    std::cout << "[F]: Fahrenheit\n";
    std::cout << "Type a letter: ";
  };
  void printHowToConvert(string temperature)
  {
    std::cout << "How do you will convert?\n";

    if (temperature == "Celsius")
    {
        std::cout << "[0]: " << temperature << " to Fahrenheit" << std::endl;
        std::cout << "[1]: " << temperature << " to Kelvin" << std::endl;
        std::cout << "[2]: " << temperature << " to all" << std::endl;
    }
    else if (temperature == "Fahrenheit")
    {
        std::cout << "[0]: " << temperature << " to Celsius" << std::endl;
        std::cout << "[1]: " << temperature << " to Kelvin" << std::endl;
        std::cout << "[2]: " << temperature << " to all" << std::endl;
    }
    else if (temperature == "Kelvin")
    {
        std::cout << "[0]: " << temperature << " to Fahrenheit" << std::endl;
        std::cout << "[1]: " << temperature << " to Celsius" << std::endl;
        std::cout << "[2]: " << temperature << " to all" << std::endl;
    }
  };
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
  char userChar; // for store user input
  char _userChar; // for switch...case statement
  bool waitingChooseTemperature {true};
  bool waitingChooseMethod {false};
  string temperature;

  // choose temperature
  while (waitingChooseTemperature)
  {
    converter.printTitle();
    converter.printChooseTemperature();
    std::cin >> userChar;
    _userChar = toupper(userChar);

    switch (_userChar)
    {
      case 'C':
        waitingChooseTemperature = false;
        waitingChooseMethod = true;
        temperature = "Celsius";
      break;
      case 'F':
        waitingChooseTemperature = false;
        waitingChooseMethod = true;
        temperature = "Fahrenheit";
      break;
      case 'K':
        waitingChooseTemperature = false;
        waitingChooseMethod = true;
        temperature = "Kelvin";
      break;
      default:
        std::cout << "Wrong Entry!";

        converter.waitForKey();
        converter.clearConsole();
    }
  }

  // how the temperature will be converted
  while (waitingChooseMethod)
  {
    converter.clearConsole();
    converter.printTitle();

    converter.printHowToConvert(temperature);

    // temp
    converter.waitForKey();
    break;
  }
  return 0;
}














