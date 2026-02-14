#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Sucess_CALL (printf("LOG -> Sucess Called by ,%s \n", __FUNCTION__))
#define ERR_CALL (printf("LOG -> Errors Called by ,%s \n", __FUNCTION__))

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* new_node(int value);

void insert(Node** root, int value)
{
    Node* n_node = new_node(value);
    if (*root == NULL) {
        Sucess_CALL;
        *root = n_node;
    } else if (value >= (*root)->value) {
        insert(&(*root)->right, value);
        free(n_node);
        Sucess_CALL;
    } else if (value <= (*root)->value) {
        insert(&(*root)->left, value);
        free(n_node);
        Sucess_CALL;
    }
}

void display_tree(Node* tree)
{
    if (tree == NULL) {
        return;
    }
    printf("[%d] ->", tree->value);
    display_tree(tree->left);
    display_tree(tree->right);
}

void free_tree(Node* root)
{
    if (root == NULL) {
        return;
    }
    free_tree(root->right);
    free_tree(root->left);
    printf("LOG -> Clear memory at : %p ", root);
    free(root);
    Sucess_CALL;
}

int main(int argc, char* argv[])
{
    Node* root = NULL;

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 30);
    insert(&root, 50);
    display_tree(root);

    free_tree(root);
    return EXIT_SUCCESS;
}

Node* new_node(int value)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        ERR_CALL;
        return new_node(value);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    Sucess_CALL;
    return node;
}
