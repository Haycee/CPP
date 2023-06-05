#include "../includes/PmergeMe.hpp"
#include <ctime>

void printVector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void printList(const std::list<int>& lst) {
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cout << "Usage: ./pmergeMe \"1 3 4 2 5\"" << std::endl;
    return 1;
  }

  try {

    std::string numbers;
    for(int i = 1; i < argc; i++) {
        if(i != 1)
            numbers += " ";
        numbers += argv[i];
    }

    PmergeMe pmergeMe(numbers);

    std::cout << "Before: ";
    printVector(pmergeMe.getVector());
    clock_t beginVector = clock();
    std::vector<int> sorted_vector = pmergeMe.sortVector();
    clock_t endVector = clock();
    double elapsedSecsVector = double(endVector - beginVector) / double(CLOCKS_PER_SEC);
    std::cout << "After: ";
    printVector(sorted_vector);
    std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector : " << elapsedSecsVector << " seconds" << std::endl;

    clock_t beginList = clock();
    std::list<int> sorted_list = pmergeMe.sortList();
    clock_t endList = clock();
    double elapsedSecsList = double(endList - beginList) / double(CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << pmergeMe.getList().size() << " elements with std::list : " << elapsedSecsList << " seconds" << std::endl;

  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}