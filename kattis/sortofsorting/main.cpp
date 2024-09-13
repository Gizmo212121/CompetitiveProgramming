#include <bits/stdc++.h>

int main()
{
    int n;
    while ((std::cin >> n, n) != 0)
    {
        std::vector<std::string> names(n);
        for (int i = 0; i < n; i++)
        {
            std::string name;
            std::cin >> name;
            names[i] = name;
        }

        std::stable_sort(names.begin(), names.end(), [](const std::string& n1, const std::string& n2)
                {
                    if (n1[0] < n2[0]) { return true; }
                    else if (n1[0] > n2[0]) { return false; }
                    else
                    {
                        return n1[1] < n2[1];
                    }
                    });

        for (int i = 0; i < n; i++)
        {
            std::cout << names[i] << '\n';
        }
        std::cout << std::endl;
    }
}
