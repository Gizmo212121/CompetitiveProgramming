#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;

    int ppr = m / n;
    int left = m % n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ppr + (left > 0); j++)
        {
            std::cout << '*';
        }

        std::cout << '\n';

        if (left > 0) { left--; }
    }
}
