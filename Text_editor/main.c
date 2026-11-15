#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool sp_eng(const char *sentence)
{

    const char *ToMatch = "english";
    int count_of_trueChars = 0;

    for (int i = 0; sentence[i] != 0; i++)
    {

        count_of_trueChars = 0;
        for (int j = 0; j < 7 && sentence[i + j] != 0; j++)
        {
            if (tolower(sentence[i + j]) == ToMatch[j])
            {
                count_of_trueChars++;
            }
            else
            {
                count_of_trueChars = 0;
                break;
            }
        }
        if( count_of_trueChars == 7 ? true : false)
        {
            return true;
        }
    }

}

int main()
{
    if (sp_eng("1234english ;k"))
    {

        printf("True");
    }
    else
    {
        printf("False");
    }
}