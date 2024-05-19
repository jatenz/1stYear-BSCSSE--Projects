#include <iostream>
using namespace std;

int sizeArr, sum;


int main(){
    cout << "\nEnter the size of the array: ";
    cin >> sizeArr;

    int arr1[sizeArr] = {};
    int arr2[sizeArr] = {};

    for (int i = 0; i < sizeArr; i++){
        cout << "Array Element " << i + 1 << ": ";
        cin >> arr1[i];
        sum+=arr1[i];
    }

    for (int i = 0; i < sizeArr; i++) {
        int minIndex = 0;
        for (int q = 0; q < sizeArr; q++) {
            if (arr1[q] < arr1[minIndex]) {
                minIndex = q;
            }
        }
        arr2[i] = arr1[minIndex];
        arr1[minIndex] = INT_FAST8_MAX;
    }

    cout << "The sorted array is: ";
    for (int i = 0; i < sizeArr; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}