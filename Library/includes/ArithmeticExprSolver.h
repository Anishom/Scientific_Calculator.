#pragma once
#include <string>
#include <stack>
#include <vector>
#include "ExprSolver.h"

using namespace std;

class ArithmeticExprSolver : public ExprSolver
{
private:
  void parse(const string &expr);

  string solvePostfix() const;

public:
  friend class ArithmeticExprSolverTester;
};
