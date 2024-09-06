#include <bits/stdc++.h>

int main()
{
    unsigned long long n;
    std::cin >> n;

    std::vector<bool> reversedInt;
    reversedInt.reserve(sizeof(unsigned long long));

    while (n >= 1)
    {
        if ((n & 1) == 1)
        {
            reversedInt.push_back(true);
        }
        else
        {
            reversedInt.push_back(false);
        }

        n = n >> 1;
    }

    unsigned long long resultingInt = 0;

    for (size_t i = 0; i < reversedInt.size(); i++)
    {
        if (reversedInt[i])
        {
            resultingInt |= (1LL << (reversedInt.size() - i - 1));
        }
    }

    std::cout << resultingInt << '\n';
}
