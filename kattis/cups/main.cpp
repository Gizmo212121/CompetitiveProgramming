#include <bits/stdc++.h>

int main()
{
    int cases;
    std::cin >> cases;

    std::cin.ignore(1, '\n');

    std::vector<std::pair<int, std::string>> cups;
    cups.reserve(cases);

    for (int i = 0; i < cases; i++)
    {
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);

        int radius = 0;
        std::string color = "default";

        if (ss >> radius)
        {
            ss >> color;
        }
        else
        {
            ss.clear();
            ss >> color >> radius;
            radius *= 2;
        }

        cups.push_back({radius, color});
    }

    std::sort(cups.begin(), cups.end(), [](const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) { return lhs.first < rhs.first; });

    for (size_t i = 0; i < cups.size(); i++)
    {
        std::cout << cups[i].second << '\n';
    }
}
