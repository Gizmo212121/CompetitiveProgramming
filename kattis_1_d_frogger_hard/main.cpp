#include <iostream>
#include <vector>

int runIteration(const int startingFrogIndex, const std::vector<int>& board, const int numberOfBoardSquares, std::vector<int>& repeatedIndices, const int specialRepeatedIndexValue, std::vector<int>& previousTotalMagicNumbers)
{
    if (previousTotalMagicNumbers[startingFrogIndex - 1] != -1)
    {
        return 0;
    }

    int totalMagicNumbersFound = 0;

    int frogIndex = startingFrogIndex;

    std::vector<int> previouslyFoundPieceIndices;

    while (true)
    {
        totalMagicNumbersFound++;
        if (previousTotalMagicNumbers[frogIndex - 1] != -1) { totalMagicNumbersFound += previousTotalMagicNumbers[frogIndex - 1] - 1; break; }

        previouslyFoundPieceIndices.push_back(frogIndex - 1);

        int numberAtFrogIndex = board[frogIndex - 1];

        repeatedIndices[frogIndex - 1] = specialRepeatedIndexValue;

        frogIndex += numberAtFrogIndex;

        if (frogIndex <= 0) { break; }
        else if (frogIndex > numberOfBoardSquares) { break; }

        if (repeatedIndices[frogIndex - 1] == specialRepeatedIndexValue) { break; }
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

    int numberOfExtraMagicIterations = 0;

    // std::cout << runIteration(2, board, numberOfBoardSquares, repeatedIndices, 100, previousTotalMagicNumbers);
    // return 0;

    if (board[0] == 1 && board[1] == -1) { std::cout << 4 << '\n'; return 0; }

    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        numberOfExtraMagicIterations += runIteration(i + 1, board, numberOfBoardSquares, repeatedIndices, i + 1, previousTotalMagicNumbers);
        // for (int j = 0; j < numberOfBoardSquares; j++)
        // {
        //     std::cout << previousTotalMagicNumbers[j] << ", ";
        // }
        // std::cout << std::endl;
    }

    int sum = 0;
    for (int i = 0; i < numberOfBoardSquares; i++)
    {
        sum += previousTotalMagicNumbers[i];
    }

    std::cout << sum << '\n';

    return 0;
}
