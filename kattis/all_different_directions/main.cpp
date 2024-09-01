#include <bits/stdc++.h>
#include <string>
#include <cmath>

int main()
{
    int n;
    while ((std::cin >> n, n) != 0)
    {
        double sumX = 0;
        double sumY = 0;

        std::vector<std::pair<double, double>> positions;
        positions.reserve(n);

        std::cin.ignore(1, '\n');

        for (int i = 0; i < n; i++)
        {
            std::string line;
            std::getline(std::cin, line);
            std::istringstream is(line);

            double x, y;
            is >> x >> y;

            double finalX = x;
            double finalY = y;

            std::string instruction;

            double angle;
            if ((is >> instruction, instruction) == "start") { is >> angle; angle *= M_PI / 180.0; }

            while (is >> instruction)
            {
                if (instruction == "walk")
                {
                    double walk;
                    is >> walk;

                    finalX += cos(angle) * walk;
                    finalY += sin(angle) * walk;
                }
                else if (instruction == "turn")
                {
                    double dAngle;
                    is >> dAngle;
                    angle += dAngle * M_PI / 180.0;
                }
            }

            sumX += finalX;
            sumY += finalY;

            positions.push_back(std::make_pair(finalX, finalY));
        }

        double averageX = sumX / n;
        double averageY = sumY / n;

        double worstDistSquared = 0;

        for (size_t i = 0; i < positions.size(); i++)
        {
            double distSq = std::pow(positions[i].first - averageX, 2) + std::pow(positions[i].second - averageY, 2);
            if (distSq > worstDistSquared)
            {
                worstDistSquared = distSq;
            }
        }

        std::cout << sumX / n << ' ' << sumY / n << ' ' << sqrt(worstDistSquared) << '\n';
    }
}
