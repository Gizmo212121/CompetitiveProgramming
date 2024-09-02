#include <cstdio>
#include <vector>
#include <iostream>

void printRecursively(std::vector<std::vector<int>>& v, std::vector<std::string>& s, int idx)
{
    std::cout << s[idx];
    for(int i : v[idx])
    {
        printRecursively(v, s, i);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::string> strings;
    std::vector<std::vector<int>> args;
    strings.resize(n);
    args.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> strings[i];
    }

    int lastIndex = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int c1, c2;
        std::cin >> c1 >> c2;
        c1--; c2--;

        args[c1].push_back(c2);

        lastIndex = c1;
    }


    printRecursively(args, strings, lastIndex);
    std::cout << '\n';
}
