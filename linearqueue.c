#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

struct queue
{
    int item[SIZE];
    int rear;
    int front;
};

typedef struct queue qu;

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
    q->front = 0;
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
    printf("Enter data to be inserted:");
    scanf("%d", &d);
    if (q->rear == SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->item[q->rear] = d;
    }
}

void delete(qu *q)
{
    int d;
    if (q->rear < q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        d = q->item[q->front];
        q->front++;
        printf("Deleted item is: %d\n", d);
        if (q->front > q->rear)
        { // Reset front and rear when queue becomes empty
            q->front = 0;
            q->rear = -1; 
        }
    }
}
   void display(qu *q)
{
    int i;
    if (q->rear < q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("%d\t", q->item[i]);
        }
        printf("\n");
    }
}
