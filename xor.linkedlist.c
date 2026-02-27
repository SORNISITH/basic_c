#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int valueue;
    uintptr_t xor_Next;
} NODE;

typedef struct {
    NODE* head;
    NODE* tail;
    NODE* CURRENT;
    NODE* PREV;
} llist;

void prev_node(llist* list);
void next_node(llist* list);
NODE* new_node(int valueue);
void push(llist* list, int valueue);

int main(int argc, char* argv[])
{
    llist newlist = { 0 };

    push(&newlist, 10);
    push(&newlist, 20);
    push(&newlist, 30);
    push(&newlist, 40);
    push(&newlist, 50);
    push(&newlist, 60);
    push(&newlist, 70);

    next_node(&newlist);
    next_node(&newlist);
    return EXIT_SUCCESS;
}

void next_node(llist* list)
{
    if (list->CURRENT == NULL && list->PREV == NULL) {
        list->CURRENT = list->head;
        list->PREV = list->CURRENT;
        list->CURRENT->xor_Next = list->CURRENT->xor_Next ^ 0;
        printf("%d ", list->CURRENT->valueue);
        return;
    }
    NODE* next = (NODE*)list->CURRENT->xor_Next;
    list->PREV = list->CURRENT;
    list->CURRENT = next;
    printf("%d ", list->CURRENT->valueue);
    list->CURRENT->xor_Next ^= list->PREV->xor_Next;
}

void push(llist* list, int valueue)
{
    NODE* cn = new_node(valueue);
    if (cn == NULL)
        return;
    if (list->head == NULL && list->tail == NULL) {
        list->head = cn;
        list->tail = cn;
    } else {
        list->head->xor_Next ^= (uintptr_t)cn;
        cn->xor_Next ^= (uintptr_t)list->head;
        list->head = cn;
    }
}

NODE* new_node(int valueue)
{
    NODE* n = malloc(sizeof(*n));
    memset(n, 0, sizeof(*n));
    if (n == NULL)
        return NULL;
    n->valueue = valueue;
    return n;
}
