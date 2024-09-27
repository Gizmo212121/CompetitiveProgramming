#include <algorithm>
#include <bits/stdc++.h>

int main()
{
    int input;
    std::cin >> input;
    int inputCopy = input;


    std::vector<int> digits;
    int numberOfDigits = floor(log10(input) + 1);
    digits.resize(numberOfDigits);
    for (int i = numberOfDigits - 1; i >= 0; i--)
    {
        digits[i] = input % 10; 
        input /= 10;
    }

    std::sort(digits.begin(), digits.end());

    do
    {
        int permutation = 0;
        for (int i = 0; i < numberOfDigits; i++)
        {
            permutation = permutation * 10 + digits[i];
        }
        if (permutation > inputCopy)
        {
            std::cout << permutation << '\n';
            return 0;
        }
    }
    while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << '0' << std::endl;
}
