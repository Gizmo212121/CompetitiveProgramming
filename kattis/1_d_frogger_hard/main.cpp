#include <cstdlib>
#include <iostream>
#include <vector>

int runIteration(const int startingFrogIndex, const std::vector<int>& board, const int numberOfBoardSquares, std::vector<int>& repeatedIndices, const int specialRepeatedIndexValue, std::vector<int>& previousTotalMagicNumbers, std::vector<int>& cycleIndices)
{
    if (previousTotalMagicNumbers[startingFrogIndex - 1] != -1)
    {
        return 0;
    }

    int totalMagicNumbersFound = 0;

    int frogIndex = startingFrogIndex;

    std::vector<int> previouslyFoundPieceIndices;
    previouslyFoundPieceIndices.resize(0);

    while (true)
    {
        if (cycleIndices[frogIndex - 1] != -1)
        {
            int cycleMagicNumbers = cycleIndices[frogIndex - 1];

            for (int i = 0; i < totalMagicNumbersFound; i++)
            {
                previousTotalMagicNumbers[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound + cycleMagicNumbers - i;
            }

            return totalMagicNumbersFound;
        }
        else if (previousTotalMagicNumbers[frogIndex - 1] != -1)
        {
            totalMagicNumbersFound += previousTotalMagicNumbers[frogIndex - 1];

            break;
        }

        totalMagicNumbersFound++;

        previouslyFoundPieceIndices.push_back(frogIndex - 1);

        int numberAtFrogIndex = board[frogIndex - 1];

        repeatedIndices[frogIndex - 1] = specialRepeatedIndexValue;

        frogIndex += numberAtFrogIndex;

        if (frogIndex <= 0) { break; }
        else if (frogIndex > numberOfBoardSquares) { break; }

        if (repeatedIndices[frogIndex - 1] == specialRepeatedIndexValue)
        {
            // Find the index value of the square that started the loop

            int indexOfStartOfLoopStart = -1;
            for (size_t i = 0; i < previouslyFoundPieceIndices.size(); i++)
            {
                if (indexOfStartOfLoopStart == -1 && previouslyFoundPieceIndices[i] == frogIndex - 1)
                {
                    indexOfStartOfLoopStart = previouslyFoundPieceIndices[i];
                }

                if (indexOfStartOfLoopStart != -1)
                {
                    previousTotalMagicNumbers[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound - indexOfStartOfLoopStart;
                    cycleIndices[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound - indexOfStartOfLoopStart;
                }
                else
                {
                    previousTotalMagicNumbers[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound - i;
                    cycleIndices[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound - i;
                }

            }

            return totalMagicNumbersFound;
        }
    }

    for (int i = 0; i < totalMagicNumbersFound; i++)
    {
        previousTotalMagicNumbers[previouslyFoundPieceIndices[i]] = totalMagicNumbersFound - i;
    }

    return totalMagicNumbersFound;
}

int main()
{
    int numberOfBoardSquares;
    std::cin >> numberOfBoardSquares;
    std::cin.ignore(1, '\n');

    std::vector<int> board;
    board.resize(numberOfBoardSquares);

    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        std::cin >> board[i];
    }

    std::vector<int> repeatedIndices(numberOfBoardSquares, -1);
    std::vector<int> previousTotalMagicNumbers(numberOfBoardSquares, -1);
    std::vector<int> cycleIndices(numberOfBoardSquares, -1);

    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        runIteration(i + 1, board, numberOfBoardSquares, repeatedIndices, i + 1, previousTotalMagicNumbers, cycleIndices);
    }

    int sum = 0;
    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        sum += previousTotalMagicNumbers[i];
    }

    std::cout << sum << '\n';

    return 0;
}
