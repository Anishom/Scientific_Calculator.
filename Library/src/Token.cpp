#include "../includes/Token.h"

Token::Token(typename Token::Type type) : type(type) {}

bool Token::isNumber() const
{
  return this->type == Token::Type::NUMBER;
}

bool Token::isMatrix() const
{
  return this->type == Token::Type::MATRIX;
}

bool Token::isOperator() const
{
  return this->type == Token::Type::OPERATOR_HIGH || this->type == Token::Type::OPERATOR_LOW || this->type == Token::Type::SCI_OPERATOR;
}

bool Token::isSeparator() const
{
  return this->type == Token::Type::SEPARATOR;
}

bool operator==(const Token &a, const Token &b)
{
  return a.type == b.type;
}

bool operator!=(const Token &a, const Token &b)
{
  return !(a == b);
}

bool operator<(const Token &a, const Token &b)
{
  if (a != b && a.isOperator() && b.isOperator())
  {
    if (b.type == Token::Type::SCI_OPERATOR)
      return true;

    if (b.type == Token::Type::OPERATOR_HIGH)
      return true;

    return false;
  }

  return false;
}

bool operator<=(const Token &a, const Token &b)
{
  return a == b || a < b;
}

bool operator>(const Token &a, const Token &b)
{
  return !(a < b) && a != b;
}

Token::~Token() {}
