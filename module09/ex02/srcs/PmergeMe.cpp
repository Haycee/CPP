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
    if((number > INT_MAX || number < INT_MIN) || number < 0) { return 0; }

    return 1;
}

void PmergeMe::insertionSortList(std::list<int>& lst)
{
    if (lst.empty())
        return;

    std::list<int>::iterator i = lst.begin();
    ++i;

    while (i != lst.end())
    {
        std::list<int>::iterator j = i;
        --j;

        while (true)
        {
            if (*i < *j)
            {
                std::swap(*i, *j);
                if (j != lst.begin())
                    --j;
            }
            else
                break;
        }

        ++i;
    }
}

std::list<int> PmergeMe::mergList(const std::list<int>& left, const std::list<int>& right)
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

std::list<int> PmergeMe::mergeInsertionSortList(std::list<int>& lst)
{
    if (lst.size() <= 10)  
    {
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


void PmergeMe::insertionSortVector(std::vector<int>& vec, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    std::vector<int> temp;
    
    while (i <= mid && j <= right) {
        if (vec[i] <= vec[j]) {
            temp.push_back(vec[i]);
            i++;
        } else {
            temp.push_back(vec[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        temp.push_back(vec[i]);
        i++;
    }
    
    while (j <= right) {
        temp.push_back(vec[j]);
        j++;
    }
    
    for (i = left; i <= right; i++) {
        vec[i] = temp[i - left];
    }
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& vec, int left, int right) {
    if (right - left <= 10) {  
        insertionSortVector(vec, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertionSortVector(vec, left, mid);
    mergeInsertionSortVector(vec, mid + 1, right);
    mergeVector(vec, left, mid, right);
}

std::vector<int> PmergeMe::sortVector() {
    std::vector<int> vec(this->vector);
    mergeInsertionSortVector(vec, 0, vec.size() - 1);
    return vec;
}


