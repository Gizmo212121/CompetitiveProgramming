#include <bits/stdc++.h>
#include <cstdio>

enum
{
    BINARY,
    DECIMAL,
    NEITHER,
};

std::pair<int, int> adjacencies[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int pathfind1(int r1, int c1, int r2, int c2, const std::vector<std::vector<bool>>& board, const int r, const int c)
{
    r1--;
    c1--;
    r2--;
    c2--;

    bool startingValue = board[r1][c1];
    if (board[r2][c2] == !startingValue) { return NEITHER; }

    std::pair<int, int> goal(r2, c2);

    std::stack<std::pair<int, int>> tocheck;
    tocheck.push({r1, c1});

    std::vector<std::vector<bool>> checked(r, std::vector<bool>(c, false));

    while (!tocheck.empty())
    {
        std::pair<int, int> currentElement = tocheck.top();

        if (currentElement == goal) { return startingValue; }

        tocheck.pop();

        checked[currentElement.first][currentElement.second] = true;

        for (const std::pair<int, int>& direction : adjacencies)
        {
            std::pair<int, int> resultingPosition = {currentElement.first + direction.first, currentElement.second + direction.second};

            if (resultingPosition.first < 0 || resultingPosition.first >= r || resultingPosition.second < 0 || resultingPosition.second >= c) { continue; }

            if (board[resultingPosition.first][resultingPosition.second] == !startingValue) { continue; }

            if (checked[resultingPosition.first][resultingPosition.second] == true) { continue; }

            tocheck.push(resultingPosition);
        }
    }

    return NEITHER;
}

int pathfind2(int r1, int c1, int r2, int c2, const std::vector<std::vector<bool>>& board)
{
    r1--;
    c1--;
    r2--;
    c2--;

    bool startingValue = board[r1][c1];
    if (board[r2][c2] == !startingValue) { return NEITHER; }



    return startingValue;
}

int main()
{
    // std::cin.tie(NULL);
    // std::ios::sync_with_stdio(false);

    int r, c;
    scanf("%d %d", &r, &c);

    std::vector<std::vector<bool>> board;
    board.resize(r);

    std::cin.ignore(1, '\n');

    for (int i = 0; i < r; i++)
    {
        board[i].resize(c);

        for (int j = 0; j < c; j++)
        {
            char input;
            while ((input = getchar()) == '\n')
            {
            }

            if (input == '0') { board[i][j] = false; }
            else if (input == '1') { board[i][j] = true; }
        }
    }

    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         std::cout << board[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int result = pathfind1(r1, c1, r2, c2, board, r, c);

        if (result == NEITHER) { std::cout << "neither\n"; }
        else if (result == BINARY) { std::cout << "binary\n"; }
        else { std::cout << "decimal\n"; }
    }
}
