#include "stack.h"
#include "linked_list.h"
struct Stack
{
    List *l;
};
Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL)
    {
        s->l = createNewList();
    }
    else
    {
        printf("Not enough space available");
    }
    return s;
}
// push pop isempty top newstack freestack
bool push(Stack *stack, Element element)
{
    Node *n = createNewNode(element);
    insertNodeIntoList(n, stack->l);
}
Element *top(Stack *stack)
{
    Node *n = stack->l->head;
    Element *e = &(n->data);
    return e;
}

bool pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty \n");
        return false;
    }
    else
    {
        removeFirstNode(s->l);
        return true;
    }
}
bool isEmpty(Stack *stack)
{
    if (stack->l->count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void freeStack(Stack *stack)
{
    destroyList(stack->l);
}
