 // . Given an array of integers nums and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int target, len;
    cout<<"Enter the length of array ";
    cin>>len;
    int *array = (int *)malloc (len * sizeof(int));
    if(array == NULL){
        cout<<"Memory allocation is failed\n";
        return -1;
    }

    cout<<"Enter the element of array: ";
    for (int i = 0; i < len; i++){
        cin>>array[i];
    }

    cout<<"Enter the Target Element that you find\t";
    cin>>target;

    int index = -1;
    for (int i = 0; i < len; i++){
        if(array[i]==target){
            index = i;
        }
    }
    
    if(index != -1){
        cout<<"The index of target "<< target<<" is "<< index;
    }else{
        cout<<("The target didn't exit in the array");
        return -1;
    }

    free(array);


    return 0;
}
