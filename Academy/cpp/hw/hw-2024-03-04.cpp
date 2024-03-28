#include <iostream>
using namespace std;

void printTenEvens() {
    // ??? а зачем тут break
    for (int i = 1; i < 11; i++) {
        cout << i * 2 << " ";
    }
}

void skipThreeFiveMultiples(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        cout << i << endl;
    }
}

void countPositives() {
    int numOfPositives = 0;
    for (int n = 1; n != 0;) {
        cout << "Введите число (0 - выход)\n>> ";
        cin >> n;
        if (n == 0) {
            break;
        }
        if (n > 0) {
            numOfPositives++;
        }
    }
    cout << numOfPositives;
}

void threeNegatives() {
    int numOfNegatives = 0;
    for (int n = 1;;) {
        cout << "Введите число (0 - выход)\n>> ";
        cin >> n;
        if (n < 0) {
            numOfNegatives++;
        }
        if (numOfNegatives > 2) {
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. 10 чётных чисел\n2. Пропустить числа, кратные 3 или 5\n3. "
            "Подсчет положительных чисел\n4. Остановить ввод после трёх "
            "отрицательных чисел\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            printTenEvens();
            break;
        case 2:
            int n;
            cout << "Введите число\n>> ";
            cin >> n;
            skipThreeFiveMultiples(n);
            break;
        case 3:
            countPositives();
            break;
        case 4:
            threeNegatives();
            break;
    }
    return 0;
}
