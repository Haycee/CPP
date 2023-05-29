#include "../includes/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: ./btc [filename]" << std::endl;
    return 1;
  }

  try
  {
    BitcoinExchange exchange;
    exchange.calculate(argv[1]);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}