#include <iostream>
using namespace std;

void bubbleSort(int arr[]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[]) {
    int length = sizeof(arr) / sizeof(arr[0]);
    int sorted[length];
    int index;
    for (int j = 0; j < length; j++) {

    }
}

void matrixBreaker(int arr1[], int arr2[]) {
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int totalSize = size1 + size2;
    int arr3[totalSize];

    for (int i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr3[i + size1] = arr2[i];
    }

    bubbleSort(arr3);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[]) {
    int arr1[8] = {-2, 0, 0, 1, 2, 3, 4, 5};
    int arr2[6] = {6, 7, 8, 9, 0, 10};
    matrixBreaker(arr1, arr2);
    printArray(arr1, 5);
    printArray(arr2, 5);
    return 0;
}