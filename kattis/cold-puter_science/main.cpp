#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        if (input < 0) { ct++; }
    }

    std::cout << ct << '\n';
}
