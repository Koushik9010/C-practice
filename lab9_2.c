//DFS
#include<stdio.h>
#include<stdlib.h>

int matrix[10][10];
int visited[10];
int n;

//create
void create()
{
    int i, j;
    printf("\nEnter the number of the cities: \n");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix: \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nValues entered.\n");
}

//DFS
void dfs(int start)
{
    visited[start] = 1;

    for(int i = 0; i < n; i++)
    {
        if(matrix[start][i] == 1 && visited[i] == 0)
        {
            printf("%d -> %d\n", start+1, i+1);
            dfs(i);
        }
    }
}

int main()
{
    int choice, i, start;
    
    do
    {
        printf("\t\t\t*************MENU***************");
        printf("\n1. Create graph.");
        printf("\n2. DFS Traversal.");
        printf("\n3. Exit.");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                create();
                    break;
            case 2: 
                for(i = 0; i < n; i++)
                {
                    visited[i] = 0;
                }
                printf("\nEnter the starting city: ");
                scanf("%d", &start);
                start = start -1;
                dfs(start);
                    break;
            case 3: 
                choice = 3;
                    break;
            default: 
                printf("\nInvalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}