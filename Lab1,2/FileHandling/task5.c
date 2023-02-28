
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fptr;
    char dataToBeRead[50];
    fptr = fopen(__FILE__, "r");
    if (fptr == NULL)
    {
        printf("file failed to open");
    }
    else
    {
        printf("contents in: " __FILE__);
        printf("\n");
        printf("File opened successfully \n");
        while (fgets(dataToBeRead, 50, fptr))
        {
            printf("%s", dataToBeRead);
        }
        fclose(fptr);
    }
}