#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* link;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LLIST;

Node* middleNode(Node* head)
{
    if (head == NULL) {
        return NULL;
    }

    Node* ptr_slow = malloc(sizeof(*ptr_slow));
    Node* ptr_fast = head;
    ptr_slow = head;
    while (ptr_fast != NULL) {
        int index_ptr_fast = 0;
        while (ptr_fast != NULL && index_ptr_fast < 2) {
            ptr_fast = ptr_fast->link;
            index_ptr_fast++;
        }
        if (index_ptr_fast != 1) {
            ptr_slow = ptr_slow->link;
        }
    }
    return ptr_slow;
}
void push(LLIST* list, int val)
{
    Node* newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) {
        return;
    }
    newNode->value = val;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->link = NULL;
    } else {
        newNode->link = list->head;
        list->head = newNode;
    }
}

void display(Node* list)
{
    if (list == NULL) {
        return;
    }
    printf("%d-", list->value);
    display(list->link);
}

int main(int argc, char* argv[])
{
    LLIST* mylist = malloc(sizeof(*mylist));
    mylist->head = NULL;
    mylist->tail = NULL;
    for (int i = 99; i >= 1; i--) {
        push(mylist, i);
    }

    display(mylist->head);

    Node* middle = middleNode(mylist->head);
    printf("\n%d", middle->value);
    Node* tmp = mylist->head;
    while (tmp != NULL) {
        Node* next = tmp->link;
        free(tmp);
        tmp = next;
    }
    free(mylist);
    return 0;
}
