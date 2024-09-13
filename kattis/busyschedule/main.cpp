#include <bits/stdc++.h>

int string_time_to_minutes(const std::string& input)
{
    std::istringstream is(input);
    std::string time;
    std::string mid_day;
    is >> time >> mid_day;

    int hours = 0;
    int minutes = 0;

    int i = 0;
    while (i < static_cast<int>(time.size()))
    {
        if (time[i] == ':') { break; }

        hours = hours * 10 + time[i] - '0';

        i++;
    }

    for (int j = i + 1; j < time.size(); j++)
    {
        minutes = minutes * 10 + time[j] - '0';
    }

    if (mid_day == "a.m.")
    {
        if (hours != 12)
        {
            minutes += hours * 60;
        }
    }
    else
    {
        if (hours == 12)
        {
            minutes += hours * 60;
        }
        else
        {
            minutes += (hours + 12) * 60;
        }
    }

    return minutes;
}

int main()
{
    int testcase;
    while ((std::cin >> testcase, testcase) != 0)
    {
        std::cin.ignore(1, '\n');
        std::vector<std::string> times(testcase);
        for (int i = 0; i < testcase; i++)
        {
            std::string line;
            std::getline(std::cin, line);

            times.push_back(line);
        }

        std::sort(times.begin(), times.end(), [](const std::string& s1, const std::string& s2)
                {
                    return string_time_to_minutes(s1) < string_time_to_minutes(s2);
                });

        for (size_t i = 0; i < times.size(); i++)
        {
            std::cout << times[i] << '\n';
        }
        std::cout << std::endl;
    }
}
