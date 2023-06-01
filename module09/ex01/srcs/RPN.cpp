#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const & src) { *this = src; }

RPN::~RPN(void) {}


RPN &	RPN::operator=(RPN const & rhs)
{
  this->stack = rhs.stack;
  return (*this);
}

int RPN::calculate(std::string const &expression)
{
	if (!this->parseInput(expression))
		throw ParsingException();

  for (size_t i = 0; i < expression.size(); i++)
  {
    if (isOperator(expression[i]))
      calculateSign(expression[i]);
    else if (!isspace(expression[i]))
      this->stack.push(expression[i] - '0');
  }

  if (this->stack.size() != 1)
    throw InvalidExpressionException();

  return (this->stack.top());
}

void RPN::calculateSign(char c)
{
  if (this->stack.size() < 2)
    throw InvalidExpressionException();

  int secondNum = this->stack.top();
  this->stack.pop();
  int firstNum = this->stack.top();
  this->stack.pop();

  switch (c)
  {
  case '+':
    this->stack.push(firstNum + secondNum);
    break;
  case '-':
    this->stack.push(firstNum - secondNum);
    break;
  case '*':
    this->stack.push(firstNum * secondNum);
    break;
  case '/':
    if (secondNum == 0)
      throw InvalidExpressionException();    this->stack.push(firstNum / secondNum);
    break;
  default:
    break;
  }
}

int	RPN::isOperator(char c) const
{
  return (c == '+' || c == '-' || c == '/' || c == '*');
}

int	RPN::parseInput(std::string expression)
{
  if (expression.size() == 0)
    return (0);

  for (size_t i = 0; i < expression.size(); i++)
  {
    if (isdigit(expression[i]))
    {
      continue;
    }
    else
    {
      if (isOperator(expression[i]) || isspace(expression[i]))
      {
        continue;
      }
      else
      {
        return (0);
      }
    }
  }
  return (1);
}