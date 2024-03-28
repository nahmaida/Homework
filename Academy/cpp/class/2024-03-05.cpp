#include <iostream>
using namespace std;

int arraySum(int array[]) {
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum;
}

void findMinMax(int array[]) {
    int length = sizeof(array) / sizeof(array[0]);
    int min = array[0];
    int max = array[0];
    for (int i = 0; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
    cout << min << " " << max;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Сумма элементов массива\n2. Минимальное и максимальное значение\n>> ";
    int array[5] = {1, 2, 3, 4, 5};
    switch (mode) {
        case 1:
            cout << arraySum(array);
            break;
        case 2:
            findMinMax(array);
            break;
    }
    return 0;
}
