#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string numbers) {
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

int   PmergeMe::parseInput(std::string num) {
    if(num.empty()) { return 0; }
    
    for(size_t i = 0; i < num.size(); i++) {
        if(!isdigit(num[i])) {
            return 0;
        }
    }

    long number = atol(num.c_str());
    if((number > INT_MAX || number < INT_MIN) || number < 0) { return 0; }

    return 1;
}

void PmergeMe::insertionSortList(std::list<int>& lst) {
    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i) {
        std::list<int>::iterator j = i;
        j++;
        while (j != lst.end()) {
            if (*i > *j) {
                std::swap(*i, *j);
            }
            j++;
        }
    }
}

std::list<int> PmergeMe::mergList(const std::list<int>& left, const std::list<int>& right) {
    std::list<int> result;
    std::list<int>::const_iterator left_it = left.begin(), right_it = right.begin();

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            result.push_back(*left_it);
            ++left_it;
        }
        else {
            result.push_back(*right_it);
            ++right_it;
        }
    }

    while (left_it != left.end()) {
        result.push_back(*left_it);
        ++left_it;
    }

    while (right_it != right.end()) {
        result.push_back(*right_it);
        ++right_it;
    }

    return result;
}

std::list<int> PmergeMe::mergeInsertionSortList(std::list<int>& lst) {
    if (lst.size() <= 10) {
        insertionSortList(lst);
        return lst;
    }

    std::list<int> left, right, result;
    std::list<int>::iterator middle = lst.begin();

    std::advance(middle, lst.size() / 2);
    std::copy(lst.begin(), middle, std::back_inserter(left));
    std::copy(middle, lst.end(), std::back_inserter(right));

    left = mergeInsertionSortList(left);
    right = mergeInsertionSortList(right);
    result = mergList(left, right);

    return result;
}


std::list<int> PmergeMe::sortList()
{
    std::list<int> lst(this->list);
    return mergeInsertionSortList(lst);
}


void PmergeMe::insertionSortVector(std::vector<int>& vec) {
    for (std::vector<int>::iterator i = vec.begin() + 1; i != vec.end(); ++i) {
        int key = *i;
        std::vector<int>::iterator j = i - 1;
        while (j >= vec.begin() && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}


std::vector<int> PmergeMe::mergeVector(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;

    std::vector<int>::const_iterator it_left = left.begin();
    std::vector<int>::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left <= *it_right) {
            result.push_back(*it_left++);
        } else {
            result.push_back(*it_right++);
        }
    }

    while (it_left != left.end()) {
        result.push_back(*it_left++);
    }

    while (it_right != right.end()) {
        result.push_back(*it_right++);
    }

    return result;
}


std::vector<int> PmergeMe::mergeInsertionSortVector(std::vector<int>& vec) {
    if (vec.size() <= 10) {
        insertionSortVector(vec);
        return vec;
    }

    std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    left = mergeInsertionSortVector(left);
    right = mergeInsertionSortVector(right);

    return mergeVector(left, right);
}

std::vector<int> PmergeMe::sortVector() {
    std::vector<int> vec(this->vector);
    return mergeInsertionSortVector(vec);
}


