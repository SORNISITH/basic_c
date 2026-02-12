#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int x);
Node* push(Node* head, int value);
void display_list(Node* list);
void destroy_list(Node* list);

void push_p(Node** head, int value);
void pop(Node** list)
{
    if (*list == NULL) {
        return;
    }
    Node* temp = *list;
    *list = (*list)->next;
    free(temp);
}

int main(int argc, char* argv[])
{
    Node* List = NULL;
    push_p(&List, 10);
    push_p(&List, 20);
    push_p(&List, 30);
    push_p(&List, 40);
    push_p(&List, 50);
    display_list(List);
    destroy_list(List);
    return EXIT_SUCCESS;
}

void destroy_list(Node* list)
{
    if (list == NULL) {
        return;
    }
    destroy_list(list->next);
    free(list);
}

void display_list(Node* list)
{
    if (list == NULL) {
        return;
    }
    if (list->next == NULL) {
        printf("%d -> NULL ", list->value);
    } else {
        printf("%d -> ", list->value);
    }
    display_list(list->next);
}

Node* push(Node* head, int value)
{
    Node* new_node = create_node(value);
    if (head == NULL) {
        return new_node;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return new_node;
}

void push_p(Node** head, int value)
{
    Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

Node* create_node(int value)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
