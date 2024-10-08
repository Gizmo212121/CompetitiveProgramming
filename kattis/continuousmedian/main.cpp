#include <bits/stdc++.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    std::string output;
    output.reserve(100000);

    for (int i = 0; i < testCases; i++)
    {
        long long medianSum = 0;

        std::priority_queue<long long> lower_priority_queue;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> upper_priority_queue;

        char input = 0;
        size_t lower_priority_queue_size = 0;
        size_t upper_priority_queue_size = 0;

        int n;
        scanf("%d", &n);

        getchar_unlocked();
        for (int j = 0; j < n; j++)
        {
            long long number = 0;

            while (true)
            {
                input = getchar_unlocked();
                if (input == ' ' || input == '\n') { break; }

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


            if (lower_priority_queue_size == upper_priority_queue_size)
            {
                medianSum += (upper_priority_queue.top() + lower_priority_queue.top()) / 2;
            }
            else
            {
                medianSum += lower_priority_queue.top();
            }
        }

        output += std::to_string(medianSum) + '\n';
    }

    printf("%s", output.c_str());
}
