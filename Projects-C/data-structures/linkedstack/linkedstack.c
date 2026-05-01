#include <stdio.h>
#include <stdio.h>
#include "linkedstack.h"

Stack* new_stack(){
        Stack* s = (Stack*)malloc(sizeof(Stack));
        s->head = NULL;
        return s;
}

Node* new_node(double e){
        Node* n = (Node*)malloc(sizeof(Node));
        n->element = e;
        n->next_node = NULL;
        return n;
}

void push(Stack* s, double e){
        Node* node = new_node(e);
        node->next_node = s->head;
        s->head = node;
}

double pop(Stack* s){
        double num;
        
        if(s->head == NULL)
                exit(10);
        
        num = s->head->element;
        Node* n = s->head;
        s->head = s->head->next_node;
        free(n);
        return num;        
}

int is_empty(Stack* s){
        return s->head == NULL;
}
