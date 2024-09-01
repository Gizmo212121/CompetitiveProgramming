#include <bits/stdc++.h>

#define MAX_SIZE 1000000

int jack[MAX_SIZE];

inline int fast_read() {
    int num = 0, c;
    while ((c = getchar_unlocked()) >= '0') {
        num = 10 * num + (c - '0');
    }
    return num;
}

int main()
{
    while (true)
    {
        int n = fast_read();
        int m = fast_read();

        if (n == 0 && m == 0) { break; }

        for (int i = 0; i < n; i++)
        {
            jack[i] = fast_read();
        }

        int cds = 0, j = 0;

        for (int i = 0; i < m; i++)
        {
            if (i >= m) { break; }
            int input = fast_read();

            while (j < n && input > jack[j])
            {
                j++;
            }

            if (j < n && input == jack[j])
            {
                cds++;
                j++;
            }
        }

        printf("%d\n", cds);
    }

    return 0;
}
