#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev; // doubly test
} Node;

Node* Front = NULL;
Node* Rear = NULL;

Node* new_node(int value);
void free_que_list(Node* head);
void enque(int value);
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
void enque(int value)
{
    Node* c_node = new_node(value);
    if (Front == NULL) {
        Front = c_node;
        Rear = c_node;
    };
    Rear->next = c_node;
    c_node->prev = Rear;
    Rear = c_node;
}

void display_que_list(Node* head)
{
    if (head == NULL) {
        return;
    }
    printf("%d -> ", head->value);
    display_que_list(head->next);
}

Node* new_node(int value)
{
    Node* mynode = malloc(sizeof(Node));
    if (mynode == NULL) {
        printf("No memory for Headp --atemp callback");
        return new_node(value);
    }
    mynode->next = NULL;
    mynode->prev = NULL;
    mynode->value = value;
    return mynode;
}
