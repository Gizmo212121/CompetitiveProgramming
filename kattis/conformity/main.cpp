// https://open.kattis.com/problems/conformity
#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    std::map<std::vector<int>, int> courseCombinations;

    for (int i = 0; i < n; i++)
    {
        std::vector<int> courses(5);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &courses[j]);
        }

        std::sort(courses.begin(), courses.end());
        courseCombinations[courses]++;
    }

    int maxPopularity = 0;
    int totalPopularity = 0;
    for (auto& it : courseCombinations)
    {
        if (it.second > maxPopularity) { maxPopularity = it.second; totalPopularity = it.second; }
        else if (it.second == maxPopularity) { maxPopularity = it.second; totalPopularity += maxPopularity; }
    }

    printf("%d", totalPopularity);
}
