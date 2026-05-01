#include <stdio.h>
#include "queue.h"

Queue* new_queue(){
        Queue *queue = (Queue*)malloc(sizeof(Queue));
        queue->front = -1;
        queue->back = 0;
        return queue;
}

int dequeue(Queue* queue){
        int element;

        if(queue->isfull){
                queue->isfull = 0;
                element = queue->elements[queue->front];
        }

        if((queue->front + 1 == queue->back) || (queue->front == MAX_SIZE-1 && queue->back == 0))
                queue->isempty = 1;
        
        if(queue->front == MAX_SIZE-1)
                queue->front = 0;
        else
                queue->front += 1;
}

void enqueue(Queue* queue, int a){
        if(queue->front == -1)
                queue->front++;
        
        if(queue->isfull){
                printf("is full\n");
                return;
        }

        if(queue->isempty)
                queue->isempty = 0;

        queue->elements[queue->back] = a;

        if((queue->back + 1 == queue->front) || (queue->back == MAX_SIZE-1 && queue->front == 0))
                queue->isfull = 1;

        if(queue->back == MAX_SIZE-1)
                queue->back = 0;
        else
                queue->back++;
}
