#include <sstream>
#include "../includes/Matrix.h"
#include "../includes/tokens.h"
#include "../includes/MatrixExprSolver.h"
using namespace std;

Matrix MatrixExprSolver::transpose(const Matrix &matrix) const
{
    Matrix ans(matrix.getColCount(), matrix.getRowCount());

    for (int r(0); r < ans.getRowCount(); r++)
    {
        for (int c(0); c < ans.getColCount(); c++)
        {
            ans.set(r, c, matrix.get(c, r));
        }
    }

    return ans;
}

Matrix MatrixExprSolver::dot(const Matrix &A, const Matrix &B) const
{
    Matrix ans(1,1);
    double sum = 0;

    for (int c(0); c < A.getColCount(); c++)
    {
        sum += (A.get(0,c) * B.get(0,c));
    }

    ans.set(0, 0, sum);
    return ans;
}

Matrix MatrixExprSolver::cross(const Matrix &A, const Matrix &B) const
{
    Matrix ans(1,3);
    double temp;

    temp = (A.get(0,2) * B.get(0,1)) - (A.get(0,1) * B.get(0,2));
    ans.set(0,0,temp);

    temp = (A.get(0,0) * B.get(0,2)) - (A.get(0,2) * B.get(0,0));
    ans.set(0,1,temp);

    temp = (A.get(0,1) * B.get(0,0)) - (A.get(0,0) * B.get(0,1));
    ans.set(0,2,temp);

    return ans;
}

void MatrixExprSolver::parse(const string &expr)
{
  stringstream ss(expr);

  char ch;
    string sciOp;
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

    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '.' || ch == 'x')
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
          Matrix a = temp.top();
          temp.pop();

          if (op == Operator::DET)
          {
              if (a.getRowCount() == a.getColCount())
              {
                  //////////
              }
              else
              {
                  return "ERROR";
              }
          }
          else if (op == Operator::TRN)
          {
              Matrix result = transpose(a);
              temp.push(result);
          }
          else if (op == Operator::INV)
          {
              if (a.getRowCount() == a.getColCount())
              {
                  //////////
              }
              else
              {
                  return "ERROR";
              }
          }
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

        else if (op == Operator::DIV)
        {
            Matrix result = a / b;
            temp.push(result);
        }

        else if (op == Operator::DOT)
        {
            Matrix result = dot(a,b);
            temp.push(result);
        }

        else if (op == Operator::CROSS)
        {
            Matrix result = cross(a,b);
            temp.push(result);
        }
      }
    }
  }

  return temp.top().asString();
}
