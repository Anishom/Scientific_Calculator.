#pragma once
#include <ostream>

class Token
{
public:
  enum class Type
  {
    NUMBER,
    SCI_OPERATOR,
    OPERATOR_HIGH,
    OPERATOR_LOW,
    MATRIX,
    SEPARATOR
  };

  Token(Type type);

  bool isNumber() const;
  bool isOperator() const;
  bool isSeparator() const;
  bool isMatrix() const;

  friend bool operator<(const Token &a, const Token &b);
  friend bool operator<=(const Token &a, const Token &b);
  friend bool operator>(const Token &a, const Token &b);
  friend bool operator==(const Token &a, const Token &b);
  friend bool operator!=(const Token &a, const Token &b);

  virtual ~Token();

private:
  const Type type;
};
