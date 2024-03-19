#include <iostream>
using namespace std;

void symbolLine() {
    char symbol;
    int length;
    int numOfSymbols;
    int mode;

    cout << "Введите один символ: \n>> ";
    cin >> symbol;
    cout << "Введите длину: \n>> ";
    cin >> length;
    cout << "Введите количество символов: \n>> ";
    cin >> numOfSymbols;
    cout << "1. Вертикальная\n2. Горизонтальная\n>> ";
    cin >> mode;

    char* lineBreak = " ";
    if (mode == 1) {
        lineBreak = "\n";
    }

    while (length > 0) {
        for (int j = 0; j < numOfSymbols; j++) {
            cout << symbol;
        }
        cout << lineBreak;
        length--;
    }

    // do {
    //     for (int j = 0; j < numOfSymbols; j++) {
    //         cout << symbol;
    //     }
    //     cout << lineBreak;
    //     length--;
    // } while (length > 0);
}

void printTable(int length, int width) {
    int num = 1;
    for (length; length > 0; length--) {
        for (int i = 0; i < width; i++) {
            cout << num;
            if (num < 10) {
                cout << "  ";
            } else {
                cout << " ";
            } //чисто для красоты
            num++;
        }
        cout << endl;
    }
}

int main(int argc, char const* argv[]) {
    int mode;
    cout << "1. Вывод линии\n2. Вывод таблицы\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            symbolLine();
            break;
        case 2:
            int length;
            int width;
            cout << "Введите высоту: \n>> ";
            cin >> length;
            cout << "Введите ширину: \n>> ";
            cin >> width;
            printTable(length, width);
            break;
        default:
            break;
    }
    return 0;
}
