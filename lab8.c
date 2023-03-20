#include<stdio.h>
#include<stdlib.h>

//structure of binary tree
typedef struct tree{
    int data;
    struct tree *left, *right;
}tree;

int n;
tree *root = NULL;

//MENU
int menu()
{
    int choice;
    printf("\n\t\t\t==========Binary Search Tree==========");
    printf("\n1. Create tree");
    printf("\n2. Search data in tree");
    printf("\n3. Delete data from tree");
    printf("\n4. In Order");
    printf("\n5. Post Order");
    printf("\n6. Pre order");
    printf("\n7. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
    printf("\n");
}

//Insert data
tree* insert(tree *address, int data){
    if(address == NULL)
    {
        tree *temp;
        temp = (tree *)malloc(sizeof(tree));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(data < address->data)
    {
        address->left = insert(address->left, data);
    }
    else if(data > address->data)
    {
        address->right = insert(address->right, data);
    }
    return address;
}

//Tree creating
tree* create()
{
    int data;
    printf("Enter the size of the tree: \n");
    scanf("%d", &n);
    printf("Tree of %d is created.\n", n);

    printf("Enter the data into tree: \n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
}

//Get smaller data
tree* smaller(tree *address)
{
    if(address == NULL)
    {
        return NULL;
    }
    else if(address->left)
    {
        return smaller(address->left);
    }
    else
    {
        return address;
    }
}

//Search
tree* search(tree *address, int data)
{
    if(address == NULL)
    {
        printf("%d is not in tree\n", data);
    }
    else if(data < address->data)
    {
        address->left = search(address->left, data);
    }
    else if(data > address->data)
    {
        address->right = search(address->right, data);
    }
    else
    {
        printf("%d is in tree\n", address->data);
    }
    return address;
}

//delete
tree* delete(tree* address, int data)
{
    tree *temp;

    if(address == NULL)
    {
        printf("\nData not found");
    }
    else if(data < address->data)
    {
        address->left = delete(address->left, data);
    }
    else if(data > address->data)
    {
        address->right = delete(address->right, data);
    }
    else
    {
        if(address->left && address->right)
        {
            temp = smaller(address->right);
            address->data = temp->data;
            address->right = delete(address->right, temp->data);
        }
        else
        {
            temp = address;
            if(address->left == NULL)
            {
                address = address->right;
            }
            else if(address->right == NULL)
            {
                address = address->left;
            }
            free(temp);
        }
    }
    return address;
}

//in
void in_order(tree *address)
{
    if(address != NULL)
    {
        in_order(address->left);
        printf("%d   ", address->data);
        in_order(address->right);
    }
}

//pre
void pre_order(tree *address)
{
    if(address != NULL)
    {
        printf("%d   ", address->data);
        pre_order(address->left);
        pre_order(address->right);
    }
}

//post
void post_order(tree *address)
{
    if(address != NULL)
    {
        post_order(address->left);
        post_order(address->right);
        printf("%d   ", address->data);
    }
}

int exit_program()
{
    printf("\nProgramm Ended");
    return 0;
}

int main()
{
    int choice, data;
    do
    {
        choice = menu();

        switch(choice)
        {
            case 1:
                    create();
                    break;
            case 2:
                    printf("Enter element to search: \n");
                    scanf("%d", &data);
                    search(root, data);
                    break;
            case 3:
                    printf("Enter element to delete: ");
                    scanf("%d", &data);
                    delete(root, data);
                    break;
            case 4:
                    printf("Display the elements is IN ORDER: \n");
                    in_order(root);
                     break;
            case 5:
                    printf("Display the elements in POST ORDER: \n");
                    post_order(root);
                    break;
            case 6:
                    printf("DIsplay the elements in PRE ORDER: \n");
                    pre_order(root);
                    break;
            case 7:
                    choice = 7;
                    break;
            default:
                    printf("Invalid option: \n");
                    break;
        }
    }while(choice != 7);

    return 0;

}
