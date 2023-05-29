#pragma once

#include <iostream>
#include <sstream>
#include <list>

class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(std::string numbers);
    PmergeMe(PmergeMe const & src);
    ~PmergeMe(void);

    PmergeMe &	operator=(PmergeMe const & rhs);

    std::vector<int> getVector(void) const { return this->vector; }
    std::list<int> getList(void) const { return this->list; }

    std::vector<int> sortVector();
    std::list<int> sortList();

  private:
    std::vector<int>  vector;
    std::list<int> list;


    int   parseInput(std::string expression);
};