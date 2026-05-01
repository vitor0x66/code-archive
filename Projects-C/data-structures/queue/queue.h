#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Queue{

        int elements[MAX_SIZE];
        int front;
        int back;
        int isfull;
        int isempty;

} Queue;

Queue* new_queue();
int dequeue(Queue* queue);
void enqueue(Queue* queue, int e);

#endif
