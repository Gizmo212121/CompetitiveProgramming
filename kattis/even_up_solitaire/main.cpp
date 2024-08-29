#include <iostream>
#include <sstream>
#include <string>
#include <stack>

int main()
{
    int numberOfCards = 0;
    std::cin >> numberOfCards;

    std::cin.ignore(1, '\n');

    std::string cards;
    std::getline(std::cin, cards);

    std::istringstream cardsStream(cards);

    std::stack<int> stack;

    int currentNumber;
    for (int iter = 0; iter < numberOfCards; iter++)
    {
        cardsStream >> currentNumber;

        if (stack.size() && (currentNumber + stack.top()) % 2 == 0)
        {
                stack.pop();
        }
        else
        {
            stack.push(currentNumber);
        }
    }

    std::cout << stack.size() << '\n';
}
