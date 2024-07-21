#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct cqueue
{
    int item[SIZE];
    int rear;
    int front;
};

typedef struct cqueue qu;

void insert(qu *);
void delete(qu *);
void display(qu *);

int main()
{
    int ch;
    qu *q = (qu *)malloc(sizeof(qu)); // Allocate memory for the queue
    if (q == NULL)
    {
        printf("Memory allocation failed.\n");
        return -1;
    }
    q->rear = -1;
    q->front = -1;
    printf("Menu for program:\n");
    printf("1: insert\n2: delete\n3: display\n4: exit\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(q);
            break;
        case 2:
            delete (q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            free(q); // Free allocated memory before exit
            exit(0);
            break;
        default:
            printf("Your choice is wrong\n");
        }
    } while (ch != 4);

    return 0;
}

void insert(qu *q)
{
    int d;
    if ((q->rear + 1) % SIZE == q->front)
        printf("Queue is full\n");
    else
    {
        printf("Enter data to be inserted:");
        scanf("%d", &d);
        if (q->front == -1) // If queue is empty
            q->front = 0;
        q->rear = (q->rear + 1) % SIZE;
        q->item[q->rear] = d;
    }
}

void delete(qu *q)
{
    if (q->front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted item is: %d\n", q->item[q->front]);
        if (q->front == q->rear) // If only one element in the queue
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = (q->front + 1) % SIZE;
    }
}

void display(qu *q)
{
    int i;
    if (q->front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Items of queue are:\n");
        for (i = q->front; i != q->rear; i = (i + 1) % SIZE)
        {
            printf("%d\t", q->item[i]);
        }
        
        printf("%d\t", q->item[q->rear]);
    }
    printf("\n");
}
