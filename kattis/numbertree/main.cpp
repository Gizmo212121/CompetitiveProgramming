// https://open.kattis.com/problems/numbertree
#include <bits/stdc++.h>
#include <cstdio>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);
    std::istringstream is(line);

    int h;
    is >> h;

    char direction;
    int index = 0;
    int treesize = pow(2, h + 1) - 1;

    while (is >> direction)
    {
        if (direction == 'L')
        {
            index = 2 * index + 1;
        }
        else
        {
            index = 2 * (index + 1);
        }
    }

    std::cout << treesize - index << '\n';
}
