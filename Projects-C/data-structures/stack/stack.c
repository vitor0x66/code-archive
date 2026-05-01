#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
size_t index = 0;

void push(int e){
        stack[index++] = e;
}

int pop(){
        if(index == 0) return -1;
        return stack[--index];
}
