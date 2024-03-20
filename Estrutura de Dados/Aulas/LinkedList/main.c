#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _linked_list {
    Node *head;
    int size;
} LinkedList;

Node *new_Node(int data) {
    Node *node = (Node*) calloc(1, sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *new_LinkedList() {
    LinkedList *linkedList = (LinkedList*) calloc(1,sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->size = 0;
    return linkedList;
}

//void add(LinkedList **linkedListRef, int data) {}

void LL_addFirst(LinkedList **linkedListRef, int data) {
    LinkedList *LL = *linkedListRef;
    Node *nodeRef = new_Node(data);
    nodeRef->next = LL->head;
    LL->head = nodeRef;
    LL->size++;
}

void LL_print(LinkedList *linkedListRef) {
    Node *next;
    next = linkedListRef->head;
    while(next != NULL) {
        printf("%i\n", next->data);
        next = next->next;
    }
}

int main() {
    LinkedList *myLL = new_LinkedList();
    LL_addFirst(&myLL, 5);
    LL_addFirst(&myLL, 10);
    LL_addFirst(&myLL, 15);
    LL_addFirst(&myLL, 20);
    LL_print(myLL);
    return 0;
}