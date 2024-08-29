// https://open.kattis.com/problems/throwns?editresubmit=14126072

#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

int main()
{
   std::string parameters;
    std::getline(std::cin, parameters);
    std::string commands;
    std::getline(std::cin, commands);

    std::istringstream inputParameterStringStream(parameters);
    std::istringstream inputCommandsStringStream(commands);

    int numberOfStudents = 0;
    int numberOfCommands = 0;
    inputParameterStringStream >> numberOfStudents >> numberOfCommands;

    std::vector<int> stack;
    stack.reserve(numberOfCommands);

    int currentStudent = 0;

    for (int iter = 0; iter < numberOfCommands; iter++)
    {
        std::string input;
        inputCommandsStringStream >> input;

        if (input == "undo")
        {
            int numberOfUndos;
            inputCommandsStringStream >> numberOfUndos;

            for (int undo = 0; undo < numberOfUndos; undo++)
            {
                stack.pop_back();
            }

            currentStudent = stack[stack.size() - 1];
        }
        else
        {
            currentStudent = (currentStudent + std::atoi(input.c_str())) % numberOfStudents;

            if (currentStudent < 0)
            {
                currentStudent += numberOfStudents;
            }

            stack.push_back(currentStudent);
        }
    }

    std::cout << currentStudent << '\n';

    return 0;
}
