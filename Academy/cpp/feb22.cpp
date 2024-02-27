#include <iostream>
using namespace std;

void printRange() {
    int i = 0;
    int end;
    cout << "Введите последнее число:\n>> ";
    cin >> end;
    while (i <= end) {
        cout << i << endl;
        i++;
    }
}

int rangeSum(int start, int end) {
    int num = start;
    int sum = 0;
    while (num <= end) {
        sum += num;
        num++;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1/2\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            printRange();
            break;
        case 2:
            int start, end;
            cout << "\n(Сумма) Введите первое число:\n>> ";
            cin >> start;
            cout << "Введите последнее число:\n>> ";
            cin >> end;
            cout << rangeSum(start, end);
        default:
            break;
    }
    return 0;
}
