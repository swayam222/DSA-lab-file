#include <stdio.h>
// #include<conio.h>

int stack[100], i, k, choice = 0, n, top = -1;

void push();
void pop();
void peek();
void display();

void main()
{
    printf("Enter the number of elements in the stack:");
    scanf("%d", &n);
    printf("Stack Operations using array\n");
    printf("\n");
    while (choice != 5)
    {
        printf("\nChoose one from the below points");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("Please enter valid choice");
        }
    };
}

void push()
{
    int val;
    if (top == n - 1) // Check if top has reached the maximum index
        printf("Overflow\n");
    else
    {
        printf("Enter the value:");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Underflow\n");
    else
        top = top - 1;
}

void peek()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is %d\n", stack[top]);
}

void display()
{
    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
    if (top == -1)
        printf("Stack is empty\n");
}
