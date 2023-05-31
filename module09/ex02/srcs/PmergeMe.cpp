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

std::vector<int> PmergeMe::mergeVector(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> result;
    std::vector<int>::const_iterator left_it = left.begin(), right_it = right.begin();

    while (left_it != left.end() && right_it != right.end())
    {
        if (*left_it <= *right_it)
        {
            result.push_back(*left_it);
            ++left_it;
        }
        else
        {
            result.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end())
    {
        result.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end())
    {
        result.push_back(*right_it);
        ++right_it;
    }

    return result;
}

std::vector<int> PmergeMe::mergeSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return vec;

    std::vector<int> left, right, result;
    std::vector<int>::iterator middle = vec.begin();

    std::advance(middle, vec.size() / 2);
    std::copy(vec.begin(), middle, std::back_inserter(left));
    std::copy(middle, vec.end(), std::back_inserter(right));

    left = mergeSortVector(left);
    right = mergeSortVector(right);
    result = mergeVector(left, right);

    return result;
}

std::vector<int> PmergeMe::sortVector()
{
    std::vector<int> vec(this->vector);
    return mergeSortVector(vec);
}

std::list<int> PmergeMe::sortList()
{
    std::list<int> lst(this->list);
    return mergeSortList(lst);
}

std::list<int> PmergeMe::mergeList(const std::list<int>& left, const std::list<int>& right)
{
    std::list<int> result;
    std::list<int>::const_iterator left_it = left.begin(), right_it = right.begin();

    while (left_it != left.end() && right_it != right.end())
    {
        if (*left_it <= *right_it)
        {
            result.push_back(*left_it);
            ++left_it;
        }
        else
        {
            result.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end())
    {
        result.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end())
    {
        result.push_back(*right_it);
        ++right_it;
    }

    return result;
}

std::list<int> PmergeMe::mergeSortList(std::list<int>& lst)
{
    if (lst.size() <= 1)
        return lst;

    std::list<int> left, right, result;
    std::list<int>::iterator middle = lst.begin();

    std::advance(middle, lst.size() / 2);
    std::copy(lst.begin(), middle, std::back_inserter(left));
    std::copy(middle, lst.end(), std::back_inserter(right));

    left = mergeSortList(left);
    right = mergeSortList(right);
    result = mergeList(left, right);

    return result;
}