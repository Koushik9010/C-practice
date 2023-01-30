#include <stdio.h>
#define max 4

int stack[max];
int top = -1;

void push(int x)
{
    if (top == max - 1)
    {
        printf("\nError: Stack overflow\n");
        return;
    }
    else
    {
       top++;
    stack[top] = x;
    }

}

void pop()
{
    if (top == -1)
    {
        printf("\nError: Stack underflow\n");
        return;
    }
    else
    {
        top--;
    }

}

void Palindrome()
{
    int i;
    int temp[max];
    int palindrome = 1;

    for (i = 0; i <= top; i++)
    {
        temp[i] = stack[i];
    }

    for (i = 0; i <= top; i++)
    {
        if (stack[i] != temp[top - i])
        {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
    {
        printf("The stack is a palindrome\n");
    }
    else
    {
        printf("The stack is not a palindrome\n");
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Error: Stack is empty\n");
        return;
    }
    printf("Stack: ");

    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
        {
        printf("\t\t\t\t\t===============Menu===============\n");
        printf("\t1. Push an element.\n");
        printf("\t2. Pop an element.\n");
        printf("\t3. Check if stack is palindrome\n");
        printf("\t4. Display stack\n");
        printf("\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)

        {
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                Palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}
