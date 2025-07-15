#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::~ScalarConverter()
{

}

bool ScalarConverter::isChar(const std::string& input)
{
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string& input)
{
    if (input.empty())
        return false;

    size_t i = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;

    if (i == input.length())
        return false;
    if (input[i] == '0' && input.length() > 1)
        return false;
    while (i < input.length())
    {
        if (!std::isdigit(input[i]))
            return false;
        i++;
    }
    if (i == input.length() && (input.length() < 11 || (input.length() == 11 && input[0] != '0')))
        return true;
    
    return false;
}

bool ScalarConverter::isFloat(const std::string& input)
{
    if (input.empty())
        return false;

    size_t i = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;

    bool hasDecimalPoint = false;
    while (i < input.length())
    {
        if (input[i] == '.')
        {
            if (hasDecimalPoint)
                return false; // More than one decimal point
            hasDecimalPoint = true;
        }
        else if (!std::isdigit(input[i]))
        {
            return false; // Invalid character
        }
        i++;
    }

    return hasDecimalPoint && i > 1; // Must have at least one digit before and after the decimal point
}

bool ScalarConverter::isDouble(const std::string& input)
{
    if (input.empty())
        return false;

    size_t i = 0;
    if (input[0] == '-' || input[0] == '+')
        i++;

    bool hasDecimalPoint = false;
    while (i < input.length())
    {
        if (input[i] == '.')
        {
            if (hasDecimalPoint)
                return false; // More than one decimal point
            hasDecimalPoint = true;
        }
        else if (!std::isdigit(input[i]))
        {
            return false; // Invalid character
        }
        i++;
    }

    return hasDecimalPoint && i > 1; // Must have at least one digit before and after the decimal point
}

bool ScalarConverter::isValidInput(const std::string& input)
{
    return isChar(input) || isInt(input) || isFloat(input) || isDouble(input);
}

void ScalarConverter::convertToChar(const std::string& input)
{
    char c = static_cast<char>(input[0]);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    int i = static_cast<int>(c);
    std::cout << "int: " << i << std::endl;
    float f = static_cast<float>(c);
    std::cout << "float: " << f << "f" << std::endl;
    double d = static_cast<double>(c);
    std::cout << "double: " << d << std::endl;

}

void ScalarConverter::convertToInt(const std::string& input)
{
    float f;
    char c;
    long long l;
    double d;

    l = std::atol(input.c_str());
    c= static_cast<char>(l);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (l < INT_MIN || l > INT_MAX)
    {
        std::cerr << "int: overflow" << std::endl;
        return;
    }
    else
        std::cout << "int: " << l << std::endl;
    f = static_cast<float>(l);
    std::cout << "float: " << f << "f" << std::endl;
    d = static_cast<double>(l);
    std::cout << "double: " << d << std::endl;
    if (l < std::numeric_limits<float>::min() || l > std::numeric_limits<float>::max())
    {        std::cerr << "float: overflow" << std::endl;
        return;
    }
}

void ScalarConverter::convertToFloat(const std::string& input)
{
    if (input == "nanf" || input == "+inff" || input == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::string newInput = input;
        newInput.erase(newInput.length() - 1);
        std::cout << "double: " << newInput << std::endl;
        return;
    }
    float f = std::atof(input.c_str());
    char c = static_cast<char>(f);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    long i = static_cast<long>(f);
    if (i < INT_MIN || i > INT_MAX)
        std::cerr << "int: overflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    double d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl; 
}

void ScalarConverter::convertToDouble(const std::string& input)
{
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }
    double d = std::atof(input.c_str());
    char c = static_cast<char>(d);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    long i = static_cast<long>(d);
    if (i < INT_MIN || i > INT_MAX)
        std::cerr << "int: overflow" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    float f = static_cast<float>(d);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl; 
    
}


void ScalarConverter::convert(const std::string& input)
{
    if (isChar(input))
        convertToChar(input);
    else if (isInt(input))
        convertToInt(input);
    else if (isFloat(input))
        convertToFloat(input);
    else if (isDouble(input))
        convertToDouble(input);
    else
    {
        std::cerr << "Error: Invalid input '" << input << "'" << std::endl;
    }
}