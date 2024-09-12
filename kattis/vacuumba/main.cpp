#include <bits/stdc++.h>

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int segments;
        std::cin >> segments;

        double x = 0, y = 0;
        double angle = 0;

        for (int j = 0; j < segments; j++)
        {
            double inputAngle;
            double distance;

            std::cin >> inputAngle >> distance;
            angle += inputAngle;

            x += distance * cos(- angle * M_PI / 180.0);
            y += distance * sin(- angle * M_PI / 180.0);
        }

        std::cout << y << ' ' << x << '\n';
    }
}
