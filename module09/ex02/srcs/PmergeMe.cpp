#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string numbers)
{
    std::istringstream iss(numbers);
    std::string num;

    if (numbers.empty()) {
      throw std::invalid_argument("Error: The given numbers must be non-negative integers.");
    }

    while (iss >> num) {
        if (parseInput(num)) {
            std::istringstream converter(num);
            int number;
            converter >> number;

            this->vector.push_back(number);
            this->list.push_back(number);
        } else {
            this->vector.clear();
            this->list.clear();
            throw std::invalid_argument("Error: The given numbers must be non-negative integers.");
        }
    }
}

PmergeMe::PmergeMe(PmergeMe const & src) { *this = src; }

PmergeMe::~PmergeMe(void) {}

PmergeMe &	PmergeMe::operator=(PmergeMe const & rhs)
{
  this->vector = rhs.vector;
  this->list = rhs.list;
  return (*this);
}

int   PmergeMe::parseInput(std::string num)
{
    if(num.empty()) { return 0; }
    
    for(size_t i = 0; i < num.size(); i++) {
        if(!isdigit(num[i])) {
            return 0;
        }
    }

    long number = atol(num.c_str());
    if((number > INT_MAX || number < INT_MIN) || number <= 0) { return 0; }

    return 1;
}

std::vector<int> PmergeMe::sortVector()
{
  std::vector<int> vec(this->vector);

  for (std::vector<int>::size_type i = 0; i < vec.size()-1; ++i) {
      for (std::vector<int>::size_type j = 0; j < vec.size()-1-i; ++j) {
          if (vec[j] > vec[j+1]) {
              std::swap(vec[j], vec[j+1]);
          }
      }
  }

  return vec;
}

std::list<int> PmergeMe::sortList()
{
  std::list<int> lst(this->list);

  for (std::list<int>::iterator it_i = lst.begin(); it_i != lst.end(); ++it_i) {
      std::list<int>::iterator it_j = it_i;
      ++it_j;

      for (; it_j != lst.end(); ++it_j) {
          if (*it_i > *it_j) {
              std::swap(*it_i, *it_j);
          }
      }
  }

  return lst;
}
