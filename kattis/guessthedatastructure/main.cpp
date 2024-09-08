#include <bits/stdc++.h>

int main()
{
    int testCases;

    std::stack<int> stack;
    std::queue<int> queue;
    std::priority_queue<int> priority_queue;

    std::string output;
    output.reserve(1000000);

    while (scanf("%d", &testCases) == 1)
    {
        bool is_stack = true;
        bool is_queue = true;
        bool is_priority_queue = true;

        for (int i = 0; i < testCases; i++)
        {
            if (!is_stack && !is_queue && !is_priority_queue)
            {
                int _, __;
                for (int j = 0; j < testCases - i; j++)
                {
                    scanf("%d %d", &_, &__);
                }

                break;
            }

            int type, x;
            scanf("%d %d", &type, &x);

            switch (type)
            {
                case 1:
                    if (is_stack) stack.emplace(x);
                    if (is_queue) queue.emplace(x);
                    if (is_priority_queue) priority_queue.emplace(x);
                    break;
                case 2:
                    if (is_stack)
                    {
                        if (stack.empty() || stack.top() != x) { is_stack = false; }
                        else { stack.pop(); }
                    }

                    if (is_queue)
                    {
                        if (queue.empty() || queue.front() != x) { is_queue = false; }
                        else { queue.pop(); }
                    }

                    if (is_priority_queue)
                    {
                        if (priority_queue.empty() || priority_queue.top() != x) { is_priority_queue = false; }
                        else { priority_queue.pop(); }
                    }

                    break;
            }
        }

        while (!stack.empty()) { stack.pop(); }
        while (!queue.empty()) { queue.pop(); }
        while (!priority_queue.empty()) { priority_queue.pop(); }

        if (is_stack && !is_queue && !is_priority_queue)
        {
            output += "stack\n";
        }
        else if (!is_stack && is_queue && !is_priority_queue)
        {
            output += "queue\n";
        }
        else if (!is_stack && !is_queue && is_priority_queue)
        {
            output += "priority queue\n";
        }
        else if (!is_stack && !is_queue && !is_priority_queue)
        {
            output += "impossible\n";
        }
        else
        {
            output += "not sure\n";
        }
    }

    printf("%s", output.c_str());
}
