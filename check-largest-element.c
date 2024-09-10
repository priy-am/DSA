#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

int main(int argc, char const *argv[])
{
    int len, k;
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

    for (int i = 0; i < len; i++){
        for(int j= 0; j <len-i-1; j++){
            if(array[j]<array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }

    //displaying
    for (int i = 0; i < len; i++){
        printf("%d\t", array[i]);
    }
    
    do{
        printf("\nEnter the kth potion of the array that you want to know to;- ");
        scanf("%d",&k);
        if(k>5 || k<0){
        printf("please enter the valid potion ");
        }
    } while (k>5 || k<0 || k == NULL);

    printf("%dth largest element in the given array is :- %d", k, array[k]);
    return 0;
}
