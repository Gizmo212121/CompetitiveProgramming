#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    int data[100000];

    for (int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);

        data[i] = input;
    }

    std::priority_queue<int> pq(data, data + n);

    int sum = 0;

    for (int i = 0; i < n / 3; i++)
    {
        sum += pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        pq.pop();
    }

    for (int i = 0; i < n % 3; i++)
    {
        sum += pq.top(); pq.pop();
    }

    printf("%d\n", sum);
}
