#include <bits/stdc++.h>

int main()
{
    int card1, card2;
    std::cin >> card1 >> card2;

    char inputs[4];
    for (int i = 0; i < 4; i++)
    {
        std::cin >> inputs[i];
    }

    for (int i = 0; i < 4; i++)
    {
        if (inputs[i] == 'A')
        {
            if (inputs[i + 1] == 'A')
            {
                if (i == 0)
                {
                    if (card2 == 7)
                    {
                        std::cout << 8 << ' ' << 9 << '\n';
                        return 0;
                    }
                }
                else if (i == 1)
                {
                    if (card1 == 2 && card2 == 8)
                    {
                        std::cout << 1 << ' ' << 9 << '\n';
                        return 0;
                    }
                }
                else
                {
                    if (card1 == 3)
                    {
                        std::cout << 1 << ' ' << 2 << '\n';
                        return 0;
                    }
                }
            }
            else if (inputs[i + 2] == 'A')
            {
                if (i == 0)
                {
                    if (card2 == 8 && card1 == 6)
                    {
                        std::cout << 7 << ' ' << 9 << '\n';
                        return 0;
                    }
                }
                else
                {
                    if (card1 == 2 && card2 == 4)
                    {
                        std::cout << 1 << ' ' << 3 << '\n';
                        return 0;
                    }
                }
            }
            else
            {
                if (card2 - card1 == 3)
                {
                    std::cout << card1 + 1 << ' ' << card1 + 2 << '\n';
                    return 0;
                }
            }

            break;
        }
    }

    std::cout << -1 << '\n';
}
