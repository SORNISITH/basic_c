#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    uintptr_t xptr;
    struct Node* next;
};
struct LINKED_LISTED_XOR {
    struct Node* Head;
    struct Node* Tail;
};
struct LLXOR_STEP {
    uintptr_t prev;
    uintptr_t next;
    struct Node* current;
} LLXOR_STEP;
enum MODES {
    NORMAL,
    REVERSE
};

struct LINKED_LISTED_XOR*
NEW_LIST_XOR();
struct LINKED_LISTED_XOR* LLX_push(struct LINKED_LISTED_XOR* list, int value);
void LLX_LOOP_NEXT_STEP(struct LINKED_LISTED_XOR* list, void (*func)(struct Node* current_list), short mode);
void LLX_KILLS(struct LINKED_LISTED_XOR* list);

void LLX_display(struct LINKED_LISTED_XOR* list, short mode);
// UTILITES
uintptr_t X0R(uintptr_t prev, uintptr_t current);
void util_print_current_value(struct Node* current_list);
void util_kill_an_list(struct Node* current_list);
bool util_check_null_list(struct Node* list);

int main()
{
    struct LINKED_LISTED_XOR* mylist = NEW_LIST_XOR();

    mylist = LLX_push(mylist, 10);
    mylist = LLX_push(mylist, 20);
    mylist = LLX_push(mylist, 30);
    mylist = LLX_push(mylist, 30);
    mylist = LLX_push(mylist, 40);
    mylist = LLX_push(mylist, 90);

    LLX_display(mylist, NORMAL);
    printf("\n");
    LLX_display(mylist, REVERSE);
    LLX_KILLS(mylist);
    return 0;
}

struct LINKED_LISTED_XOR* LLX_push(struct LINKED_LISTED_XOR* list, int value)
{
    struct Node* new_node = malloc(sizeof(*new_node));
    new_node->value = value;
    if (util_check_null_list(list->Head)) {
        list->Head->xptr = X0R((uintptr_t)new_node, list->Head->xptr);
        new_node->xptr = (uintptr_t)list->Head;
        new_node->next = list->Head;
        list->Head = new_node;
    } else {
        // init list here !
        new_node->next = nullptr;
        new_node->xptr = 0;
        list->Head = new_node;
        list->Tail = new_node;
    }
    return list;
}

void LLX_KILLS(struct LINKED_LISTED_XOR* list)
{
    if (list != NULL) {
        if (util_check_null_list(list->Head)) {
            LLX_LOOP_NEXT_STEP(list, util_kill_an_list, NORMAL);
        }
        if (list != NULL) {
            free(list);
        }
    }
}

void util_kill_an_list(struct Node* current_list)
{
    if (util_check_null_list(current_list)) {
        free(current_list);
    }
}

void LLX_display(struct LINKED_LISTED_XOR* list, short mode)
{
    if (util_check_null_list(list->Head)) {
        LLX_LOOP_NEXT_STEP(list, util_print_current_value, mode);
    }
}

void LLX_LOOP_NEXT_STEP(struct LINKED_LISTED_XOR* list, void (*func)(struct Node* current_list), short mode)
{
    if (util_check_null_list((mode == NORMAL ? list->Head : list->Tail))) {
        struct LLXOR_STEP controll_step;
        controll_step.prev = 0;
        controll_step.current = (mode == NORMAL) ? list->Head : list->Tail;
        while (controll_step.current) {
            controll_step.next = X0R(controll_step.prev, controll_step.current->xptr);
            controll_step.prev = (uintptr_t)controll_step.current;
            func(controll_step.current);
            controll_step.current = (struct Node*)controll_step.next;
        }
    }
}

struct LINKED_LISTED_XOR* NEW_LIST_XOR()
{
    struct LINKED_LISTED_XOR* l = malloc(sizeof(*l));
    l->Head = NULL;
    l->Tail = NULL;
    return l;
}
uintptr_t X0R(uintptr_t prev, uintptr_t current)
{
    return prev ^ current;
}

void util_print_current_value(struct Node* current_list)
{
    if (util_check_null_list(current_list)) {
        printf("%d -> ", current_list->value);
    }
}

bool util_check_null_list(struct Node* list)
{
    return list != NULL ? true : false;
}
// void LLX_display(struct Node* header)
// {
//     if (header == nullptr) {
//         return;
//     }
//     struct LLXOR_MOVE_POSITION* list;
//     list->current = header;
//     list->prev = 0;
//     while (list->current) {
//         printf("%d -> ", list->current->value);
//         list->next = X0R(list->prev, list->current->xptr);
//         list->prev = (uintptr_t)list->current;
//         list->current = (struct Node*)list->next;
//     }
// }
