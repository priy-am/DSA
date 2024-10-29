// 6. Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Write a function to return the kth positive integer that is missing from this array.
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;

    int *array = (int *)malloc(len * sizeof(int));
    if (array == NULL) {
        cout << "Memory allocation failed!" << endl;
        return -1;
    }

    cout << "Enter a strictly increasing positive integer array with possible missing elements: ";
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }

    int k;
    cout << "Enter the value of k to find the kth missing positive integer: ";
    cin >> k;

    int missingCount = 0;
    int currentNumber = 1;  // Tracks the expected positive integer
    int i = 0;  // Array index

    while (missingCount < k) {
        if (i < len && array[i] == currentNumber) {
            i++;
        } else {
            missingCount++;
            if (missingCount == k) {
                cout << "The " << k << "th missing positive integer is: " << currentNumber << endl;
                break;
            }
        }
        currentNumber++;
    }

    free(array);
    return 0;
}
