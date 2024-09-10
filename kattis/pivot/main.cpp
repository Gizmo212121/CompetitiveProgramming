#include <bits/stdc++.h>
#include <cstdio>

const int MAX_VALUES = 100000;

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
    int n = get_input_fast();

    int values[MAX_VALUES];
    std::bitset<MAX_VALUES> candidates;

    int max_value = 0;
    int number_of_candidates = 0;

    for (int i = 0; i < n; i++)
    {
        int input = get_input_fast();

        values[i] = input;

        if (input >= max_value)
        {
            number_of_candidates++;
            candidates[i] = true;
        }

        max_value = std::max(max_value, input);
    }

    int min_value = values[n - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        if (values[i] > min_value && candidates[i])
        {
            number_of_candidates--;
        }

        min_value = std::min(min_value, values[i]);
    }

    printf("%d\n", number_of_candidates);
}
