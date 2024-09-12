#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        float b, p;
        std::cin >> b >> p;

        std::cout << 60.0 * (b - 1) / p << ' ' << 60 * b / p << ' ' << 60 * (b + 1) / p << '\n';
    }
}
