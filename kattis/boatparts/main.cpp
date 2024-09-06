#include <bits/stdc++.h>
#include <unordered_set>

int main()
{
    int numParts, days;
    std::cin >> numParts >> days;

    std::unordered_set<std::string> parts;

    for (int day = 0; day < days; day++)
    {
        std::string part;
        std::cin >> part;

        if (parts.find(part) == parts.end())
        {
            parts.insert(part);
        }

        if (parts.size() == numParts) { std::cout << day + 1 << '\n'; return 0; }
    }

    std::cout << "paradox avoided\n";
}
