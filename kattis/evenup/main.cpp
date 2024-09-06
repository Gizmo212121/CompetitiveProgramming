#include <iostream>
#include <stack>

int main()
{
    int numberOfCards = 0;
    scanf("%d", &numberOfCards);

    std::stack<int> stack;

    int currentNumber;
    for (int iter = 0; iter < numberOfCards; iter++)
    {
        scanf("%d", &currentNumber);

        if (stack.size() && (currentNumber + stack.top()) % 2 == 0)
        {
            stack.pop();
        }
        else
        {
            stack.push(currentNumber);
        }
    }

    printf("%lu\n", stack.size());
}
