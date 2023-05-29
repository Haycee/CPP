#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

		class DataException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Could not open data.csv");
				}
		};

    class InputException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Could not open input file");
				}
		};

    class NegValueException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};

    class MaxValueException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Error: too large a number.");
				}
		};

    class InvalidValueException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Error: value is invalid");
				}
		};

    class InvalidDateException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Error: date is invalid");
				}
		};

    void calculate(const std::string &filename);

  private:
    std::map<std::string, float> _dateExchangeRate;

    bool loadData();
    std::string getExchangeRate(const std::string &date);
    bool parseLine(const std::string &line) const;
    void parseDate(const std::string &date) const;
    void parseValue(const std::string &value) const;
    int maxDayInMonth(int year, int month) const;
};