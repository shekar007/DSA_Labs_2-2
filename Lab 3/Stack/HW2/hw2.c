#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stack.h"
double evaluate(char *arr, int n)
{

    Stack *s = newStack();
    char *str;
    int strcount = 0;
    int num = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (strcount == num && num != 0)
        {
            return evaluate();
        }
        else
        {

            if (arr[i] == '+' || arr[i] == '-' || arr[i] == '/' || arr[i] == '*')
            {
                Element *e = (Element *)malloc(sizeof(Element));
                e->c = arr[i];
                push(s, *e);
                sym++;
            }
            else
            {

                *(str + strcount) = arr[i];
                strcount++;
            }
        }
    }
}
int main()
{
    printf("enter the postfix notation expression : \n");
    char *arr;
    scanf("%s", &arr);
    printf("enter length of expression: ");
    int n;
    scanf("%d", &n);
    evaluate(arr, n);
}
