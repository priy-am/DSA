// Given a sorted array of n elements, possibly with duplicates, find the number of occurrences of the target element
#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int len, target;
    cout << "Enter the length of the array: ";
    cin >> len;
    int *array = (int *)malloc(len * sizeof(int));
    if (array == NULL) {
        cout << "Memory allocation failed :(" << endl;
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
    cout << "Enter the target element: ";
    cin >> target;
    int occurrence = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] == target) {
            occurrence += 1;
        }
    }

    if (occurrence == 0) {
        cout << "Target element does not exist in this array" << endl;
    } else {
        cout << "The number of occurrences of the target element " << target << " is " << occurrence << endl;
    }

    free(array);
    return 0;
}
