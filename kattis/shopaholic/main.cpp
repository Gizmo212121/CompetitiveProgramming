#include <bits/stdc++.h>

int get_input_fast()
{
    int output = 0;
    while (true)
    {
        char char_input = getchar_unlocked();
        if (char_input == ' ' || char_input == '\n') { break; }

        output = output * 10 + char_input - '0';
    }

    return output;
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<int> items(n);

    getchar_unlocked();
    for (int i = 0; i < n; i++)
    {
        int input = get_input_fast();
        items.push_back(input);
    }

    std::sort(items.begin(), items.end(), std::greater<>());

    long long discount = 0;

    for (int i = 0; i < n; i += 3)
    {
        discount += items[i + 2];
    }

    printf("%lli\n", discount);
}
