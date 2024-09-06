#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    int counter = 1;
    int days = 0;
    while (counter < n)
    {
        days++;
        counter *= 2;
    }

    std::cout << ++days << '\n';
}
