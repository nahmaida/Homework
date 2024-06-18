#include <iostream>
using namespace std;

template <typename T>
T* addArrays(T* arr1, T* arr2, int size) {
    T* arr = new T[size * 2];
    for (int i = 0; i < size; i++) {
        arr[i] = arr1[i];
        arr[i + size] = arr2[i];
    }
    return arr;
}

template <typename T>
void search(T threeDimArray[][3][3], int toSearch) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (threeDimArray[i][j][k] == toSearch) {
                    cout << "Найдено: " << toSearch << " по координатам " << i << ", " << j << ", " << k << endl;
                    return;
                }
            }
        }
    }
    cout << "Не найдено" << endl;
}

int main(int argc, char const *argv[]) {
    int threeDimArray[3][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
    };
    int toSearch = 15;
    search(threeDimArray, toSearch);

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int* arr = addArrays(arr1, arr2, 3);
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
