#include <vector>
#include <iostream>
#include <random>
#include <unordered_set>
#include <chrono>

// #define MAX_BOARD_SIZE 200'000
#define MAX_BOARD_SIZE 1000'000

void runIteration(const int startingIndex, int board[], const int numberOfBoardSquares, std::vector<int>& repeatedIndices, std::vector<int>& previousTotalMagicNumbers, std::vector<std::vector<int>>& subpathDistinctMagicNumbers, int& olist, int& oloop, int& odistinct)
{
    olist++;

    if (subpathDistinctMagicNumbers[startingIndex].size() > 0)
    {
        return;
    }

    int totalMagicNumbersFound = 0;

    std::vector<int> distinctMagicNumbers;
    std::unordered_set<int> distinctMagicNumbersMap;
    // distinctMagicNumbers.


    int currentIndex = startingIndex;

    std::vector<int> previouslyFoundPieceIndices;
    previouslyFoundPieceIndices.reserve(numberOfBoardSquares);

    while (true)
    {
        oloop++;

        previouslyFoundPieceIndices.push_back(currentIndex);
        repeatedIndices[currentIndex] = startingIndex;

        if (distinctMagicNumbersMap.find(board[currentIndex]) == distinctMagicNumbersMap.end())
        {
            distinctMagicNumbersMap.insert(board[currentIndex]);
        }

        int numberAtFrogIndex = board[currentIndex];
        currentIndex += numberAtFrogIndex;

        if (currentIndex < 0 || currentIndex >= numberOfBoardSquares) { break; }

        if (!subpathDistinctMagicNumbers[currentIndex].empty())
        {
            distinctMagicNumbers = subpathDistinctMagicNumbers[currentIndex];
            // distinctMagicNumbersMap.insert(subpathDistinctMagicNumbers[currentIndex].begin(), subpathDistinctMagicNumbers[currentIndex].end());

            break;
        }

        if (repeatedIndices[currentIndex] == startingIndex)
        {
            // std::cout << "Found loop!\n";
            // Find the index value of the square that started the loop

            int indexOfStartOfLoopStart = -1;
            for (size_t i = 0; i < previouslyFoundPieceIndices.size(); i++)
            {
                if (indexOfStartOfLoopStart == -1 && previouslyFoundPieceIndices[i] == currentIndex)
                {
                    indexOfStartOfLoopStart = i;
                }

                if (indexOfStartOfLoopStart != -1)
                {
                    bool currentValueIsDistinct = true;
                    for (size_t j = 0; j < distinctMagicNumbers.size(); j++)
                    {
                        odistinct++;

                        if (distinctMagicNumbers[j] == board[previouslyFoundPieceIndices[i]])
                        {
                            currentValueIsDistinct = false;
                            break;
                        }
                    }

                    if (currentValueIsDistinct)
                    {
                        // std::cout << "Adding a distinct value: " << board[previouslyFoundPieceIndices[i]] << '\n';
                        distinctMagicNumbers.push_back(board[previouslyFoundPieceIndices[i]]);
                    }
                }
            }

            // std::cout << "Distinct magic numbers size: " << distinctMagicNumbers.size() << std::endl;

            for (int i = indexOfStartOfLoopStart; i < previouslyFoundPieceIndices.size(); i++)
            {
                subpathDistinctMagicNumbers[previouslyFoundPieceIndices[i]] = distinctMagicNumbers;
            }

            for (int i = indexOfStartOfLoopStart - 1; i >= 0; i--)
            {
                bool currentValueIsDistinct = true;
                for (size_t j = 0; j < distinctMagicNumbers.size(); j++)
                {
                    odistinct++;

                    if (distinctMagicNumbers[j] == board[previouslyFoundPieceIndices[i]])
                    {
                        currentValueIsDistinct = false;
                        break;
                    }
                }

                if (currentValueIsDistinct)
                {
                    distinctMagicNumbers.push_back(board[previouslyFoundPieceIndices[i]]);
                }

                // std::cout << "DEBUG\n";
                // std::cout << i << '\n';
                // std::cout << previouslyFoundPieceIndices[i] << '\n';
                subpathDistinctMagicNumbers[previouslyFoundPieceIndices[i]] = distinctMagicNumbers;
            }

            return;
        }
    }

    for (int i = static_cast<int>(previouslyFoundPieceIndices.size()) - 1; i >= 0; i--)
    {
        bool currentValueIsDistinct = true;
        for (size_t j = 0; j < distinctMagicNumbers.size(); j++)
        {
            odistinct++;

            if (distinctMagicNumbers[j] == board[previouslyFoundPieceIndices[i]])
            {
                currentValueIsDistinct = false;
                break;
            }
        }

        // bool currentValueIsDistinct = (distinctMagicNumbersMap.find(board[previouslyFoundPieceIndices[i]]) == distinctMagicNumbersMap.end());

        if (currentValueIsDistinct)
        {
            distinctMagicNumbers.push_back(board[previouslyFoundPieceIndices[i]]);
        }

        subpathDistinctMagicNumbers[previouslyFoundPieceIndices[i]] = distinctMagicNumbers;
    }

    return;
}

