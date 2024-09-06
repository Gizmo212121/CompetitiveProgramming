#include <bits/stdc++.h>

int main()
{
    long long int x, y;

    while (scanf("%lld %lld", &x, &y) == 0)
    {
        printf("%lld\n", llabs(x - y));
    }
}
