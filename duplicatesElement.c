#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

int main(int argc, char const *argv[])
{
    int len, target;
    printf("Enter the Length of array :- ");
    scanf("%d",&len);
    int *array = malloc(len * sizeof(len));
    if(len == NULL){
        printf("Memory allocation is failed :(\n");
        return -1;
    }

    printf("Enter the element of the array:- ");
    for(int i=0; i<len;i++){
        scanf("%d",&array[i]);
    }

    for(int i = 0; i < len; i++){
        for(int j=0; j<len-i; j++){
            if(array[j]>array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }

    printf("Displaying the sorted array\n");
    for(int i =0; i<len;i++){
        printf("%d\t",array[i]);
    }

    printf("\nEnter the target element:- ");
    scanf("%d",&target);

    int occurrence = 0;

    for(int i = 0; i<len;i++){
        if(array[i]==target){
            occurrence += 1;
        }
    }

    if(occurrence == 0){
        printf("Target element does not exit in this array \n");
    }else{
        printf("The number of occurrences of the target %d element is %d ",target, occurrence);
    }

    free(array);
    return 0;
}
