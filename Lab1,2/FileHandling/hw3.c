#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    //
    FILE *ptr = fopen("LOTR.txt", "r");
    char buffer[1000];
    char str[1000000];
    while (fgets(buffer, 1000, ptr))
    {
        strcat(str, buffer);
        printf("%s", str);
    }
    int c = 0;
    char *arr = strtok(str, " ");
    char *brr = "hobbit";
    while (arr != NULL)
    {
        int l = strlen(arr);
        for (size_t i = 0; i < l; i++)
        {
            arr[i] = tolower(arr[i]);
        }
        int f = 0;
        for (size_t i = 0; i < __min(l, 6); i++)
        {
            f = 0;
            if (arr[i] == brr[i])
            {
                continue;
            }
            else
            {
                f = 1;
                break;
            }
        }
        if (f != 1)
        {
            c++;
        }

        arr = strtok(NULL, " ");
    }
    printf("%d", c);
}