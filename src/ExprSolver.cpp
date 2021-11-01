#include "../includes/ExprSolver.h"
#include "../includes/tokens.h"

string ExprSolver::solve(const string &expr)
{
  string answer;

  try
  {
    this->parse(expr);
    this->toPostfix();

    answer = this->solvePostfix();
  }
  catch (exception &e)
  {
    answer = "Error.";
  }

  // Clean internal memory
  for (auto pt : this->infixExpr)
    delete pt;

  this->infixExpr.erase(this->infixExpr.begin(), this->infixExpr.end());
  this->postfixExpr.erase(this->postfixExpr.begin(), this->postfixExpr.end());

  return answer;
}

void ExprSolver::toPostfix()
{
  stack<const Token *> temp;

  for (const Token *token : this->infixExpr)
  {
    if (token->isNumber() || token->isMatrix())
      this->postfixExpr.push_back(token);

    else if (token->isSeparator())
    {
      // Find value of the token
      char ch = *dynamic_cast<const Separator *>(token);

      if (ch == '(')
        temp.push(token);

      else if (ch == ')')
      {
        // Take all the tokens out of the stack until you find '('
        while (!temp.empty())
        {
          if (temp.top()->isOperator())
          {
            this->postfixExpr.push_back(temp.top());
            temp.pop();
          }

          else
          {
            temp.pop();
            break;
          }
        }
      }
    }

    else if (token->isOperator())
    {
      // If empty or the top of the stack has '('
      if (temp.empty() || temp.top()->isSeparator())
        temp.push(token);

      else if (*token > *(temp.top()))
        temp.push(token);

      // Current token is not greater than the token on stack
      else if (*token <= *(temp.top()))
      {
        // Take out all the tokens from stack which are equal or higher than current token
        while (!temp.empty() && temp.top()->isOperator() && *token <= *temp.top())
        {
          this->postfixExpr.push_back(temp.top());
          temp.pop();
        }

        temp.push(token);
      }
    }
  }

  // Take out remaining tokens
  while (!temp.empty())
  {
    this->postfixExpr.push_back(temp.top());
    temp.pop();
  }
}