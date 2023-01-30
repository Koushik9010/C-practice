#include<stdio.h>

int array[100];
int n;

//Create
void create()
{
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\n\n");
}

//Display
void display()
{
    printf("Array elements are: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n\n");
}

//Insert
void insert()
{
    int elem, pos;
    printf("Enter the element want to insert: ");
    scanf("%d", &elem);
    printf("Enter the position want to insert: ");
    scanf("%d", &pos);
    if(pos < 0 || pos > n)
    {
        printf("Invalid position. Please choose a valid position");
    }
    else
    {
        for(int i=(n-1); i>=pos; i--)
      {
        array[i] = array[i-1];
      }
        array[pos-1] = elem;
    }
    printf("\nArray elements are: ");
    for(int i=0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//Delete
void delete()
{
    int pos;
    printf("Enter the position you want to be deleted: ");
    scanf("%d", &pos);
    if(pos < 0 || pos> n)
    {
        printf("Invalid position. Please choose a valid position");
    }
    else
    {
       for(int i = (pos-1); i< (n-1); i++)
      {
        array[i] = array[i + 1];
      }
      n--;
    }
    printf("\nElements of the array are: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//Main
int main() {
    int choice;
    do {
        printf("\n\t\t\t\t\t===============Menu===============\n");
        printf("\n\t1. Create an array.");
        printf("\n\t2. Display of array elements.");
        printf("\n\t3. Inserting an elem at a given pos.");
        printf("\n\t4. Deleting an elem at a given pos.");
        printf("\n\t5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
            case 4: delete();
            break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}

