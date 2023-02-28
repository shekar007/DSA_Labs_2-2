#include "set.h"
int answer_checker(char arr[])
{
    char key[] = {'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D', 'A', 'B'};
    int score = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if (arr[i] == key[i])
        {
            score += 4;
        }
        else
        {
            score -= 1;
        }
    }
    return score;
}