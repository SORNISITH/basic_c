#include <stdio.h>
#include <stdlib.h>

#define SIZE 101
int arr[SIZE] = { 0 };

void deque(int** front, int** rear);
void enque(int** front, int** rear, int valueue);

int main(int argc, char* argv[])
{
    int *front, *rear;
    front = arr;
    rear = arr;

    enque(&front, &rear, 5);
    enque(&front, &rear, 10);
    enque(&front, &rear, 20);
    enque(&front, &rear, 20);
    enque(&front, &rear, 30);
    deque(&front, &rear);
    deque(&front, &rear);

    int* ptr = front;
    while (ptr != rear) {
        printf("%d-", *ptr);
        ptr++;
    }

    return EXIT_SUCCESS;
}

void enque(int** front, int** rear, int valueue)
{
    **rear = valueue;
    (*rear)++;
}

void deque(int** front, int** rear)
{
    if (*front == NULL) {
        *front = *rear;
        return;
    }
    **front = 0;
    (*front)++;
}
