#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class Matrix : public Token
{
private:
  const int rows;
  const int cols;
  vector<vector<double>> values;

public:
  Matrix(const int rows, const int cols);
  Matrix(const int rows, const int cols, const vector<vector<double>> &values);

  const int getRowCount() const;
  const int getColCount() const;

  friend const Matrix operator+(const Matrix &A, const Matrix &B);
  friend const Matrix operator-(const Matrix &A, const Matrix &B);
  friend const Matrix operator*(const Matrix &A, const Matrix &B);

  string asString() const;

  void set(int r, int c, double value);
  double get(int r, int c) const;
};
