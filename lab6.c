#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void delete();
void display();

int *a;
int rear = -1;
int front = -1;
int max;

void create()
{
    printf("Enter the value of queue: ");
    scanf("%d", &max);

    a = malloc(max * sizeof(int));
    printf("\nQueue of %d is created", max);
}

void insert()
{
    int value;
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &value);

    if(rear == max - 1)
    {
        printf("\n\nQueue is overflowed....");
    }

    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = value;
    }
    else
    {
        a[++rear] = value;
    }
}

void delete()
{
    if(front == -1)
    {
        printf("\n\nQueue is underflowed....");
    }
    else if(front == rear)
    {
        printf("\n\n%d is deleted...", a[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n\n%d is deleted...", a[front]);
        front = ((front + 1)%max);
    }
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("\n\nError: Queue is empty...");
    }

    else
    {
        printf("\n\nQueue values are: ");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n\t\t\t==========MENU==========");
        printf("\n 1. Create a Queue.");
        printf("\n 2. Insert into Queue.");
        printf("\n 3. Delete from Queue.");
        printf("\n 4. Display the Queue status.");
        printf("\n 5. Exit.");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create();
            break;

            case 2: insert();
            break;

            case 3: delete();
            break;

            case 4: display();
            break;

            case 5: choice = 5;
            break;

            default: printf("\nInvalid choice.");
        }
    }while(choice != 5);

    return 0;
}
