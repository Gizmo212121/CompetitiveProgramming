// https://open.kattis.com/problems/annoyedcoworkers
#include <bits/stdc++.h>
#include <utility>

int main()
{
    int h, c;
    scanf("%d %d", &h, &c);

    auto compare = [](const std::pair<size_t, int>& left, const std::pair<size_t, int>& right)
    {
        return (left.first + left.second > right.first + right.second);
    };

    std::vector<std::pair<size_t, int>> data;
    data.reserve(c);

    int maxAnger = 0;

    for (int i = 0; i < c; i++)
    {
        size_t a;
        int d;
        scanf("%lu %d", &a, &d);

        maxAnger = std::max(static_cast<size_t>(maxAnger), a);

        data.push_back(std::make_pair(a, d));
    }

    std::priority_queue<std::pair<size_t, int>, std::vector<std::pair<size_t, int>>, decltype(compare)> pq(compare, data);

    for (int i = 0; i < h; i++)
    {
        std::pair<size_t, int> minC = pq.top();
        pq.pop();

        minC.first += minC.second;
        maxAnger = std::max(static_cast<size_t>(maxAnger), minC.first);

        pq.push(minC);
    }

    std::cout << maxAnger << '\n';
}
