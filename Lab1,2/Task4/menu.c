#include <stdio.h>
int main()
{
    printf("Enter size of the string: ");
    int n;
    scanf(" %d", &n);
    char *arr = (char *)malloc(n * sizeof(char));
    printf("Enter string you want to store");
    gets(arr);

    while (1)
    {
        int c;
        printf("1 Add a string to the end of the array,\n 2 Add a string to the beginning of the array,\n 3 Delete the element at index x(taken as input) of the array,\n 4 Display the length of the array,\n 5 Display all the elements of the array in sequence.\n");
        scanf("%d", &c);
        if (c == 1)
        {
            char c1;
            printf("Enter charachter you want to add: \n");
            scanf("%c", &c1);
            arr = realloc(arr, n + 1);
            arr[n] = c1;
        }
        else if (c == 2)
        {
            char c1;
            printf("Enter charachter you want to add: \n");
            scanf("%c", &c1);
            arr = realloc(arr, n + 1);
            arr = arr - 1;
            arr[0] = c1;
        }
        else if (c == 3)
        {
            int x;
            printf("enter index of charachter you want to remove");
            scanf(" %d", x);
            char *brr = (char *)malloc(sizeof(arr) / sizeof(char) - 1);
            int count = 0;
            for (size_t i = 0; i < sizeof(arr) / sizeof(char) - 1; i++)
            {
                if (count == x)
                {
                    continue;
                }
                brr[count] = arr[count];
                count++;
            }
            free(arr);
            arr = brr;
            free(brr);
        }
        else if (c == 4)
        {
            printf("length of the array:%d", sizeof(arr) / sizeof(char));
        }
        else if (c == 5)
        {
            for (size_t i = 0; i < sizeof(arr) / sizeof(char); i++)
            {
                printf("%c", arr[i]);
            }
                }
        else if (c == 6)
        {
            break;
        }
        else
        {
            printf("Invalid input.\n");
        }
    }
}
