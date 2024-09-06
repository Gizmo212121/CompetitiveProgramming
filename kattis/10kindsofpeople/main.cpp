#include <bits/stdc++.h>
#include <cstdio>

enum
{
    BINARY,
    DECIMAL,
    NEITHER,
};

int pathfind(int r1, int c1, int r2, int c2, const std::vector<std::vector<bool>>& board)
{
    r1--;
    c1--;
    r2--;
    c2--;

    bool startingValue = board[r1][c1];
    // if (board[r2][c2] == !startingValue) { return NEITHER; }


    return startingValue;
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    std::vector<std::vector<bool>> board;
    board.reserve(r);

    std::cin.ignore(1, '\n');

    for (int i = 0; i < r; i++)
    {
        board[i].reserve(c);

        for (int j = 0; j < c; j++)
        {
            char input = getchar();
            if (input == '0') { board[i].push_back(false); }
            else { board[i].push_back(true); }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int result = pathfind(r1, c1, r2, c2, board);

        if (result == NEITHER) { std::cout << "neither\n"; }
        else if (result == BINARY) { std::cout << "binary\n"; }
        else { std::cout << "decimal\n"; }
    }
}
