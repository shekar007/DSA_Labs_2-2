#include "queue.h"
// #include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->arr = (Element *)malloc(SIZE_QUEUE * sizeof(Element *));
    q->first = 0;
    q->last = 0;
    q->size = 0;
    return q;
}
// 1 2 3 _ _ _
bool enqueue(Queue *q, Element element)
{
    if (q->size == 0)
    {
        q->arr[0] = element;
        q->size++;
        return true;
    }
    if (q->size == SIZE_QUEUE)
    {
        return false;
    }
    int last = q->last;
    last = (last + 1) % (q->size);

    (q->arr)[last] = element;
    q->size++;
    q->last = last;
    return true;
}
bool dequeue(Queue *q)
{
    if (size(q) == 0)
    {
        return false;
    }
    else
    {
        if (q->size == 1)
        {
            q->size = 0;
            return true;
        }
        int first = q->first;
        first = (first + 1) % (SIZE_QUEUE);
        q->size--;
        q->first = first;
        return true;
    }
}
Element *front(Queue *q)
{
    if (!size(q))
    {
        printf("queue empty");
        return NULL;
    }
    else
    {
        Element *e = &(q->arr[(q->first)]);
        return (e);
    }
}
int size(Queue *q)
{
    return q->size;
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
    free(queue->arr);
    printf("queue freed");
}