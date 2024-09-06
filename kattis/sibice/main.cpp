#include <bits/stdc++.h>

int main()
{
    int n, w, h;
    std::cin >> n >> w >> h;

    double longestFittingMatch = sqrt(pow(w, 2) + pow(h, 2));

    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;

        if (input > longestFittingMatch)
        {
            std::cout << "NE\n";
        }
        else
        {
            std::cout << "DA\n";
        }
    }
}
