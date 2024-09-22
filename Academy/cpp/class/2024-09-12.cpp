#include <time.h>

#include <cstdlib>
#include <iostream>
using namespace std;

void fillArray(int *array, int size, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int sorted = true;
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                sorted = false;
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
        if (sorted) {
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int size = 10;
    int min = 1;
    int max = 100;
    int array[size];
    fillArray(array, size, min, max);
    bubbleSort(array, size);
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
