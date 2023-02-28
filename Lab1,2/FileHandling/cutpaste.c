#include <stdio.h>
#include <string.h>
int main()
{
    FILE *ptr1 = fopen("test1.txt", "r");
    FILE *ptr2 = fopen("test2.txt", "w");
    char buffer[100];

    while (fgets(buffer, 100, ptr1))
    {
        fputs(buffer, ptr2);
    }
    fclose(fopen("test1.txt", "w"));
}