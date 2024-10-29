// 4. Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// *A peak element is an element that is strictly greater than its neighbors.

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int len;
    int peak = -1;
    cout << "Enter the length of array: ";
    cin >> len;

    if (len <= 0) {
        cout << "Array length should be greater than 0." << endl;
        return -1;
    }

    int *array = new int[len];
    cout << "Enter the elements: ";
    for (int i = 0; i < len; i++) {
        cin >> array[i];
    }
    
    for(int i=0; i<len; i++ ){
        bool isLeftGreater = ( i== 0 || array[i]> array[i-1] );
        bool isRightGreater = ( i == len-1 || array[i]> array[i+1]);
        if( isLeftGreater && isRightGreater){
            peak = i;
            break;
        }
    }

    if(peak == -1){
        cout<<"Peak element not found\n";
    }else{
        cout<<"Peak element is "<<array[peak]<<" at index "<<peak<<endl;
    }

    delete[] array;

    return 0;
}
