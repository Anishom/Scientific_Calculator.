#pragma once
#include <string>
#include <stack>
#include <vector>
#include "ExprSolver.h"
#include "Matrix.h"

using namespace std;

class MatrixExprSolver : public ExprSolver
{
private:
  void parse(const string &expr);

  string solvePostfix() const;

  Matrix transpose(const Matrix &matrix) const;

  double determinant(const Matrix &matrix) const;

  Matrix inverse(const Matrix &matrix) const;

  double dot(const Matrix &A, const Matrix &B) const;
  Matrix cross(const Matrix &A, const Matrix &B) const;
};
