#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void delete();
void display();

int *a;
int rear  = -1;
int front = -1;
int max;

//Create Function
void create()
{
    printf("\nEnter the size of queue: ");
    scanf("%d", &max);

    a = malloc(max * sizeof(int));
    printf("\nQueue of %d is created", max);
}

//Insert function
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
        rear = -1;
    }
    else
    {
        printf("\n\n%d is deleted....", a[front]);
        front = ((front + 1)%max);
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

/**
 create().

1. The function begins by prompting the user to enter the size of the 
    queue by printing the message "Enter the value of queue: ".
2. The user's input is then read in through the standard input 
    function scanf() and stored in the variable max.
3. The code dynamically allocates an array of max integers using the malloc() function. 
    The size of the array is calculated as max * sizeof(int), 
    where sizeof(int) returns the number of bytes required to store an integer on the user's system.
4. Finally, the function prints a message indicating that a queue of size max has been created, using the printf() function.

insert(). 

1. The function begins by declaring a local integer variable value.
2. The function prompts the user to enter the value to be inserted into 
    the queue by printing the message "Enter the value to be inserted: ".
3. The user's input is then read in through the standard input function 
    scanf() and stored in the variable value.
4. The code checks if the queue is already full (i.e., if the rear variable is equal to max - 1).
    If the queue is full, the function prints a message indicating that the queue 
    is overflowed and does not insert the value into the queue.
5. If the queue is not full, the code checks if the queue is empty 
    (i.e., if both the front and rear variables are equal to -1). 
    If the queue is empty, the front and rear variables are set to 0, 
    and the value is inserted into the first (and only) position in the queue.
6. If the queue is neither full nor empty, the rear variable is incremented 
    by 1, and the value is inserted into the next available position in the queue.

delete().

1. The function checks if the queue is empty (i.e., if front is equal to -1). 
    If the queue is empty, the function prints a message indicating that the queue 
    is underflowed and does not attempt to delete any element.
2. If the queue is not empty, the code checks if there is only one 
    element in the queue (i.e., if front is equal to rear). 
    If there is only one element, the element is printed, the front and rear 
    variables are set to -1 to indicate that the queue is empty, and the element is deleted from the queue.
3. If there is more than one element in the queue, the element at the front of the queue is printed, 
    and the front variable is incremented by 1 using the modulo operator (%). 
    This causes front to wrap around to 0 if it reaches the end of the queue. The element is then deleted from the queue.
**/
