#include <bits/stdc++.h>

int get_word_fast(std::array<char, 11>& arr)
{
    char input;
    int count = 0;
    while ((input = getchar_unlocked()) != ' ' && input != '\n' && input != EOF)
    {
        arr[count++] = input;
        if (count >= 11) { break; }
    }

    arr[count] = '\0';

    return (count == 0) ? 1 : 0;
}

int main()
{
    std::map<std::array<char, 11>, std::array<char, 11>> map;

    std::array<char, 11> english;
    std::array<char, 11> translate;

    while (get_word_fast(english) == 0)
    {
        get_word_fast(translate);

        map[translate] = english;

        std::fill(english.begin(), english.end(), 0);
        std::fill(translate.begin(), translate.end(), 0);
    }

    while (get_word_fast(translate) == 0)
    {
        if (map.find(translate) == map.end())
        {
            printf("eh\n");
        }
        else
        {
            printf("%s\n", map[translate].data());
        }
    }
}
