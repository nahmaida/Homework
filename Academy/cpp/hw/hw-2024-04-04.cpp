#include <iostream>
using namespace std;

template <typename T>
void fun(T var) {
    // typeid(_).name() на разных компиляторах выдает по своему
    if (typeid(var) == typeid(int)) {
        cout << "Integer" << endl;
    } else if (typeid(var) == typeid(double)) {
        cout << "Double" << endl;
    } else if (typeid(var) == typeid(float)) {
        cout << "Float" << endl;
    } else if (typeid(var) == typeid(char)) {
        cout << "Character" << endl;
    } else if (typeid(var) == typeid(bool)) {
        cout << "Boolean" << endl;
    } else if (typeid(var) == typeid(char *) or
               typeid(var) == typeid(const char *)) {
        cout << "String" << endl;
    } else {
        cout << "Unknown" << endl;
    }
}

template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    fun(10);       // Integer
    fun(3.14);     // Double
    fun(2.718f);   // Float
    fun('A');      // Character
    fun(true);     // Boolean
    fun("Hello");  // String

    int intArr[] = {5, 2, 8, 1, 9, 3};
    double doubleArr[] = {3.14, 2.718, 1.618, 1.414};
    char charArr[] = {'A', 'B', 'C', 'D'};

    cout << findMax(intArr, 6) << endl;
    cout << findMax(doubleArr, 4) << endl;
    cout << findMax(charArr, 4) << endl;

    int intArr2[] = {5, 2, 8, 1, 9, 3};
    double doubleArr2[] = {3.14, 2.718, 1.618, 1.414};
    char charArr2[] = {'A', 'B', 'C', 'D'};
    bubbleSort(intArr2, 6);
    bubbleSort(doubleArr2, 4);
    bubbleSort(charArr2, 4);
    return 0;
}
