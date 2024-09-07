#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // . Given an array of integers nums and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    int target, len;
    printf("Enter the length of array ");
    scanf("%d", &len);
    int *array = (int *)malloc (len * sizeof(int));
    if(len == NULL){
        printf("Memory allocation is failed\n");
        return -1;
    }

    printf("Enter the element of array");
    for (int i = 0; i < len; i++){
        scanf("%d",&array[i]);
    }

// //for debug displaying the array
//     for (int i = 0; i < len; i++){
//         printf("%d\t",array[i]);
//     }

    printf("Enter the Target Element that you find\t");
    scanf("%d", &target);

    int index = -1;
    for (int i = 0; i < len; i++){
        if(array[i]==target){
            index = i;
        }
    }
    
    if(index != -1){
        printf("The index of target %d is %d", target, index);
    }else{
        printf("The target didn't exit in the array");
        return -1;
    }

    free(array);


    return 0;
}
