#include <bits/stdc++.h>

const long double SQRT_2 = pow(2, 1.0 / 2);
const long double INIT_PAPER_LENGTH = pow(2, - 3.0 / 4);
const int MAX_N = 30;

int main()
{
    int n;
    std::cin >> n;

    long long conversion_count[MAX_N - 1];
    std::fill(conversion_count, conversion_count + MAX_N - 1, 0);
    long long paper_count[MAX_N - 1];

    for (int i = 0; i < n - 1; i++)
    {
        long long num_paper;
        std::cin >> num_paper;
        paper_count[i] = num_paper;
    }

    bool possible = false;
    long long paper_needed = 2;
    int i = 0;
    while (i < n - 1)
    {
        if (paper_needed - paper_count[i] <= 0) { possible = true; break; }

        paper_needed -= paper_count[i];
        paper_needed *= 2;

        i++;
    }

    if (!possible) { std::cout << "impossible\n"; return 0; }

    paper_count[i - 1] += paper_needed / 2;
    conversion_count[i] = paper_needed / 2;
    for (int j = i - 1; j > 0; j--)
    {
        paper_count[j - 1] += paper_count[j] / 2;
        conversion_count[j] = paper_count[j] / 2;
    }
    conversion_count[0] = 1;

    long double total_tape_length = 0;
    for (int i = 0 ; i < n - 1; i++)
    {
        total_tape_length += conversion_count[i] * INIT_PAPER_LENGTH / pow(SQRT_2, i);
    }

    printf("%.8Lf\n", total_tape_length);
}
