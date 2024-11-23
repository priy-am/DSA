// 2. Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int target, len;
    cout << "Enter the length of array: ";
    cin >> len;
    
    int *array = (int *)malloc(len * sizeof(int));
    if (array == NULL) {
        cout << "Memory allocation failed" << endl;
        return -1;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }

    // Sorting in ascending order using bubble sort
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    // Displaying the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < len; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
    
    cout << "Enter the target element that you want to find: ";
    cin >> target;

    int index = -1;
    if (target > array[len / 2]) {
        for (int i = len / 2; i < len; i++) {
            if (target == array[i]) {
                index = i;
                break;
            }
        }
    } else {
        for (int i = len / 2; i >= 0; i--) {
            if (target == array[i]) {
                index = i;
                break;
            }
        }
    }

    if (index != -1) {
        cout << "The index of the target in the sorted array is: " << index << endl;
    } else {
        cout << "Element doesn't exist" << endl;
    }

    free(array);
    return 0;
}
