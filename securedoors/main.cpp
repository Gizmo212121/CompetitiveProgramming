#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;

    std::set<std::string> log;

    for (int i = 0; i < n; i++)
    {
        std::string command;
        std::string name;

        std::cin >> command >> name;

        if (command == "entry")
        {
            if (log.find(name) != log.end())
            {
                std::cout << name << " entered (ANOMALY)\n";
            }
            else
            {
                log.insert(name);
                std::cout << name << " entered\n";
            }
        }
        else
        {
            if (log.find(name) != log.end())
            {
                log.erase(name);
                std::cout << name << " exited\n";
            }
            else
            {
                std::cout << name << " exited (ANOMALY)\n";
            }
        }
    }
}
