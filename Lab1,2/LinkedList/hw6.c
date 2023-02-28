#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
typedef struct Node Node;
typedef struct Num Num;
typedef struct LinkedList LL;
struct Node
{
    int data;
    Node *next;
};
struct Num
{
    Node *head;
};
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
void insert(Node **ptr, int n)
{
    Node *temp = (Node *)malloc(sizeof(Node *));
    temp->next = *ptr;
    temp->data = n;
    *ptr = temp;
}
Node *add(Node **n1, Node **n2)
{
    Node *sum;
    Node *a = (*n1);
    Node *b = (*n2);
    int c = 0;
    while (a != NULL && b != NULL)
    {

        int s = a->data + b->data + c;
        insert(&sum, s);
        if (s > 9)
        {
            c = 1;
        }
        a = a->next;
        b = b->next;
    }
    if (a != NULL)
    {
        while (a != NULL)
        {
            insert(&sum, a->data);
            a = a->next;
        }
    }

    if (b != NULL)
    {
        while (b != NULL)
        {
            insert(&sum, b->data);
            b = b->next;
        }
    }
    return sum;
}
Node *createLL(int arr[])
{
    Node *head = NULL;
    size_t l = 3;
    for (int i = l - 1; i >= 0; i--)
    {
        insert(&head, arr[i]);
    }
    Node *ptr = head;
    return head;
}
void printLL(Node **n)
{
    Node *ptr = *n;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3};
    int brr[] = {1, 2, 3};
    Node *a = createLL(arr);
    Node *b = createLL(brr);
    printLL(&a);
    printLL(&b);
    Node *sum = add(&a, &b);
    sum = reverse(&sum);
    printLL(&sum);
}
