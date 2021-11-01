#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Token.h"
using namespace std;

using token_container = vector<const Token *>;

class ExprSolver
{
protected:
  token_container infixExpr;
  token_container postfixExpr;

private:
  virtual void parse(const string &expr) = 0;

  void toPostfix();

  virtual string solvePostfix() const = 0;

public:
  string solve(const string &expr);

  friend class ExprSolverTester;
};
