#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node* next;
} Node;

typedef struct _linked_list {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

Node* new_Node(int data) {
    Node* node = (Node*) calloc(1,sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *new_LinkedList() {
    LinkedList* linkedList = (LinkedList*) calloc(1, sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->size = 0;
    return linkedList;
}


void LL_addToHead(LinkedList* linkedListRef, int data) {
    Node* node = new_Node(data);
    if(linkedListRef->size == 0) {
        linkedListRef->tail = node;
    } else {
        node->next = linkedListRef->head;
    }
    linkedListRef->head = node;
    linkedListRef->size++;
}

void LL_addToTail(LinkedList* linkedListRef, int data) {
    if(linkedListRef->size == 0 || linkedListRef->head == NULL) {
        LL_addToHead(linkedListRef, data);
    } else {
        Node* node = new_Node(data);
        linkedListRef->tail->next = node;
        linkedListRef->tail = linkedListRef->tail->next;
        linkedListRef->size++;
    }
}

Node* LL_getHead(LinkedList* linkedListRef) {
    return linkedListRef->head;
}

Node* LL_getTail(LinkedList* linkedListRef) {
    return linkedListRef->tail;
}

Node* LL_getIndex(LinkedList* linkedListRef, int index) {
    Node* aux = linkedListRef->head;
    for(int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux;
}

void LL_printList(LinkedList* linkedListRef) {
    if(linkedListRef->size == 0) {
        printf("Lista Vazia!!!\n");
    } else {
        Node* nodeAUX = linkedListRef->head;
        printf("Head -> ");
        while(nodeAUX != NULL) {
            printf("%i -> ", nodeAUX->data);
            nodeAUX = nodeAUX->next;
        }
        printf("Tail!\n");
    }
}

int LL_sizeList(LinkedList* linkedListRef) {
    return linkedListRef->size;
}

void LL_removeElement(LinkedList* linkedListRef, int data) {
    if(linkedListRef->size != 0) {
        Node* prev = NULL;
        Node* pos = linkedListRef->head;
        while(pos != NULL && pos->data != data) {
            prev = pos;
            pos = pos->next;
        }

        if(pos != NULL) {
            if(linkedListRef->tail == pos) {
                linkedListRef->tail = prev;
            }
            if(linkedListRef->head == pos) {
               linkedListRef->head = linkedListRef->head->next ;
            }
            else {
                prev->next = pos->next;
            }
            free(pos);
            linkedListRef->size--;
        }
    }
}

void LL_destroyLinkedList(LinkedList** linkedListRef) {
    printf("Destruindo LinkedList!\n");
    LinkedList* _LL = *linkedListRef;
    Node* aux = _LL->head;
    Node* deleted = NULL;
    while(aux != NULL) {
        deleted = aux;
        aux = aux->next;
        free(deleted);
    }
    free(_LL);
    *linkedListRef = NULL;
}

int main() {
    LinkedList *myLL = new_LinkedList();
    LL_addToHead(myLL, 5);
    LL_addToHead(myLL, 10);
    LL_addToHead(myLL, 15);
    LL_addToHead(myLL, 20);
    LL_addToTail(myLL, 19);
    LL_printList(myLL);
    LL_removeElement(myLL, 15);
    LL_printList(myLL);
    return 0;
}