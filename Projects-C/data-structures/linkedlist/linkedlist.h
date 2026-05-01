#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node{

        int num;
        Node* next;

}Node;

typedef struct Linked_list{

        Node* head;

} Linked_list;

Node* new_node();
Linked_list* new_linked_list();
void add(Linked_list* list, int num);
void remove(Linked_list* list, int value);

#endif
