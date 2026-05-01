#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

typedef struct Node{
        double element;
        Node* next_node;
} Node;

typedef struct Stack{
        Node* head;
} Stack;

Stack* new_stack();
Node* new_node(double e);
void push(Stack* s, double e);
double pop(Stack* s);
int is_empty(Stack* s);

#endif
