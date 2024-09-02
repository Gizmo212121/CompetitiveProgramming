#include <iostream>

int main()
{
    std::string i1;
    std::string i2;
    std::getline(std::cin, i1);
    std::getline(std::cin, i2);

    if (i1.size() >= i2.size()) { std::cout << "go\n"; }
    else { std::cout << "no\n"; }
}
