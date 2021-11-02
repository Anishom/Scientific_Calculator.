#include <stack>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>
#include "../includes/ArithmeticExprSolver.h"
#include "../includes/Token.h"
#include "../includes/tokens.h"

constexpr double PI = 3.14159265;

bool isSeparator(char ch)
{
  return ch == '(' || ch == ')';
}

bool isMathOperator(char ch)
{
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void ArithmeticExprSolver::parse(const string &expr)
{
  stringstream ss(expr);

  char ch;
  double number;
  string sciOp;

  while (ss)
  {
    if (ss.eof())
      break;

    if (isdigit(ss.peek()))
    {
      ss >> number;
      this->infixExpr.push_back(new Number(number));
    }

    else if (isSeparator(ss.peek()))
    {
      ss.get(ch);
      this->infixExpr.push_back(new Separator(ch));
    }

    else if (isMathOperator(ss.peek()))
    {
      ss.get(ch);
      this->infixExpr.push_back(new Operator(string(1, ch)));
    }

    else if (!ss.eof())
    {
      sciOp = "";

      while (!ss.eof() && isalpha(ss.peek()))
      {
        ss.get(ch);
        sciOp += ch;
      }

      this->infixExpr.push_back(new Operator(sciOp));
    }
  }
}

string ArithmeticExprSolver::solvePostfix() const
{
  stack<Number> temp;

  for (const Token *token : this->postfixExpr)
  {
    if (token->isNumber())
    {
      const Number num = *dynamic_cast<const Number *>(token);
      temp.push(num);
    }

    else if (token->isOperator())
    {
      const Operator opToken = *dynamic_cast<const Operator *>(token);
      string op = opToken;

      if (opToken.isUnaryOperator())
      {
        double a = temp.top();
        temp.pop();

        double result = 0;

        if (op == Operator::SIN)
          result = sin(a * PI / 180.0);

        else if (op == Operator::COS)
          result = cos(a * PI / 180.0);

        else if (op == Operator::TAN)
          result = tan(a * PI / 180.0);

        else if (op == Operator::LN)
          result = log2(a);

        else if (op == Operator::LOG)
            result = log10(a);

        else if (op == Operator::EXP)
          result = exp(a);

        const Number num(result);
        temp.push(num);
      }

      else if (opToken.isBinaryOperator())
      {
        double a = temp.top();
        temp.pop();

        double b = temp.top();
        temp.pop();

        double result = 0;

        if (op == Operator::PLUS)
          result = a + b;

        else if (op == Operator::MINUS)
          result = a - b;

        else if (op == Operator::MUL)
          result = a * b;

        else if (op == Operator::DIV)
          result = a / b;

        else if (op == Operator::POW)
            result = pow(a, b);

        const Number num(result);
        temp.push(num);
      }
    }
  }

  stringstream ss("");
  ss << temp.top();

  string answer;
  ss >> answer;

  return answer;
}