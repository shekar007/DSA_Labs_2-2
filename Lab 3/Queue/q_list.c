#include "q_list.h"
#include <stdio.h>
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue) * SIZE_QUEUE);
    q->l = createNewList();
    return q;
}
bool enqueue(Queue *q, Element element)
{
    List *l = q->l;
    Node n = createNewNode(element);
    insertLast(n, l);
    return true;
}
bool dequeue(Queue *q)
{
    List *l = q->l;
    removeFirst(q->l);
}
Element *front(Queue *q)
{
    if (q->l->count == 0)
    {
        printf("queue is empty! \n");
    }
    else
    {
        Element *e = &(q->l->head->data);
        return e;
    }
}
int size(Queue *queue)
{
    queue->l->count;
}
bool isEmpty(Queue *queue)
{
    if (size(queue) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void destroyQueue(Queue *queue)
{
    free(queue->l);
    free(queue);
    printf("queue freed! \n");
}
