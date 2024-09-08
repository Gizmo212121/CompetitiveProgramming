// https://open.kattis.com/problems/10kindsofpeople
// This is my own solution using my own intuitions

#include <bits/stdc++.h>
#include <cstdio>

const size_t MAX_BOARD_SIZE = 1000;

enum
{
    BINARY,
    DECIMAL,
    NEITHER,
};

std::pair<int, int> adjacencies[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int pathfind1(int r1, int c1, int r2, int c2, const bool board[MAX_BOARD_SIZE][MAX_BOARD_SIZE], const int r, const int c, int visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE], int& visitedCounter)
{
    r1--; c1--; r2--; c2--;

    bool startingValue = board[r1][c1];
    if (board[r2][c2] == !startingValue) { return NEITHER; }

    if (visited[r1][c1] != -1 && visited[r1][c1] == visited[r2][c2])
    {
        return startingValue;
    }

    visitedCounter++;

    std::pair<int, int> goal(r2, c2);

    std::stack<std::pair<int, int>> tocheck;
    tocheck.push({r1, c1});

    while (!tocheck.empty())
    {
        std::pair<int, int> currentElement = tocheck.top();

        if (currentElement == goal) { return startingValue; }

        tocheck.pop();

        visited[currentElement.first][currentElement.second] = visitedCounter;

        for (const std::pair<int, int>& direction : adjacencies)
        {
            std::pair<int, int> resultingPosition = {currentElement.first + direction.first, currentElement.second + direction.second};

            if (resultingPosition.first < 0 || resultingPosition.first >= r || resultingPosition.second < 0 || resultingPosition.second >= c) { continue; }

            if (board[resultingPosition.first][resultingPosition.second] == !startingValue) { continue; }

            if (visited[resultingPosition.first][resultingPosition.second] == visitedCounter) { continue; }

            tocheck.push(resultingPosition);
        }
    }

    return NEITHER;
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    bool board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    int visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

    for (int i = 0; i < r; i++)
    {
        std::fill(visited[i], visited[i] + c, -1);
    }

    std::cin.ignore(1, '\n');

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char input;
            while ((input = getchar_unlocked()) == '\n')
            {
            }

            if (input == '0') { board[i][j] = false; }
            else if (input == '1') { board[i][j] = true; }
        }
    }

    int n;
    scanf("%d", &n);

    int visitedCounter = 0;

    for (int i = 0; i < n; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        int result = pathfind1(r1, c1, r2, c2, board, r, c, visited, visitedCounter);

        if (result == NEITHER) { std::cout << "neither\n"; }
        else if (result == BINARY) { std::cout << "binary\n"; }
        else { std::cout << "decimal\n"; }
    }
}
