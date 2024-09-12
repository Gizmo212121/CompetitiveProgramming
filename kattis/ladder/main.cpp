#include <bits/stdc++.h>

int main()
{
    int h, v;
    std::cin >> h >> v;

    std::cout << ceil(h / sin(v * M_PI / 180.0));
}
