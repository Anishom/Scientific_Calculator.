#include <iostream>
#include "../includes/calclib.h"
#include "../includes/Calculator.h"
#include "../includes/SciCalculator.h"

using namespace std;

Calculator &getCalculator()
{
  static SciCalculator calculator;

  return calculator;
}

std::string calculate(std::string expr)
{
  return getCalculator().calculate(expr);
}

void setArithmeticMode()
{
  getCalculator().setMode(Calculator::OpMode::ARITHMATIC);
}

void setMatrixMode()
{
  getCalculator().setMode(Calculator::OpMode::MATRIX);
}
