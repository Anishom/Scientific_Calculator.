#include "../includes/Matrix.h"
#include<iostream>
#include <sstream>
using namespace std;

Matrix::Matrix(const int rows, const int cols)
    : Token(Token::Type::MATRIX), rows(rows), cols(cols)
{
  int r = rows;

  while (r--)
    this->values.push_back(vector<double>(cols));
}

Matrix::Matrix(const int rows, const int cols, const vector<vector<double>> &values)
    : Token(Token::Type::MATRIX), rows(rows), cols(cols), values(values)
{
}

const int Matrix::getRowCount() const
{
    return this->rows;
}

const int Matrix::getColCount() const
{
    return this->cols;
}

string Matrix::asString() const
{
  string str("{");

  for (int r(0); r < this->rows; r++)
  {
    str += "{";

    for (int c(0); c < this->cols; c++)
    {
        ostringstream temp;
        temp << values[r][c];

        str += temp.str();

      if (c != this->cols - 1)
        str += ",";
    }

    str += "}";
    if (r != this->rows - 1)
      str += ",";
  }

  str += "}";

  return str;
}

void Matrix::set(int r, int c, double value)
{
  this->values[r][c] = value;
}

double Matrix::get(int r, int c) const
{
  return this->values[r][c];
}

const Matrix operator+(const Matrix &A, const Matrix &B)
{
  Matrix ans(A.rows, A.cols);

  for (int r(0); r < ans.rows; r++)
  {
    for (int c(0); c < ans.cols; c++)
    {
      ans.set(r, c, A.get(r, c) + B.get(r, c));
    }
  }

  return ans;
}

const Matrix operator-(const Matrix &A, const Matrix &B)
{
  Matrix ans(A.rows, A.cols);

  for (int r(0); r < ans.rows; r++)
  {
    for (int c(0); c < ans.cols; c++)
    {
      ans.set(r, c, B.get(r, c) - A.get(r, c));
    }
  }

  return ans;
}

const Matrix operator*(const Matrix &A, const Matrix &B)
{
  Matrix ans(B.rows, A.cols);

  for (int r(0); r < ans.rows; r++)
  {
    for (int c(0); c < ans.cols; c++)
    {
      double sol = 0;

      for (int k(0); k < B.cols; k++)
      {
          sol += (B.get(r,k) * A.get(k,r));
      }

      ans.set(r, c, sol);
    }
  }

  return ans;
}

