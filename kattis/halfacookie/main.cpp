#include <bits/stdc++.h>

int main()
{
    double r = 0, x = 0, y = 0;
    while (std::cin >> r)
    {
        std::cin >> x >> y;

        if (pow(x, 2) + pow(y, 2) > pow(r, 2))
        {
            std::cout << "miss\n";
            continue;
        }

        double r_prime = sqrt(pow(x, 2) + pow(y, 2));
        double theta = acos(r_prime / r);

        double A = pow(r, 2) * theta - sqrt(pow(r, 2) - pow(r_prime, 2)) * r_prime;
        double A_prime = M_PI * pow(r, 2) - A;

        std::cout << A_prime << ' ' << A << '\n';
    }
}
