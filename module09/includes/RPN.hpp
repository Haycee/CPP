#pragma once

#include <iostream>
#include <stack>

class RPN
{
  public:

    RPN();
    RPN(RPN const & src);
    ~RPN(void);

    RPN &	operator=(RPN const & rhs);
    
    int calculate(std::string const &expression);

		class ParsingException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("The expression can only contain numbers or the four basic arithmetic operators: (+, -, *, /).");
				}
		};

		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("The expression is invalid");
				}
		};

  private:

    std::stack<int> stack;

    int   parseInput(std::string expression);
    int   isOperator(char c) const;
    void  calculateSign(char c);
};