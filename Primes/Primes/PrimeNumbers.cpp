#include "PrimeNumbers.h"

set<int> GeneratePrimeNumbersSet(int upperBound)
{
    set<int> primeNumbersSet;
    vector<bool> numbers((upperBound / 2) + 1, true);

    for (int i = 3; i * i <= upperBound; i += 2)
    {
        if (numbers[i / 2])
        {
            for (int j = i * i; j <= upperBound; j += 2 * i)
            {
                numbers[j / 2] = false;
            }
        }
    }

    if (upperBound >= 2)
        primeNumbersSet.insert(2);

    for (int i = 3; i <= upperBound; i += 2)
    {
        if (numbers[i / 2])
            primeNumbersSet.insert(i);
    }

    return primeNumbersSet;
}
