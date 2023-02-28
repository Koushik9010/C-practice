// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n, i;
    // Write C code here
    printf("Enter array size : ");
    scanf("%d",&n);
    
    int array[n];
    
    printf("\nEnter array values : \n");
    
    for(i=0; i < n; i++){
        scanf("%d",&array[i]);
    }
    
    printf("\nOutput : \n");
    for(i=0; i < n; i++){
        if(i == 0){
            if(array[i] > array[i+1]){
                printf("%d\t", array[i]);
            }
        }
        if(i != 0 && i != n-1){
           if(array[i] > array[i+1] && array[i] > array[i-1]){
               printf("%d\t", array[i]);
           }
        }
        if(i == n-1){
          if(array[i] > array[i-1]){
                printf("%d\t", array[i]);
          }
        }
    }

    return 0;
}
