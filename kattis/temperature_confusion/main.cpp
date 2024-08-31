#include <bits/stdc++.h>
#include <numeric>

int main()
{
    int topF;
    char slash;
    int bottomF;

    std::cin >> topF >> slash >> bottomF;

    int topC, bottomC;
    topC = 5 * topF - 160 * bottomF;
    bottomC = 9 * bottomF;

    int greatestDivisor = std::gcd(topC, bottomC);

    std::cout << topC / greatestDivisor << '/' << bottomC / greatestDivisor << '\n';
}
