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
    
    void insertionSortVector(std::vector<int>& vec, int left, int right);
    void mergeVector(std::vector<int>& vec, int left, int mid, int right);
    void mergeInsertionSortVector(std::vector<int>& vec, int left, int right);

    void insertionSortList(std::list<int>& lst);
    std::list<int> mergList(const std::list<int>& left, const std::list<int>& right);
    std::list<int> mergeInsertionSortList(std::list<int>& lst);
};