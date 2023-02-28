/*
Write a function rotate() that takes a linked list of integers as input and rotates the
elements left/anticlockwise/towards head by k steps. You will need to create your own linked
list of integers for this, before implementing the above function.
33
For example, if the linked list originally was [HEAD] -> 1 -> 2 -> 3 -> 4 -> 5 ->
[NULL], and k = 2, then the linked list should become [HEAD] -> 3 -> 4 -> 5 -> 1 ->
2 -> [NULL].
[Hint: For solving the problem, it may be helpful to make the linked list circular first.]
*/
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
typedef struct Node Node;
struct Node
{
    int val;
    Node *next;
};
void printLL(Node **n)
{
    Node *ptr = *n;
    while (ptr != NULL)
    {
        printf("%d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(Node **ptr, int n)
{
    Node *temp = (Node *)malloc(sizeof(Node *));
    temp->next = *ptr;
    temp->val = n;
    *ptr = temp;
}
Node *createLL(int arr[])
{
    Node *head = NULL;
    size_t l = 5;
    for (int i = l - 1; i >= 0; i--)
    {
        insert(&head, arr[i]);
    }
    Node *ptr = head;
    return head;
}
Node *createCLL(int arr[])
{
    Node *head = NULL;
    size_t l = 5;
    for (int i = l - 1; i >= 0; i--)
    {
        insert(&head, arr[i]);
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;
    return head;
}
void printCLL(Node *head)
{
    Node *ptr = head;
    int c = 0;
    do
    {
        c = 1;
        printf("%d", ptr->val);
        ptr = ptr->next;
    } while (ptr != head);
}
void shift(Node **start, int n)
{
    // 1 2 3 4 5
    //
    Node *h1 = (*start);
    Node *h2 = (*start);
    Node *ptr = *start;
    int x = ptr->val;
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            ptr->val = ptr->next->val;
            ptr = ptr->next;
        }
    }
    do
    {
        h1 = h1->next;
    } while (h1->next != h2);
    h1->val = x;
}
Node *reverse(Node **head)
{

    Node *prev = NULL;
    Node *curr = *head;
    Node *f = curr->next;
    if (curr->next != NULL)
    {
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = f;
            if (f != NULL)
            {
                f = f->next;
            }
        }
        return prev;
    }
    else
    {
        return curr;
    }
}
Node *revRecursion(Node **head)
{
    Node *h = *head;
    if ((*(head))->next == NULL)
    {
        return *head;
    }
    Node *h2 = revRecursion(&((*head)->next));
    Node *ptr = h2;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = *head;
    return h2;
    // 1 5432
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *n = createLL(arr);
    printLL(&n);
    n = revRecursion(&n);
    printLL(&n);
}
