#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int valueue;
    struct Node* next;
} Node;

void display_linked_list(Node* List)
{
    if (List == NULL)
        return;
    printf("%d -> ", List->valueue);
    display_linked_list(List->next);
}

void display_linked_list_rev(Node* List)
{
    if (List == NULL)
        return;
    display_linked_list_rev(List->next);
    printf(" <- %d", List->valueue);
}

Node* reverseList(Node* List)
{
    if (List->next == NULL) {
        return List;
    }
    Node* rev_Head = reverseList(List->next);
    List->next->next = List;
    List->next = NULL;
    return rev_Head;
}

Node* create_list(int element)
{
    Node* Head = NULL;
    for (int i = 1; i < 5; i++) {
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return NULL;
        }
        newNode->valueue = 10 * i;
        newNode->next = Head;
        Head = newNode;
    }
    return Head;
}
void destroy_list(Node* List)
{
    while (List != NULL) {
        Node* next = List->next;
        free(List);
        List = next;
    }
}
int main(int argc, char* argv[])
{
    Node* Linked_List = create_list(10);
    // Head = reverseList(Head);
    printf("Original L : ");
    display_linked_list(Linked_List);
    printf("\n");
    Linked_List = reverseList(Linked_List);
    printf("Format 1 : ");
    display_linked_list(Linked_List);
    printf("\n");
    printf("Format 2 : ");
    display_linked_list_rev(Linked_List);
    destroy_list(Linked_List);
    return EXIT_SUCCESS;
}

Node* reverse_linked_list(Node* List)
{
    Node* current = List;
    Node* next = NULL;
    Node* prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    List = prev;
    return List;
}
