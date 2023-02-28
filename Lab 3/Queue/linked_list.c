#include "linked_list.h"
#include "element.h"
#include "heap_usage.h"
#include <stdio.h>
List *createNewList()
{
    List *l = (List *)malloc(sizeof(List));
    l->count = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}
Node createNewNode(Element data)
{
    Node n = (Node)malloc(sizeof(Node));
    n->data.int_value = data.int_value;
    n->data.float_value = data.float_value;
    n->next = NULL;
    return n;
}
// }
// void insertFirst(Node node, List *list)
// {
//     if (list->count == 0)
//     {
//         Node n = (Node)malloc(sizeof(Node));
//         n->data = node->data;
//         n->next = NULL;
//         list->head = n;
//         list->tail = n;
//     }
//     node->next = list->head;
//     list->head = node;
//     list->count++;
// }

// void removeLast(List *list)
// {

//     Node node = list->head;
//     list->head = node->next;

//     free(node);
//     list->count--;
//     if (list->count == 0)
//     {
//         list->tail = NULL;
//     }
// }
void insertLast(Node n, List *l)
{
    if (l->count == 0)
    {
        l->head = n;
        l->tail = n;
        l->count++;

        return;
    }
    l->tail->next = n;
    l->tail = n;
    l->count++;
}
void removeFirst(List *l)
{
    if (l->count == 0)
    {
        printf("list is empty\n");
        return;
    }
    if (l->count == 1)
    {
        l->head = NULL;
        l->tail = NULL;
        l->count--;
        return;
    }
    l->head = l->head->next;
    l->count--;
}

void destroyList(List *list)
{
    while (list->head != NULL)
    {
        removeFirst(list);
    }
}

// 1 2 3 4 5 6 7 8 9
//