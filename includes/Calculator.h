#pragma once
#include <string>
using namespace std;

class Calculator
{
public:
  enum class OpMode
  {
    ARITHMATIC,
    MATRIX
  };

  enum class ErrorType
  {
    INVALID_EXPR = 100,
    OVERFLOW,
    INVALID_MATRIX_DIM,
    UNEXPECTED
  };

  virtual string calculate(const string &expr) = 0;

  virtual void setMode(OpMode mode) = 0;
};
