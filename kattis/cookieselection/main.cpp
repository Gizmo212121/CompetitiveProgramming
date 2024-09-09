#include <bits/stdc++.h>

int main()
{
    std::priority_queue<int> lower_priority_queue;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper_priority_queue;

    char input = 0;
    size_t lower_priority_queue_size = 0;
    size_t upper_priority_queue_size = 0;

    std::string output;
    output.reserve(100000);

    while (input != EOF)
    {
        int number = 0;
        input = getchar_unlocked();

        if (input == '#')
        {
            if (lower_priority_queue_size == upper_priority_queue_size)
            {
                output += std::to_string(upper_priority_queue.top()) + '\n';

                upper_priority_queue.pop();
                upper_priority_queue_size--;
            }
            else
            {
                output += std::to_string(lower_priority_queue.top()) + '\n';

                lower_priority_queue.pop();
                lower_priority_queue_size--;
            }

            scanf("%c", &input);

        }
        else if (input >= '0' && input <= '9')
        {
            number += input - '0';
            while ((input = getchar_unlocked()) != '\n')
            {
                number = number * 10 + input - '0';
            }

            if (lower_priority_queue_size == upper_priority_queue_size)
            {
                if (lower_priority_queue_size != 0 && number > upper_priority_queue.top())
                {
                    lower_priority_queue.push(upper_priority_queue.top());
                    upper_priority_queue.pop();
                    upper_priority_queue.push(number);
                }
                else
                {
                    lower_priority_queue.push(number);
                }
            }
            else
            {
                if (lower_priority_queue.top() > number)
                {
                    upper_priority_queue.push(lower_priority_queue.top());
                    lower_priority_queue.pop();
                    lower_priority_queue.push(number);
                }
                else
                {
                    upper_priority_queue.push(number);
                }
            }

            lower_priority_queue_size = lower_priority_queue.size();
            upper_priority_queue_size = upper_priority_queue.size();
        }
    }

    printf("%s", output.c_str());
}
