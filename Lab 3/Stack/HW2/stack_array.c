#include "element.h"
#include "stack.h"
#include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};
Stack *newStack()
{
    Stack *s = (Stack *)mymalloc(sizeof(Stack));
    if (s != NULL)
        s->top = -1;
    return s;
}
bool push(Stack *s, Element e)
{
    if (s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

bool pop(Stack *s)
{

    if (isEmpty(s))
    {
        printf("underflow");
        return false;
    }
    else
    {
        s->top--;
    }
}
bool isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Element *top(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty");
        Element *e = NULL;
        return e;
    }
    else
    {
        int top = s->top;
        Element *e = &(s->data)[top];
        return e;
    }
}
void freeStack(Stack *s)
{
    s->top = -1;
}