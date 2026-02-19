#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev; // doubly test
} Node;

typedef struct LINKED_LIST {
    Node* Front;
    Node* Rear;
} LINKED_LIST;

Node* new_NODE(int value);
void free_que_list(Node* head);
void enque(int value);
void display_que_list(Node* head);

void deque(Node* Front)
{
    Node* temp = Front->next;
    free(Front);
    Front = temp;
}

int main(int argc, char* argv[])
{
    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    deque();
    deque();

    display_que_list(Front);
    free_que_list(Front);
    return EXIT_SUCCESS;
}
void free_que_list(Node* head)
{
    while (head != NULL) {
        Node* temp = head->next;
        free(head);
        head = temp;
    }
}
void enque(int value)
{
    Node* c_NODE = new_NODE(value);
    if (Front == NULL) {
        Front = c_NODE;
        Rear = c_NODE;
    };
    Rear->next = c_NODE;
    c_NODE->prev = Rear;
    Rear = c_NODE;
}

void display_que_list(Node* head)
{
    if (head == NULL) {
        return;
    }
    printf("%d -> ", head->value);
    display_que_list(head->next);
}

Node* new_NODE(int value)
{
    Node* myNODE = malloc(sizeof(Node));
    if (myNODE == NULL) {
        printf("No memory for Headp --atemp callback");
        return new_NODE(value);
    }
    myNODE->next = NULL;
    myNODE->prev = NULL;
    myNODE->value = value;
    return myNODE;
}
