#pragma once
#include <string>
#include "Token.h"

using namespace std;

class Separator : public Token
{
private:
  const char value;

public:
  Separator(const char value);

  operator char() const;
};

class Number : public Token
{
private:
  const double value;

public:
  Number(const double value);

  operator double() const;
};

class Operator : public Token
{
private:
  const string name;

public:
  static const string SIN;
  static const string COS;
  static const string TAN;
  static const string LOG;
  static const string POW;
  static const string LN;
  static const string EXP;
  static const string PLUS;
  static const string MINUS;
  static const string MUL;
  static const string DIV;

  Operator(const string name);

  bool isUnaryOperator() const;
  bool isBinaryOperator() const;

  operator string() const;

  friend bool operator==(const Operator &a, const Operator &b);
};
