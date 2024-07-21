#include <stdio.h>
#include <stdlib.h>

void create();
void insert_atfirst();
void insert_atlast();
void insert();
void delete_bypos();
void delete_byval();
void display();
int menu();
void processChoice(int choice);

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL, *temp = NULL;

int main()
{
    // Display the menu choices once
    menu();

    // Process user input
    int choice;
    do
    {
        printf("\nEnter Your Choice:");
        scanf("%d", &choice);
        processChoice(choice);
    } while (choice != 8);

    return 0;
}

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the Data in the Node:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}

void insert_atfirst()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter Element:");
    scanf("%d", &temp->data);
    temp->next = first;
    first = temp;
}

void insert()
{
    struct node *t, *t1;
    int pos, count = 1, AB;
    printf("Enter Position to be inserted:");
    scanf("%d", &pos);
    printf("After[1] or Before[2]:");
    scanf("%d", &AB);
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    t = t1 = first;
    while (t != NULL)
    {
        if (pos == count)
            break;
        else
        {
            t = t1;
            t = t->next;
            count++;
        }
    }
    if (AB == 1)
    {
        temp->next = t->next;
        t->next = temp;
    }
    else if (AB == 2)
    {
        temp->next = t;
        t1->next = temp;
    }
    else
        printf("Invalid Input");
}

void insert_atlast()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter value to be inserted at last:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (last != NULL)
    {
        last->next = temp;
        last = temp;
    }
    else
    {
        first = temp;
        last = temp;
    }
}

void delete_bypos()
{
    struct node *t, *t1;
    int pos, count = 1;
    printf("Enter the Position of the element to delete:");
    scanf("%d", &pos);
    t = t1 = first;
    while (t != NULL)
    {
        if (pos == count)
            break;
        else
        {
            t1 = t;
            t = t->next;
            count++;
        }
    }
    if (t == NULL)
    {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1)
    {
        first = t->next;
        if (first == NULL)
            last = NULL;
        free(t);
        printf("Executed-->First Node is deleted!!");
    }
    else if (t == last)
    {
        t1->next = NULL;
        last = t1;
        free(t);
        printf("Executed-->Last Node is deleted!!");
    }
    else
    {
        t1->next = t->next;
        free(t);
        printf("Executed-->Node has been deleted!!");
    }
}

void delete_byval()
{
    int val;
    struct node *t, *t1;
    printf("Enter value:");
    scanf("%d", &val);
    t = t1 = first;
    while (t != NULL)
    {
        if (val == t->data)
            break;
        else
        {
            t1 = t;
            t = t->next;
        }
    }
    if (t == NULL)
    {
        printf("Value not found!\n");
        return;
    }
    if (t == first)
    {
        first = t->next;
        if (first == NULL)
            last = NULL;
        free(t);
    }
    else if (t == last)
    {
        t1->next = NULL;
        last = t1;
        free(t);
    }
    else
    {
        t1->next = t->next;
        free(t);
    }
}

void display()
{
    temp = first;
    while (temp != NULL)
    {
        printf("|%d|%p| --> ", temp->data, (void *)temp->next);
        temp = temp->next;
    }
}

void processChoice(int choice)
{
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        insert_atfirst();
        break;
    case 3:
        insert_atlast();
        break;
    case 4:
        insert();
        break;
    case 5:
        delete_bypos();
        break;
    case 6:
        delete_byval();
        break;
    case 7:
        display();
        break;
    case 8:
        exit(0);
    default:
        printf("Error-->Enter a valid choice!!");
        break;
    }
}

int menu()
{
   // printf("Single Linked List\n");
    printf("1.Create\n2.Insert at first\n3.Insert at last\n4.Insert at Middle\n5.Delete by Position\n6.Delete by Value\n7.Display\n8.Exit\n");
    return 0;
}
