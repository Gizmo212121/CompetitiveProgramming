#include <bits/stdc++.h>

int main()
{
    std::unordered_set<int> us;

    for (int i = 0; i < 10; i++)
    {
        int input;
        std::cin >> input;

        int result = input % 42;

        if (us.find(result) == us.end())
        {
            us.insert(result);
        }
    }

    std::cout << us.size() << '\n';
}
