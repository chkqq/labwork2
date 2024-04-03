#include <iostream>
#include <string>
#include <cstdlib> 
#include "PrimeNumbers.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <upper_bound>" << std::endl;
        return 1;
    }

    int upperBound;
    try
    {
        upperBound = std::atoi(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Invalid upper bound: " << e.what() << std::endl;
        return 1;
    }

    if (upperBound <= 1)
    {
        std::cerr << "Upper bound must be greater than 1" << std::endl;
        return 1;
    }

    if (upperBound > 100000000)
    {
        std::cerr << "Upper bound is too big" << std::endl;
        return 1;
    }

    std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);

    std::cout << "Prime numbers up to " << upperBound << ":" << std::endl;
    std::cout << "Total prime numbers found: " << primeNumbers.size() << std::endl;
    for (int prime : primeNumbers)
    {
        std::cout << prime << std::endl;
    }

    return 0;
}
