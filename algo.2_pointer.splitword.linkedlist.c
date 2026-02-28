
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct arr_word {
    char* myword;
    struct arr_word* next;
} arr_word;

char* reverse(char* str);
void destroy_list(arr_word* list);
arr_word* new_NODE(char* str);
arr_word* create_NODE(char* str);
void push_p(arr_word** head, char* word);

void split_word(arr_word** head, char* sentence)
{
    char* low;
    low = sentence;

    if (*low == '\0') {
        return;
    }
    while (*low == ' ') {
        low++;
    }
    char* lastword = low;

    char result_word[32];
    char* p = result_word;
    while (*lastword != ' ' && *lastword != '\0') {
        *p = *lastword;
        p++;
        lastword++;
    }
    *p = '\0';
    push_p(head, strdup(result_word));
    split_word(head, lastword);
}

void push_p(arr_word** head, char* word)
{

    arr_word* new_NODE = create_NODE(word);
    if (*head == NULL) {
        *head = new_NODE;

        return;
    }
    new_NODE->myword = word;
    new_NODE->next = *head;
    *head = new_NODE;
}

arr_word* create_NODE(char* str)
{
    arr_word* NODE = malloc(sizeof(arr_word));
    if (NODE == NULL)
        return NULL;
    NODE->myword = str;
    NODE->next = NULL;
    return NODE;
}
void display_list(arr_word* list)
{
    if (list == NULL) {
        return;
    }
    if (list->next == NULL) {
        printf("%s -> NULL ", list->myword);
    } else {
        printf("%s -> ", list->myword);
    }
    display_list(list->next);
}

int main()
{
    char string[] = "     Hello        world mygodolax     ";
    int len = sizeof(string);
    arr_word* mylist = NULL;
    split_word(&mylist, string);
    char* myname = reverse("hellwlwwwwwaaaaaaaa");
    puts(myname);
    display_list(mylist);
    destroy_list(mylist);
    free(myname);
    return 0;
}

void destroy_list(arr_word* list)
{
    while (list != NULL) {
        arr_word* temp = list->next;
        free(list->myword);

        free(list);
        list = temp;
    }
}

char* reverse(char* restrict stx)
{
    char* str = strdup(stx);
    int len = strlen(stx);
    char *h, *t;
    h = str;
    t = str + len - 1;

    while (h != t) {
        char temp;
        temp = *h;
        *h = *t;
        *t = temp;
        h++;
        t--;
    }

    return str;
}

char* remove_white_space(char* str, int len)
{
    int new_len = len;
    char *low, *top;
    low = str;
    top = str + len - 2;
    while (*low == ' ') {
        low++;
        new_len--;
    }
    while (*top == ' ') {
        top--;
        new_len--;
    }
    char* new_str = malloc(new_len + 2);
    char* p = new_str;

    while (low != top) {
        *p = *low;
        low++;
        p++;
    }
    *p++ = *top;
    *p = '\0';
    return new_str;
}
