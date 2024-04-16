#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    struct _node* prev;
    int data;
    struct _node* next;
} Node;

typedef struct _Dual_linked_list {
    Node* begin;
    Node* end;
} DualLinkedList;

Node* new_Node(int data) {
    Node* node = (Node*) calloc(1, sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    return node;
}

DualLinkedList* new_DualLinkedList() {
    DualLinkedList* dualLinkedList = (DualLinkedList*) calloc(1, sizeof(DualLinkedList));
    dualLinkedList->begin = NULL;
    dualLinkedList->end = NULL;
    return dualLinkedList;
}

bool DLL_isEmpty(DualLinkedList* DLLref) {
    return (DLLref->begin == NULL);
}

void DLL_add(DualLinkedList* DLLref, int data) {
    Node* node = new_Node(data);
    if(DLL_isEmpty(DLLref)) {
        DLLref->begin = node;
        DLLref->end = DLLref->begin;
    } else {
        node->next = DLLref->begin;
        DLLref->begin->prev = node;
        DLLref->begin = node;
    } 
}

void DLL_print(DualLinkedList* DLLref) {
    printf("Begin -> ");
    if(DLL_isEmpty(DLLref)) {
        printf(" Lista vazia! ");
    } else {
        Node* aux = DLLref->begin;
        while(aux != NULL) {
            printf("%d <-> ", aux->data);
            aux = aux->next;
        }
    }
    printf("<- End");
}

int main() {
    DualLinkedList* myDLL = new_DualLinkedList();
    DLL_add(myDLL,1);
    DLL_add(myDLL,2);
    DLL_add(myDLL,3);
    DLL_add(myDLL,4);
    DLL_add(myDLL,5);
    DLL_print(myDLL);
    printf("\n%i", myDLL->begin->data);
    return 0;
}