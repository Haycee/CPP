#pragma once

#include <iostream>
#include <sstream>
#include <list>
#include <vector>

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
    std::vector<int> mergeSortVector(std::vector<int>& vec);
    std::vector<int> mergeVector(const std::vector<int>& left, const std::vector<int>& right);
    std::list<int> mergeList(const std::list<int>& left, const std::list<int>& right);
    std::list<int> mergeSortList(std::list<int>& lst);

};