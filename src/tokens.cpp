#include "../includes/Token.h"
#include "../includes/tokens.h"

Number::Number(const double value)
    : Token(Token::Type::NUMBER),
      value(value)
{
}

Number::operator double() const
{
  return this->value;
}

Separator::Separator(const char value)
    : Token(Token::Type::SEPARATOR),
      value(value)
{
}

Separator::operator char() const
{
  return this->value;
}

Token::Type getOperatorType(const string &name)
{
  if (name == "+" || name == "-")
    return Token::Type::OPERATOR_LOW;

  if (name == "*" || name == "/")
    return Token::Type::OPERATOR_HIGH;

  return Token::Type::SCI_OPERATOR;
}

const string Operator::SIN = "sin";
const string Operator::COS = "cos";
const string Operator::TAN = "tan";
const string Operator::LOG = "log";
const string Operator::POW = "pow";
const string Operator::LN = "ln";
const string Operator::EXP = "e";
const string Operator::PLUS = "+";
const string Operator::MINUS = "-";
const string Operator::MUL = "*";
const string Operator::DIV = "/";

Operator::Operator(const string name)
    : Token(getOperatorType(name)),
      name(name)
{
}

Operator::operator string() const
{
  return this->name;
}

bool Operator::isUnaryOperator() const
{
  return this->name == SIN || this->name == COS || this->name == TAN || this->name == LOG || this->name == POW || this->name == LN || this->name == EXP;
}

bool Operator::isBinaryOperator() const
{
  return this->name == PLUS || this->name == MINUS || this->name == MUL || this->name == DIV;
}

bool operator==(const Operator &a, const Operator &b)
{
  return a == b;
}
