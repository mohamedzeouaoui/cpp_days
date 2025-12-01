#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <utility>
#include <exception>
#include <string.h>
#include <string>
#include <ctype.h>
#include <sstream>

class RPN
{
public:
  static long evaluate(const std::string &expr);

private:
  static bool isOperator(char c);
  static long apply_Op(long a, long b, char op);
};

#endif