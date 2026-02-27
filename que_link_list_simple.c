#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valueue;
    struct Node* next;
    struct Node* prev; // doubly test
} Node;

Node* Front = NULL;
Node* Rear = NULL;

Node* new_NODE(int valueue);
void free_que_list(Node* head);
void enque(int valueue);
void display_que_list(Node* head);
void deque()
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
void enque(int valueue)
{
    Node* c_NODE = new_NODE(valueue);
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
    printf("%d -> ", head->valueue);
    display_que_list(head->next);
}

Node* new_NODE(int valueue)
{
    Node* myNODE = malloc(sizeof(Node));
    if (myNODE == NULL) {
        printf("No memory for Headp --atemp callback");
        return new_NODE(valueue);
    }
    myNODE->next = NULL;
    myNODE->prev = NULL;
    myNODE->valueue = valueue;
    return myNODE;
}
