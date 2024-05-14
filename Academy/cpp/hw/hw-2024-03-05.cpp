#include <iostream>
using namespace std;

int secondGreatest() {
    int len;
    cout << "Введите размер массива:\n>> ";
    cin >> len;
    int arr[len], greatest = 0, lastGreatest;
    for (int i = 0; i < len; i++) {
        cout << "Введите значение:\n>> ";
        cin >> arr[i];
        if (arr[i] > greatest) {
            lastGreatest = greatest;
            greatest = arr[i];
        }
    }
    return lastGreatest;
}

double average(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum / len;
}

bool isMirror(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        if (arr[i] != arr[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Второе наибольшее\n2. Среднее арифметическое\n"
            "3. Проверка на зеркальность\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            cout << secondGreatest() << endl;
            break;
        case 2:
            int arr[5];
            cout << "Введите 5 чисел:\n";
            for (int i = 0; i < 5; i++) {
                cout << ">> ";
                cin >> arr[i];
            }
            cout << "Среднее арифметическое: " << average(arr, 5) << endl;
            break;
        case 3:
            int arr2[5];
            cout << "Введите 5 чисел:\n";
            for (int i = 0; i < 5; i++) {
                cout << ">> ";
                cin >> arr2[i];
            }
            cout << "Зеркальный: " << isMirror(arr2, 5) << endl;
            break;
    }
    return 0;
}
