#include "../includes/SciCalculator.h"

SciCalculator::SciCalculator()
    : arithmeticExprSolver(ArithmeticExprSolver()),
      matrixExprSolver(MatrixExprSolver())
{
  this->exprSolver = &this->arithmeticExprSolver;
}

void SciCalculator::setMode(SciCalculator::OpMode mode)
{
  switch (mode)
  {
  case SciCalculator::OpMode::ARITHMATIC:
    this->exprSolver = &this->arithmeticExprSolver;
    break;

  case SciCalculator::OpMode::MATRIX:
    this->exprSolver = &this->matrixExprSolver;
    break;

  default:
    throw Calculator::ErrorType::UNEXPECTED;
  }
}

string SciCalculator::calculate(const string &expr)
{
  return this->exprSolver->solve(expr);
}
