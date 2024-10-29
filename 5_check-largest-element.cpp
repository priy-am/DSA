// 5. Given an integer array ‘num’ and an integer k. Write a function to return kth largest element in the given array.

#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int len, k;
    cout << "Enter the length of the array: ";
    cin >> len;

    int *array = (int *)malloc(len * sizeof(int));
    if (array == NULL) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }

    // Sorting in descending order to find kth largest element
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    // Displaying sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < len; i++) {
        cout << array[i] << "\t";
    }
    cout << endl;

    do {
        cout << "Enter the kth position of the largest element in the array: ";
        cin >> k;
        if (k > len || k <= 0) {
            cout << "Please enter a valid position." << endl;
        }
    } while (k > len || k <= 0);

    cout << k << "th largest element in the given array is: " << array[k - 1] << endl;

    free(array);
    return 0;
}
