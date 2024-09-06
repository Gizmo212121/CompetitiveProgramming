#include <bits/stdc++.h>

int main()
{
    int firstSum = 0;
    for (int i = 0; i < 4; i++)
    {
        int input;
        std::cin >> input;

        firstSum += input;
    }

    int secondSum = 0;
    for (int i = 0; i < 4; i++)
    {
        int input;
        std::cin >> input;

        if ((secondSum += input) > firstSum)
        {
            std::cout << "Emma\n";
            return 0;
        }
    }

    if (secondSum == firstSum)
    {
        std::cout << "Tie\n";
    }
    else
    {
        std::cout << "Gunnar\n";
    }
}
