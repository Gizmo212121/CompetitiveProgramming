#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum
{
    MAGIC,
    LEFT,
    RIGHT,
    CYCLE
};

const int MAX_BOARD_VALUE = 201;

std::pair<int, int> runGame()
{
    int numberOfBoardSquares;
    int frogIndex;
    int magicNumber;

    std::string parameters;
    std::getline(std::cin, parameters);
    std::istringstream inputParameters(parameters);

    inputParameters >> numberOfBoardSquares >> frogIndex >> magicNumber;

    std::vector<int> board;
    board.resize(numberOfBoardSquares);

    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        std::cin >> board[i];
    }

    int numberOfHops = 0;

    while (true)
    {
        int numberAtFrogIndex = board[frogIndex - 1];

        if (numberAtFrogIndex == magicNumber)
        {
            return std::pair<int, int>(MAGIC, numberOfHops);
        }
        else if (numberAtFrogIndex == MAX_BOARD_VALUE)
        {
            return std::pair<int, int>(CYCLE, numberOfHops);
        }

        numberOfHops++;

        board[frogIndex - 1] = MAX_BOARD_VALUE;

        frogIndex += numberAtFrogIndex;

        if (frogIndex <= 0)
        {
            return std::pair<int, int>(LEFT, numberOfHops);
        }
        else if (frogIndex > numberOfBoardSquares)
        {
            return std::pair<int, int>(RIGHT, numberOfHops);
        }
    }
}

int main()
{
    std::pair<int, int> outcome = runGame();

    switch (outcome.first)
    {
        case MAGIC:
            std::cout << "magic\n";
            break;
        case LEFT:
            std::cout << "left\n";
            break;
        case RIGHT:
            std::cout << "right\n";
            break;
        case CYCLE:
            std::cout << "cycle\n";
            break;
    }

    std::cout << outcome.second << '\n';

    return 0;
}
