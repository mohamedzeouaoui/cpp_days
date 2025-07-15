#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <climits>


class ScalarConverter
{
    public:
        static void convert(const std::string& input);

    private:
        ScalarConverter(); // Private constructor to prevent instantiation
        // ScalarConverter(const ScalarConverter&) = delete; // Disable copy constructor
        // ScalarConverter& operator=(const ScalarConverter&) = delete; // Disable assignment operator
        ~ScalarConverter(); // Destructor

        static void convertToChar(const std::string& input);
        static void convertToInt(const std::string& input);
        static void convertToFloat(const std::string& input);
        static void convertToDouble(const std::string& input);

        static bool isValidInput(const std::string& input);
        static void handleConversionError(const std::string& type, const std::string& input);
        static void printConversionResults(char c, int i, float f, double d, const std::string& input);
        
        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);

};


#endif