// void addDistinctSubpaths(const int start, const int end)
// {
//     for (int i = static_cast<int>(previouslyFoundPieceIndices.size()) - 1; i >= 0; i--)
//     {
//         bool currentValueIsDistinct = true;
//         for (size_t j = 0; j < distinctMagicNumbers.size(); j++)
//         {
//             odistinct++;
//
//             if (distinctMagicNumbers[j] == board[previouslyFoundPieceIndices[i]])
//             {
//                 currentValueIsDistinct = false;
//                 break;
//             }
//         }
//
//         // bool currentValueIsDistinct = (distinctMagicNumbersMap.find(board[previouslyFoundPieceIndices[i]]) == distinctMagicNumbersMap.end());
//
//         if (currentValueIsDistinct)
//         {
//             distinctMagicNumbers.push_back(board[previouslyFoundPieceIndices[i]]);
//         }
//
//         subpathDistinctMagicNumbers[previouslyFoundPieceIndices[i]] = distinctMagicNumbers;
//     }
// }

void generatePermutations(int depth, int numberOfBoardSquares, int board[], const int minVal, const int maxVal)
{
    if (depth == numberOfBoardSquares)
    {
        // Process the board permutation here (runIteration, etc.)
        std::vector<int> repeatedIndices(numberOfBoardSquares, -1);
        std::vector<std::vector<int>> subpathDistinctMagicNumbers(numberOfBoardSquares);
        std::vector<int> previousTotalMagicNumbers(numberOfBoardSquares, -1);

        int olist = 0;
        int oloop = 0;
        int odistinct = 0;

        for (int i = 0; i < numberOfBoardSquares; i++)
        {
            runIteration(i, board, numberOfBoardSquares, repeatedIndices, previousTotalMagicNumbers, subpathDistinctMagicNumbers, olist, oloop, odistinct);
        }

        int sum = 0;

        for (int i = 0; i < numberOfBoardSquares; i++)
        {
            sum += subpathDistinctMagicNumbers[i].size();
        }

        return;
    }

    for (int i = minVal; i <= maxVal; ++i)
    {
        board[depth] = i;
        generatePermutations(depth + 1, numberOfBoardSquares, board, minVal, maxVal);
    }
}

class Timer
{

public:

    Timer(const std::string& functionName)
    {
        start = std::chrono::high_resolution_clock::now();
        m_name = functionName;
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        m_timerMessages.push_back(m_name + " elapsed time: " + std::to_string(duration.count()) + "s");
    }

    static void print()
    {
        for (const std::string& message : m_timerMessages)
        {
            std::cout << message << '\n';
        }
    }

private:

    std::string m_name;

    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    std::chrono::duration<double> duration;

    static std::vector<std::string> m_timerMessages;

};

std::vector<std::string> Timer::m_timerMessages;

int main()
{
    // int numberOfBoardSquares;
    // std::cin >> numberOfBoardSquares;
    // std::cin.ignore(1, '\n');
    //
    // int board[MAX_BOARD_SIZE];
    //
    // for (int i = 0; i < numberOfBoardSquares; i++)
    // {
    //     std::cin >> board[i];
    // }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-2000, 2000);

    const int numberOfBoardSquares = 1000000;
    int board[MAX_BOARD_SIZE];
    for (size_t i = 0; i < numberOfBoardSquares; i++) { board[i] = dist(gen); }

    // const int numberOfBoardSquares = 6;  // Board size
    // const int minVal = -5;               // Minimum value
    // const int maxVal = 5;                // Maximum value
    //
    // std::vector<int> board(numberOfBoardSquares);
    // generatePermutations(0, numberOfBoardSquares, board, minVal, maxVal);



    {
        Timer timer("main");

        std::vector<int> repeatedIndices(numberOfBoardSquares, -1);
        std::vector<std::vector<int>> subpathDistinctMagicNumbers(numberOfBoardSquares);
        std::vector<int> previousTotalMagicNumbers(numberOfBoardSquares, -1);

        int olist = 0;
        int oloop = 0;
        int odistinct = 0;


        for (int i = 0; i < numberOfBoardSquares; i++)
        {
            runIteration(i, board, numberOfBoardSquares, repeatedIndices, previousTotalMagicNumbers, subpathDistinctMagicNumbers, olist, oloop, odistinct);
        }

        size_t sum = 0;

        for (int i = 0; i < numberOfBoardSquares; i++) { sum += subpathDistinctMagicNumbers[i].size(); }

        std::cout << sum << '\n';
        // std::cout << "N: " << numberOfBoardSquares << '\n';
        // std::cout << "olist: " << olist << '\n';
        // std::cout << "oloop: " << oloop << '\n';
        // std::cout << "odistinct: " << odistinct << '\n';
    }

    Timer::print();

    // for (int i = 0; i < numberOfBoardSquares; i++)
    // {
    //     sum += subpathDistinctMagicNumbers[i].size();
    //
    //     // for (size_t j = 0; j < subpathDistinctMagicNumbers[i].size(); j++)
    //     // {
    //     //     std::cout << subpathDistinctMagicNumbers[i][j] << ", ";
    //     // }
    //     //
    //     // std::cout << std::endl;
    // }

    return 0;
}
