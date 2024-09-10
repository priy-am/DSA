#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int len;
    printf("Enter the length of array:- ");
    scanf("%d", &len);
    int *array = (int *)malloc(len * sizeof(int));
    if(len == NULL){
        printf("Memory allocation failed!!\n");
        return -1;
    }

    printf("Enter the element of the array:- ");
    for (int i = 0; i < len; i++){
        scanf("%d",&array[i]);
    }

    //find the kth largest element in the array
    int largestElement;
    largestElement = array[0];
    for (int i = 0; i < len; i++){
        if(largestElement < array[i]){
        largestElement = array[i];
        }
    }
    
    printf("The largest element in the array :- %d ", largestElement);

    return 0;
}
