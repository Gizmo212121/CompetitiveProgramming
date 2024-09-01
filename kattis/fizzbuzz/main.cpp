#include <bits/stdc++.h>

int main()
{
    int x, y, n;
    std::cin >> x >> y >> n;

    for (int i = 1; i <= n; i++)
    {
        int f = i % x;
        int b = i % y;

        if (f == 0 && b == 0)
        {
            std::cout << "FizzBuzz\n";
        }
        else if (f == 0)
        {
            std::cout << "Fizz\n";
        }
        else if (b == 0)
        {
            std::cout << "Buzz\n";
        }
        else
        {
            std::cout << i << '\n';
        }
    }
}
