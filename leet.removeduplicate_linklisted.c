#include "stdio.h"
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct LINKEDLIST {
    struct ListNode* Head;
    struct ListNode* Tail;
};

void pushNode(struct LINKEDLIST* l, int value)
{
    struct ListNode* newNode = malloc(sizeof(*newNode));
    if (newNode == NULL)
        return;
    newNode->next = (l->Head == NULL) ? NULL : l->Head;
    newNode->val = value;
    l->Head = newNode;
}

void display_list(struct ListNode* ll)
{
    if (ll == NULL)
        return;
    printf("%d ", ll->val);
    display_list(ll->next);
}
void kill_list(struct ListNode* ll)
{
    if (ll == NULL) {
        return;
    }
    kill_list(ll->next);
    free(ll);
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* finder_current = head;
    struct ListNode* finder_next = head->next;
    while (finder_next != NULL) {
        if (finder_current->val == finder_next->val) {
            struct ListNode* tmp_replacer = finder_next;
            finder_current->next = finder_next->next;
            free(tmp_replacer);
            finder_next = finder_current->next;
        } else {
            finder_current = finder_current->next;
            finder_next = finder_current->next;
        }
    }
    return head;
}

int main(int argc, char* argv[])
{
    struct LINKEDLIST* mylist = malloc(sizeof(*mylist));
    mylist->Head = NULL;
    mylist->Tail = NULL;
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 3);
    pushNode(mylist, 2);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    pushNode(mylist, 1);
    display_list(mylist->Head);
    mylist->Head = deleteDuplicates(mylist->Head);
    printf("\n");
    display_list(mylist->Head);
    //    mylist->Head = deleteDuplicates(mylist->Head);
    printf("\n");
    kill_list(mylist->Head);
    free(mylist);
    return 0;
}
