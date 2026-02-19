// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
// /**
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

void display(struct ListNode* h);
struct ListNode* newnode(int x);
struct ListNode* push(struct ListNode* head, int x);
struct ListNode* swapPairs(struct ListNode* head);
int main(int argc, [[maybe_unused]] char* argv[])
{
    struct ListNode* myhead = NULL;
    myhead = push(myhead, 10);
    myhead = push(myhead, 20);
    myhead = push(myhead, 30);
    myhead = push(myhead, 40);

    myhead = swapPairs(myhead);

    display(myhead);
    return EXIT_SUCCESS;
}

bool myfn()
{
    return true;
}
struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL)
        return head;
    struct ListNode* temp = malloc(sizeof(*temp));

    temp = head->next;
    head->next = temp->next;
    temp = head;

    printf("xxx");
    return head;
}
void display(struct ListNode* h)
{
    if (h == NULL) {
        return;
    }
    printf("%d-", h->val);
    display(h->next);
}

struct ListNode* push(struct ListNode* head, int x)
{
    struct ListNode* cnode = newnode(x);
    if (head == NULL) {
        head = cnode;
        return head;
    }
    cnode->next = head;
    head = cnode;

    return head;
}

struct ListNode* newnode(int x)
{
    struct ListNode* n = malloc(sizeof(*n));
    if (n == NULL)
        return NULL;

    n->val = x;
    n->next = NULL;
    return n;
}
