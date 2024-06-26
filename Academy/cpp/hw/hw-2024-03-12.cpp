#include <iostream>
#include "time.h"
using namespace std;

void split() {
    int a = 10, b = 5, c = 10, d = 20;
    int arr[a], arr1[b], arr2[b];
    srand(time(NULL));
    for (int i = 0; i < a; i++) {
        arr[i] = c + rand() % (d - c);
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "1 2" << endl;
    for (int i = 0; i < b; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i+5];
    }
    for (int i = 0; i < b; i++) {
        cout << arr1[i] << " "<< arr2[i]<< endl;
    }
}

int* sum(int* arr1, int* arr2, int size) {
    int result[size];
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] + arr2[i];
    }
    return result;
}

int main(int argc, char const *argv[]) {
    split();
    cout << "аа";
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int* result = sum(arr1, arr2, 5);
    for (int i = 0; i < 5; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
