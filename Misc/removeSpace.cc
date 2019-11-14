#include <iostream>
#include <stdlib.h>
#include <string.h>

void removeSpaces(char *str, int size)
{
    for (int i=0; i < size; i++)
    {
        while (isspace(str[i]) && i < size)
        {
            i++;
        }

        if (str[i])
    }
}

int main()
{
    char p[ ] = "   Hello world  . how are you doing today, any news ?   ";
    removeSpaces(p, strlen(p));
    return 0;
}