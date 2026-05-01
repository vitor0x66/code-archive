
#include <stdlib.h>
#include "linkedlist.h"

Linked_list* new_linked_list(){

        Linked_list* list = (Linked_list*)malloc(sizeof(Linked_list));

        list->head = NULL;

        return list;
}

Node* new_node(int num){

        Node* node = (Node*)malloc(sizeof(Node));
        node->num = num;
        node->next = NULL;

        return node;
}

void add(Linked_list* list, int num){
        
        if(list->head == NULL) 
                list->head = new_node(num);
        else{
           
                Node* ptr = list->head;

                while (ptr->next != NULL){
                        ptr = ptr->next;
                }

                ptr->next = new_node(num);
        }
}

void remove(Linked_list* list, int num){
        if(list->head == NULL){ 
                printf("List empty\n");
                return;
        }
        else{
                Node* ptr = list->head;
                Node* last_ptr = NULL;

                int found = 0;

                do{
                        if(ptr->num == num){
                                found = 1;   
                                break;
                        }
                        last_ptr = ptr;
                        ptr = ptr->next;
                }while (ptr->next != NULL);

                if(found){
                        if(last_ptr != NULL)
                                last_ptr->next = ptr->next;
                        free(ptr);
                        printf("Item removed\n");
                        return;
                }
                else{
                        printf("Item not found\n");
                        return;
                }
        }
}
