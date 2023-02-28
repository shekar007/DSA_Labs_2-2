#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "element.h"

struct Node
{
    Element data;
    struct Node *next;
};
typedef struct Node Node;

struct LinkedList
{
    int count;
    Node *head;
    // NODE tail; // Not required for stack. Required for Queue
};
typedef struct LinkedList List;

List *createNewList();
// This function allocates memory for a new list and returns a pointer to it.
// The list is empty and the count is set to 0.

Node *createNewNode(Element data);
// This function allocates memory for a new node and returns a pointer to it.
// The next pointer is set to NULL and the data is set to the value passed in.

void insertNodeIntoList(Node *node, List *list);
// This function inserts a node at the beginning of the list.

void removeFirstNode(List *list);
// This function removes the first node from the list.

// void insertNodeAtEnd(NODE node, LIST list); // Not required for stack. Required for Queue
// This function inserts a node at the end of the list.

void destroyList(List *list);
#endif