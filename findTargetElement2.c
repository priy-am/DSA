#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a = *b;
    *b = temp;
};

int main(int argc, char const *argv[])
{
    int target, len;
    printf("Enter the length of array:-  ");
    scanf("%d",&len);
    int *array = (int *)malloc(len* sizeof(int));
    if (array == NULL){
        printf("Memory allocation is failed \n");
        return -1;
    }

    printf("Enter the element of array:- ");
    for(int i = 0; i<len; i++){
        scanf("%d",&array[i]);
    }
    //shorting in ascending order using bubble shorting
    for(int i = 0; i < len; i++){
        for(int j=0; j<len-i; j++){
            if(array[j]>array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }

//for displaying 
    printf("Display the shorted array \n");
    for (int i = 0; i < len; i++) {
        printf("%d \t", array[i]);
    }
    
    printf("\nEnter the Target element that you want to find:- ");
    scanf("%d", &target);

    int index = -1;
    if(target> array[len/2]){
        for(int i = len/2; i<len; i++){
            if(target == array[i]){
            index = i;
            }
        }
    }else{
        for(int i = len/2; i>0; i--){
            if(target == array[i]){
                index = i;
            }
        }
    }

    if(index != -1){
        printf("The index of the target in the array according to the shorted array %d", index);
    }else{
        printf("Element doesn't exit\n");
    }

    free(array);

    return 0;
}
