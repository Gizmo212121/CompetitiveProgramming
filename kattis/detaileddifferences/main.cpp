#include <bits/stdc++.h>

int main()
{
    int cases;
    std::cin >> cases;

    std::cin.ignore(1, '\n');

    for (int i = 0; i < cases; i++)
    {
        std::string input1, input2;

        std::getline(std::cin, input1);
        std::getline(std::cin, input2);

        std::cout << input1 << '\n' << input2 << '\n';

        for (size_t j = 0; j < input1.size(); j++)
        {
            if (input1[j] == input2[j])
            {
                std::cout << '.';
            }
            else
            {
                std::cout << '*';
            }
        }

        std::cout << '\n';
    }
}
