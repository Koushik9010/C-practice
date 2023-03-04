#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void delete();
void display();

int *a;
int rear  = -1;
int front = -1;
int MAX;

//Create Function
void create()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &MAX);

    a = malloc(MAX * sizeof(int));
    printf("\nQueue of %d is created", MAX);
}

//Insert function
void insert()
{
    int value;
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &value);

    if(rear == MAX - 1)
    {
        printf("\n\nQueue is overflowed....");
    }
    else if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = value;
        printf("\n%d is inserted..", value);
    }
    else
    {
        a[++rear] = value; 
        printf("\n%d is inserted..", value);
    }
}

//Delete function
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
        rear = -2;
    }
    else
    {
        printf("\n\n%d is deleted....", a[front]);
        front = ((front + 1)%MAX);
    }
}

//Display function
void display()
{
    int i;
    if(front == -1)
    {
        printf("\n\nQueue is empty....");
    }
    else
    {
        printf("\nQueue values are: ");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n\n");
}

//Main function
int main()
{
    int choice;
    do
    {
        printf("\n\t\t\t==========MENU==========");
        printf("\n 1. Create a queue.");
        printf("\n 2. Insert value in queue.");
        printf("\n 3. Delete value from queue.");
        printf("\n 4. Display the status of queue.");
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

            default: printf("\nInvalid choice...");
        }
    } while (choice != 5);
    
    return 0;
}
