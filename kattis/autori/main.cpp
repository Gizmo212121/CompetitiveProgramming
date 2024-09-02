#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    bool foundH = true;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (foundH) { std::cout << line[i]; foundH = false; }
        else if (line[i] == '-') { foundH = true; }
    }

    std::cout << std::endl;
}
