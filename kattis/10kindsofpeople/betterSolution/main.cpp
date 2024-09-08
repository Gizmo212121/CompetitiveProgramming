#include <bits/stdc++.h>

const int MAX_BOARD_SIZE = 1000;

std::pair<int, int> adjacencies[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int find(int parent[], int x)
{
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unite(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY)
    {
        if (rank[rootX] < rank[rootY])
        {
            std::swap(rootX, rootY);
        }

        parent[rootX] = rootY;

        if (rank[rootX] == rank[rootY])
        {
            rank[rootX]++;
        }
    }
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    std::bitset<MAX_BOARD_SIZE * MAX_BOARD_SIZE> board;

    int parent[MAX_BOARD_SIZE * MAX_BOARD_SIZE];

    for (int i = 0; i < r * c; ++i)
    {
        parent[i] = i;
    }

    int rank[MAX_BOARD_SIZE * MAX_BOARD_SIZE];
    std::fill(rank, rank + MAX_BOARD_SIZE * MAX_BOARD_SIZE, 1);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char input;

            while ((input = getchar_unlocked()) == '\n') {}
            board[i * c + j] = (input == '1');
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i > 0 && board[i * c + j] == board[(i - 1) * c + j])
            {
                unite(parent, rank, i * c + j, (i - 1) * c + j);
            }
            if (j > 0 && board[i * c + j] == board[i * c + j - 1])
            {
                unite(parent, rank, i * c + j, i * c + (j - 1));
            }
        }
    }

    int n;
    scanf("%d", &n);

    std::string output;
    output.reserve(n * 7);

    for (int i = 0; i < n; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        r1--; c1--; r2--; c2--;
        if (board[r1 * c + c1] != board[r2 * c + c2])
        {
            output += "neither\n";
        }
        else if (find(parent, r1 * c + c1) == find(parent, r2 * c + c2))
        {
            output += (board[r1 * c + c1] ? "decimal\n" : "binary\n");
        }
        else
        {
            output += "neither\n";
        }
    }

    printf("%s", output.c_str());
}
