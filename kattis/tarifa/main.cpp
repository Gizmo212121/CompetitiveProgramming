#include <bits/stdc++.h>

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);

        sum += x - input;
    }

    std::cout << sum + x << '\n';
}
