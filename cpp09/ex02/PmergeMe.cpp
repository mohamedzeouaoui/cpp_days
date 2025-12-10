#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <sys/time.h>

// Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171...
static size_t jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t result = 1;

    for (size_t i = 2; i <= n; i++)
    {
        result = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = result;
    }
    return result;
}

// Binary insertion: insert element into sorted portion using binary search
template <typename Container>
void binaryInsert(typename Container::value_type value, Container &container, size_t limit)
{
    size_t left = 0;
    size_t right = limit;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (container[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    container.insert(container.begin() + left, value);
}

// Merge-Insertion Sort for vector<int>
static void mergeInsertionSort(std::vector<int> &d)
{
    size_t n = d.size();

    if (n <= 1)
        return;

    // Step 1: Group elements into pairs and compare
    std::vector<int> a; // larger elements
    std::vector<int> b; // smaller elements

    // Pair consecutive elements: (d[0],d[1]), (d[2],d[3]), etc.
    for (size_t i = 0; i < n / 2; i++)
    {
        if (d[2 * i] > d[2 * i + 1])
        {
            a.push_back(d[2 * i]);
            b.push_back(d[2 * i + 1]);
        }
        else
        {
            a.push_back(d[2 * i + 1]);
            b.push_back(d[2 * i]);
        }
    }

    // Handle odd element (straggler)
    int straggler = 0;
    bool hasStraggler = (n % 2 == 1);
    if (hasStraggler)
        straggler = d[n - 1];

    // Step 2: Recursively sort the larger elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < a.size(); i++)
        pairs.push_back(std::make_pair(a[i], b[i]));

    if (a.size() > 1)
        mergeInsertionSort(a);

    // Step 3: Permute b to match sorted a
    std::vector<int> b_sorted;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == a[i])
            {
                b_sorted.push_back(pairs[j].second);
                break;
            }
        }
    }
    b = b_sorted;

    // Step 4: Build initial sequence S = (b[0], a[0], a[1], ..., a[n/2-1])
    d.clear();
    if (!b.empty())
        d.push_back(b[0]); // Insert b[0] at the start

    for (size_t i = 0; i < a.size(); i++)
        d.push_back(a[i]);

    // Step 5: Insert remaining b elements using Jacobsthal sequence
    if (b.size() <= 1 && !hasStraggler)
        return;

    // Generate Jacobsthal-based insertion order
    std::vector<size_t> insertionOrder;

    size_t k = 3;
    size_t pos = 1; // Position in b array (b[0] already inserted)

    while (pos < b.size())
    {
        size_t jacob = jacobsthal(k);
        size_t limit = std::min(jacob, b.size() - 1);

        // Insert from limit down to pos
        for (size_t i = limit; i >= pos && i > 0; i--)
        {
            insertionOrder.push_back(i);
            if (i == pos)
                break;
        }

        pos = limit + 1;
        k++;
    }

    // Insert straggler at the end if it exists
    if (hasStraggler)
        insertionOrder.push_back(b.size()); // Special index for straggler

    // Perform insertions
    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t idx = insertionOrder[i];

        if (idx == b.size()) // Straggler
        {
            // Binary search in entire d
            binaryInsert(straggler, d, d.size());
        }
        else
        {
            // Find position of a[idx] in d to limit search
            size_t searchLimit = d.size();
            for (size_t j = 0; j < d.size(); j++)
            {
                if (d[j] == a[idx])
                {
                    searchLimit = j;
                    break;
                }
            }

            // Binary insert b[idx] into d[0..searchLimit-1]
            binaryInsert(b[idx], d, searchLimit);
        }
    }
}

