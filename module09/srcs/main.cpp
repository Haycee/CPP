#include "../includes/RPN.hpp"

int main(int argc, char *argv[])
{
  RPN calculator;

	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"expression\"" << std::endl;
		return (0);
	}

	try
	{
		std::cout << calculator.calculate(argv[1]) << std::endl;
	}
	catch (RPN::ParsingException &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
  catch (RPN::InvalidExpressionException &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

  return (0);
}