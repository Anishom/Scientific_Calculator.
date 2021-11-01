#pragma once
#include "Calculator.h"
#include "ExprSolver.h"
#include "ArithmeticExprSolver.h"
#include "MatrixExprSolver.h"

class SciCalculator : public Calculator
{
private:
  ArithmeticExprSolver arithmeticExprSolver;
  MatrixExprSolver matrixExprSolver;
  ExprSolver *exprSolver;

public:
  SciCalculator();

  string calculate(const string &expr);

  void setMode(OpMode mode);
};
