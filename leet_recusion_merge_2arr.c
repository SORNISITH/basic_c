#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int value;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int value;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
struct ListNode* push_node(struct ListNode* list, int x);
void display_node(struct ListNode* list);
void kill_node(struct ListNode* list);

int main(void)
{

    struct ListNode* first_list = NULL;
    struct ListNode* second_list = NULL;

    first_list = push_node(first_list, 10);
    first_list = push_node(first_list, 2);
    first_list = push_node(first_list, 1);

    second_list = push_node(second_list, 9);
    second_list = push_node(second_list, 3);
    second_list = push_node(second_list, 0);

    struct ListNode* M_list = mergeTwoLists(first_list, second_list);

    // mergeTwoLists(first_list, second_list);
    display_node(first_list);
    printf("\n");
    display_node(second_list);
    printf("\n");
    display_node(M_list);

    kill_node(first_list);
    kill_node(second_list);
    kill_node(M_list);
    // kill_node();

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    // Base cases
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // Choose smaller node
    if (list1->value < list2->value) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

struct ListNode* push_node(struct ListNode* list, int x)
{
    if (list == NULL) {
        struct ListNode* new_note = malloc(sizeof(*new_note));
        new_note->value = x;
        new_note->next = NULL;
        list = new_note;
        return new_note;
    } else {
        struct ListNode* new_note = malloc(sizeof(*new_note));
        new_note->next = list;
        new_note->value = x;
        list = new_note;
        return new_note;
    }
}
//
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
// {
//     if (list1 == NULL && list2 == NULL) {
//         return NULL;
//     }
//     struct ListNode* m_list = NULL;
//     struct ListNode *x = list1, *y = list2;
//     //
//     size_t init_arr_size = 5;
//     int* temp_arr = malloc(sizeof(int) * init_arr_size);
//     int index = 0;
//
//     while (x && y) {
//         if (index >= init_arr_size) {
//             init_arr_size *= 2;
//             temp_arr = realloc(temp_arr, sizeof(int) * init_arr_size);
//         }
//         if (x->value <= y->value) {
//             temp_arr[index++] = x->value;
//             x = x->next;
//         } else {
//             temp_arr[index++] = y->value;
//             y = y->next;
//         }
//     }
//     while (x) {
//         if (index >= init_arr_size) {
//             init_arr_size *= 2;
//             temp_arr = realloc(temp_arr, sizeof(int) * init_arr_size);
//         }
//         temp_arr[index++] = x->value;
//         x = x->next;
//     }
//     while (y) {
//         if (index >= init_arr_size) {
//             init_arr_size *= 2;
//             temp_arr = realloc(temp_arr, sizeof(int) * init_arr_size);
//         }
//         temp_arr[index++] = y->value;
//         y = y->next;
//     }
//
//     for (int i = index - 1; i >= 0; i--) {
//         m_list = push_node(m_list, temp_arr[i]);
//     }
//     free(temp_arr);
//     return m_list;
// }
// TODO : enque
struct ListNode* enque_node(struct ListNode* list, int x)
{
    if (list == NULL) {
        struct ListNode* new_note = malloc(sizeof(*new_note));
        new_note->value = x;
        new_note->next = NULL;
        list = new_note;
        return new_note;
    } else {
        struct ListNode* new_note = malloc(sizeof(*new_note));
        new_note->value = x;
        list->next = new_note;
        list = new_note;
        return new_note;
    }
};

void display_node(struct ListNode* list)
{
    if (list == NULL)
        return;
    printf("%d-", list->value);
    display_node(list->next);
}

void kill_node(struct ListNode* list)
{
    if (list == NULL)
        return;
    kill_node(list->next);
    free(list);
}
