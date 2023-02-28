#include "q_list.h"
#include <stdio.h>
#include <time.h>

int main()
{
    // {
    //     long start = clock();

    Queue *s = createQueue();
    if (isEmpty(s))
    {
        printf("Queue is empty\n");
    }
    Element one;
    Element two;
    Element three;
    Element four;
    Element five;
    one.int_value = 1;
    two.int_value = 2;
    three.int_value = 3;
    four.int_value = 4;
    five.int_value = 5;
    printf("yaha tak 1 \n");
    enqueue(s, one);
    if (isEmpty(s))
    {
        printf("Queue empty hai\n");
    }
    printf("Element at front: %d", front(s)->int_value);
    printf("\n");
    printf("front printed\n");
    dequeue(s);
    printf("dequeued\n");
    if (isEmpty(s))
    {
        printf("Queue not empty\n");
    }
    else
    {
        printf("queue empty.\n");
    }
    enqueue(s, one);
    printf("enqueued\n");
    enqueue(s, two);
    printf("enqueued\n");
    printf("Element at front: %d", front(s)->int_value);
    printf("\n");
    dequeue(s);

    printf("Element at front: %d", front(s)->int_value);
    printf("\n");
    // long end = clock();
    // printf("Time elapsed: %f", (end - start) / ((double)(CLOCKS_PER_SEC)));
    // Time elapsed: 0.000194 - linked list

    // time elapsed  0.000215 - array

    return 0;
}
