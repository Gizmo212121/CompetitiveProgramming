#include <bits/stdc++.h>

int main()
{
    int n, p, q;
    std::cin >> n >> p >> q;

    if ((p + q) / n % 2 == 0)
    {
        std::cout << "paul\n";
    }
    else
    {
        std::cout << "opponent\n";
    }
}