// Merge-Insertion Sort for deque<int>
static void mergeInsertionSort(std::deque<int> &d)
{
    size_t n = d.size();

    if (n <= 1)
        return;

    // Step 1: Group elements into pairs and compare
    std::deque<int> a; // larger elements
    std::deque<int> b; // smaller elements

    // Pair consecutive elements: (d[0],d[1]), (d[2],d[3]), etc.
    for (size_t i = 0; i < n / 2; i++)
    {
        if (d[2 * i] > d[2 * i + 1])
        {
            a.push_back(d[2 * i]);
            b.push_back(d[2 * i + 1]);
        }
        else
        {
            a.push_back(d[2 * i + 1]);
            b.push_back(d[2 * i]);
        }
    }

    // Handle odd element (straggler)
    int straggler = 0;
    bool hasStraggler = (n % 2 == 1);
    if (hasStraggler)
        straggler = d[n - 1];

    // Step 2: Recursively sort the larger elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < a.size(); i++)
        pairs.push_back(std::make_pair(a[i], b[i]));

    if (a.size() > 1)
        mergeInsertionSort(a);

    // Step 3: Permute b to match sorted a
    std::deque<int> b_sorted;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == a[i])
            {
                b_sorted.push_back(pairs[j].second);
                break;
            }
        }
    }
    b = b_sorted;

    // Step 4: Build initial sequence S = (b[0], a[0], a[1], ..., a[n/2-1])
    d.clear();
    if (!b.empty())
        d.push_back(b[0]);

    for (size_t i = 0; i < a.size(); i++)
        d.push_back(a[i]);

    // Step 5: Insert remaining b elements using Jacobsthal sequence
    if (b.size() <= 1 && !hasStraggler)
        return;

    // Generate Jacobsthal-based insertion order
    std::vector<size_t> insertionOrder;

    size_t k = 3;
    size_t pos = 1;

    while (pos < b.size())
    {
        size_t jacob = jacobsthal(k);
        size_t limit = std::min(jacob, b.size() - 1);

        for (size_t i = limit; i >= pos && i > 0; i--)
        {
            insertionOrder.push_back(i);
            if (i == pos)
                break;
        }

        pos = limit + 1;
        k++;
    }

    if (hasStraggler)
        insertionOrder.push_back(b.size());

    // Perform insertions
    for (size_t i = 0; i < insertionOrder.size(); i++)
    {
        size_t idx = insertionOrder[i];

        if (idx == b.size()) // Straggler
        {
            binaryInsert(straggler, d, d.size());
        }
        else
        {
            size_t searchLimit = d.size();
            for (size_t j = 0; j < d.size(); j++)
            {
                if (d[j] == a[idx])
                {
                    searchLimit = j;
                    break;
                }
            }

            binaryInsert(b[idx], d, searchLimit);
        }
    }
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

static double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::sort(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    // Parse and validate input
    for (int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        int num;

        if (!(ss >> num) || !ss.eof() || num < 0)
        {
            std::cerr << "Error" << std::endl;
            return;
        }

        vec.push_back(num);
        deq.push_back(num);
    }

    // Print before
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
        if (i > 4)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;

    // Sort with vector
    double start_vec = getTime();
    mergeInsertionSort(vec);
    double end_vec = getTime();

    // Sort with deque
    double start_deq = getTime();
    mergeInsertionSort(deq);
    double end_deq = getTime();

    // Print after
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
        if (i > 100)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;

    // Print timing
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : "
              << (end_vec - start_vec) << " us" << std::endl;

    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : "
              << (end_deq - start_deq) << " us" << std::endl;

    for (size_t k = 0; k < vec.size(); k++ )
    {
        if (k >0 && vec[k] < vec[k-1])
        {
            std::cout << "error in sort" << std::endl;
        }
        else if (k == vec.size()-1)
        {
            std::cout << "all good in vec" << std::endl;
        }
    }

        for (size_t k = 0; k < deq.size(); k++ )
    {
        if (k >0 && deq[k] < deq[k-1])
        {
            std::cout << "error in sort" << std::endl;
            break;
        }
        else if (k == deq.size()-1)
        {
            std::cout << "all good in deque" << std::endl;
        }
    }
    
}