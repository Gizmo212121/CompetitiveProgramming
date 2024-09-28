#include <bits/stdc++.h>
#include <limits>

int main()
{
    int cases = 1;
    int inputs;
    while (std::cin >> inputs)
    {
        int input;
        int max = - std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::max();

        for (int i = 0; i < inputs; i++)
        {
            std::cin >> input;
            max = std::max(max, input);
            min = std::min(min, input);
        }

        std::cout << "Case " << cases++ << ": ";
        std::cout << min << ' ' << max << ' ' << max - min << '\n';
    }
}
