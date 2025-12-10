#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

public:
    ~PmergeMe();
    static void sort(int argc, char **argv);
};

#endif