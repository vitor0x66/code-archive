#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
        int value;
        struct Node * left;
        struct Node * middle;
        struct Node * right;
}Node;


typedef struct Tree{
        Node* top;
}Tree;

Node* new_node(int v){
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = v;
        node->left = NULL;
        node->right = NULL;
        node->middle = NULL;
        return node;
}

Tree* new_tree(int value){
        Tree* tree = (Tree*)malloc(sizeof(Tree));
        tree->top = new_node(value);
        return tree;
}


void addNode(int v, Tree* tree){

        Node* ptr = tree->top;
        Node* next = NULL;
        if(ptr == NULL)
                tree->top = new_node(v);
        else{
                while(1){
                        if(ptr->value < v){
                                if(ptr->right == NULL){
                                        ptr->right = new_node(v);
                                        return;
                                }
                                ptr = ptr->right;
                        }
                        if(ptr->value > v){
                                if(ptr->left == NULL){
                                        ptr->left = new_node(v);
                                        return;
                                }
                                ptr = ptr->left;
                        }
                        if(ptr->value == v){
                                if(ptr->middle == NULL){
                                        ptr->middle = new_node(v);
                                        return;
                                }
                                ptr = ptr->middle;
                        }
                        
                }
        } 
}

void printNodeXML(Node *node , FILE* fp){
        fprintf(fp, "<node>\n");
        fprintf(fp, "  <value>%d</value>\n", node->value);
        if (node->left != NULL){
                fprintf (fp, "<left>\n");
                printNodeXML(node->left, fp);
                fprintf (fp, "</left>\n");
        }
        if (node->right != NULL){
                fprintf(fp, "<right>\n" );
                printNodeXML(node->right, fp);
                fprintf (fp, "</right>\n" );
        }
        if (node->middle != NULL){
                fprintf(fp, "<middle>\n" );
                printNodeXML(node->middle, fp);
                fprintf (fp, "</middle>\n" );
        }
        fprintf(fp, "</node>\n");
}

void printTreeXML(Tree * tree){
        FILE * fp = fopen("Tree.xml", "w+");
        fprintf(fp, "<tree>\n");
        if (tree->top != NULL)
                printNodeXML(tree->top, fp);
        fprintf(fp, "</tree>\n");
        fclose(fp);
}

int main(){
        srand(284043);
        /*Primeira arvore
        Tree* tree = new_tree((rand() % 19));
        for(int i = 0; i < 30; i++)
                addNode((rand() % 19), tree);
        printTreeXML(tree);
        */

        //Segunda arvore
        Tree* tree = new_tree((rand() % 19));
        for(int i = 0; i < 100; i++)
                addNode((rand() % 299), tree);
        printTreeXML(tree);

        return 0;
}
