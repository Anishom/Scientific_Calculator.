#include <sstream>
#include "../includes/Matrix.h"
#include "../includes/tokens.h"
#include "../includes/MatrixExprSolver.h"
using namespace std;

void MatrixExprSolver::parse(const string &expr)
{
  stringstream ss(expr);

  char ch;
  bool isInsideMatrix(false);
  vector<vector<double>> values;

  while (true)
  {
    ch = ss.peek();

    if (ss.eof())
      break;

    if (ch == '{')
    {
      ss.get(ch);

      if (isInsideMatrix == false)
      {
        isInsideMatrix = true;
        values.erase(values.begin(), values.end());
      }
      else
      {
        values.push_back(vector<double>());
      }
    }

    else if (ch == '}')
    {
      ss.get(ch);

      if (ss.peek() == '}')
      {
        isInsideMatrix = false;

        this->infixExpr.push_back(new Matrix(values.size(), values[0].size(), values));
      }
    }

    else if (isdigit(ch))
    {
      double d;
      ss >> d;

      values[values.size() - 1].push_back(d);
    }

    else if (ch == ',')
      ss.get(ch);

    else if (ch == '+' || ch == '-' || ch == '*')
    {
      ss.get(ch);
      this->infixExpr.push_back(new Operator(string(1, ch)));
    }
  }
}

string MatrixExprSolver::solvePostfix() const
{
  stack<Matrix> temp;

  for (const Token *token : this->postfixExpr)
  {
    if (token->isMatrix())
    {
      const Matrix num = *dynamic_cast<const Matrix *>(token);
      temp.push(num);
    }

    else if (token->isOperator())
    {
      const Operator opToken = *dynamic_cast<const Operator *>(token);
      string op = opToken;

      if (opToken.isUnaryOperator())
      {
      }

      else if (opToken.isBinaryOperator())
      {
        Matrix a = temp.top();
        temp.pop();

        Matrix b = temp.top();
        temp.pop();

        if (op == Operator::PLUS)
        {
          Matrix result = a + b;
          temp.push(result);
        }

        else if (op == Operator::MINUS)
        {
          Matrix result = a - b;
          temp.push(result);
        }
        else if (op == Operator::MUL)
        {
          Matrix result = a * b;
          temp.push(result);
        }
      }
    }
  }

  return temp.top().asString();
}
