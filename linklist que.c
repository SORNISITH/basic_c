#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Que {
    int Size;
    Node* Front;
    Node* Rear;
} Que;

void enque(Que* q, int value);
Que* create_que();
Node* create_note(int value);

int main(int argc, char* argv[])
{
    Que* que = create_que();

    enque(que, 10);
    enque(que, 30);
    enque(que, 40);
    enque(que, 50);

    return EXIT_SUCCESS;
}

void enque(Que* q, int value)
{
    Node* NODE = create_note(value);
    if (q->Front == NULL) {
        q->Front = q->Rear = NODE;
    } else {
        q->Rear->next = NODE;
        q->Rear = NODE;
    }
    q->Size++;
}

Que* create_que()
{
    Que* q = malloc(sizeof(Que));
    q->Front = q->Rear = NULL;
    q->Size = 0;
    return q;
}

Node* create_note(int value)
{
    Node* new_NODE = malloc(sizeof(Node));
    new_NODE->value = value;
    new_NODE->next = NULL;
    return new_NODE;
}
