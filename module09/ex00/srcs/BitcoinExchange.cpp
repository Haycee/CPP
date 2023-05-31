#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
  if (!loadData()) throw DataException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
  *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
  this->_dateExchangeRate = rhs._dateExchangeRate;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadData()
{
  std::ifstream file("data.csv");
  std::string line;
  std::string date;
  std::string exchangeRate;

  if (!file.is_open()) return false;

  getline(file, line);

  while (getline(file, line))
  {
    std::stringstream ss(line);
    getline(ss, date, ',');
    getline(ss, exchangeRate);
    this->_dateExchangeRate[date] = std::atof(exchangeRate.c_str());
  }
  file.close();
  return true;
}

void BitcoinExchange::calculate(const std::string &filename)
{
  std::ifstream file(filename);
  std::string line;
  std::string date;
  std::string value;

  if (!file.is_open()) throw InputException();

  getline(file, line);
  while (getline(file, line))
  {
    if (!parseLine(line)) {
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }

    std::stringstream ss(line);
    getline(ss, date, '|');
    getline(ss, value);
    date = date.substr(0, date.size()-1);
    value = value.substr(1);

    try {
      parseDate(date);
      parseValue(value);
      std::cout << date << " => " << value << " = " << this->_dateExchangeRate[getExchangeRate(date)] * std::atof(value.c_str()) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  file.close();
}

int BitcoinExchange::maxDayInMonth(int year, int month) const {
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      return 29;
    } else {
      return 28;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}

std::string BitcoinExchange::getExchangeRate(const std::string &date)
{
  int year;
  int month;
  int day;

  size_t firstHyphen = date.find_first_of('-');
  size_t secondHyphen = date.find_first_of('-', firstHyphen + 1);


  std::stringstream ssYear(date.substr(0, firstHyphen));
  ssYear >> year;
  std::stringstream ssMonth(date.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1));
  ssMonth >> month;
  std::stringstream ssDay(date.substr(secondHyphen + 1));
  ssDay >> day;

  for (;year > 0; year--) {
    for (;month > 0; month--) {
      int maxDay = maxDayInMonth(year, month);

      for (;day > 0; day--) {
        if (day > maxDay) {
          continue;
        }
        std::stringstream ss;
        ss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
        if (this->_dateExchangeRate.find(ss.str()) != this->_dateExchangeRate.end()) {
          return ss.str();
        }
      }

      day = maxDayInMonth(year, month - 1);
    }
    month = 12;
  }
  return "0";
}

bool BitcoinExchange::parseLine(const std::string &line) const
{
  std::size_t pos = line.find('|');

  if (pos == std::string::npos || line.find('|', pos+1) != std::string::npos) return false;
  if (pos == 0 || pos == line.size() - 1) return false;
  if (line[pos-1] != ' ' || line[pos+1] != ' ') return false;
  if (pos == 1 || pos == line.size() - 2) return false;
  return true;
}

void BitcoinExchange::parseDate(const std::string &date) const
{
  int year;
  int month;
  int day;

  for (size_t i = 0; i < date.length(); i++) {
      if (!isdigit(date[i]) && date[i] != '-') throw InvalidDateException();
  }
  size_t firstHyphen = date.find_first_of('-');
  size_t secondHyphen = date.find_first_of('-', firstHyphen + 1);

  if (secondHyphen == std::string::npos) throw InvalidDateException();

  std::stringstream ssYear(date.substr(0, firstHyphen));
  ssYear >> year;
  std::stringstream ssMonth(date.substr(firstHyphen + 1, secondHyphen - firstHyphen - 1));
  ssMonth >> month;
  std::stringstream ssDay(date.substr(secondHyphen + 1));
  ssDay >> day;

  if (ssYear.str().length() != 4 || year < 0) throw InvalidDateException();
  if (ssMonth.str().length() != 2 || month > 12 || month < 1) throw InvalidDateException();
  if (ssDay.str().length() != 2 || day < 1 || day > maxDayInMonth(year, month)) throw InvalidDateException();
}


void BitcoinExchange::parseValue(const std::string &value) const
{
  double val;

  for (size_t i = 0; i < value.length(); i++) {
      if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-') throw InvalidValueException();
  }
  val = std::atof(value.c_str());
  if (val < 0) throw NegValueException();
  if (val > 1000) throw MaxValueException();
}
