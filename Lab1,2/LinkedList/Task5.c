#include <stdio.h>
typedef struct node *NODE;
struct node
{
    int ele;
    NODE next;
};
typedef struct linked_list *LIST;
struct linked_list
{
    int count;
    NODE head;
};
LIST createNewList()
{
    LIST myList;
    myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}
NODE createNewNode(int value)
{
    NODE myNode;
    myNode = (NODE)malloc(sizeof(struct node));
    myNode->ele = value;
    myNode->next = NULL;
    return myNode;
}
void insertAfter(int searchEle, NODE n1, LIST l1)
{
    if (l1->head == NULL)
    {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }
    else
    {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL)
        {
            if (temp->ele == searchEle)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if (temp->next == NULL)
            {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}
void printList(LIST l1)
{
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL)
    {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}
int search(LIST L, int n)
{
    NODE ptr = L->head;
    int count = 0;
    while (ptr != NULL)
    {
        if (ptr->ele == n)
        {
            return count;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return -1;
}
LIST deleteFirst(LIST L)
{
    NODE temp = L->head;
    NODE n = L->head->next;
    free(temp);
    L->head = n;
    L->count--;
    return L;
}
LIST insertFirst(LIST l, int x)
{
    NODE n = createNewNode(x);
    n->next = l->head;
    l->head = n;
    l->count++;
    return l;
}
LIST deleteAt(LIST l, int n)
{

    NODE ptr;
    ptr = l->head;
    if (n >= 0 && n <= l->count)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->next;
        }
        NODE temp = ptr->next;
        if (ptr->next != NULL)
        {
            ptr->next = ptr->next->next;
            free(temp);
            l->count--;
        }
        else
        {
            ptr = NULL;
            l->count--;
        }
    }
    else
    {
        printf("not a valid element \n");
    }
    return l;
}
int main()
{
}