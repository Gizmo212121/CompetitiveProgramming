#include <bits/stdc++.h>

int main()
{
    std::string num1, num2;
    std::cin >> num1 >> num2;

    int rev1 = 0, rev2 = 0;
    for (int i = 0; i < 3; i++)
    {
        rev1 = rev1 * 10 + num1[2 - i] - '0';
        rev2 = rev2 * 10 + num2[2 - i] - '0';
    }

    if (rev1 > rev2)
    {
        std::cout << rev1 << '\n';
    }
    else
    {
        std::cout << rev2 << '\n';
    }
}
