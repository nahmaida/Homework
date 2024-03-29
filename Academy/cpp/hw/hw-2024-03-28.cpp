#include <iostream>
using namespace std;

int raiseTo(int number, int power) {
    int product = number;
    for (int i = 1; i < power; i++) {
        product *= number;
    }
    return product;
}

int rangeSum(int start, int end) {
    int sum = 0;
    for (int num = start; num <= end; num++) {
        sum += num;
    }
    return sum;
}

bool isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if ((num % i) == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

void printCard() {
    char *rank, *suit;
    int pickSuit;
    cout << "Введите достоинство (2-10, J, Q, K, A и т.д.):\n>> ";
    cin >> rank;
    cout << "Введите масть (1. Пики, 2. Трефы, 3. Черви, 4. Бубны):\n>> ";
    cin >> pickSuit;
    switch (pickSuit) {
        case 1:
            suit = "♠";
            break;
        case 2:
            suit = "♣";
            break;
        case 3:
            suit = "♥";
            break;
        case 4:
            suit = "♦";
            break;
        default:
            suit = " ";
            break;
    }
    cout << "┌─────────┐\n│";
    cout.width(2);
    cout << rank;
    cout << ". . . .│\n"
         << "│. . . . .│\n"
         << "│. . . . .│\n"
         << "│. . " << suit << " . .│\n"
         << "│. . . . .│\n"
         << "│. . . . .│\n"
         << "│. . . ";
    cout.width(2);
    cout << rank;
    cout << ".│\n└─────────┘";
}

bool isLucky(int num) {
    // есть штук 200 определений счастливых чисел
    // как я понял тут имелись в виду счастливые билетики
    int firstThree = 0;
    int lastThree = 0;
    for (int pos = 6; pos > 0; pos--) {
        int digit = num % 10;
        num /= 10;
        if (pos >= 4) {
            lastThree += digit;
        } else {
            firstThree += digit;
        }
    }
    return (firstThree == lastThree);
}

int main(int argc, char const* argv[]) {
    int mode;
    cout << "1. Степень\n2. Сумма диапазона\n3. Совершенное число\n"
         << "4. Вывести карту\n5. Счастливое число\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            int number;
            int power;
            cout << "Введите число: \n>> ";
            cin >> number;
            cout << "Введите степень: \n>> ";
            cin >> power;
            cout << raiseTo(number, power);
            break;
        case 2:
            int start;
            int end;
            cout << "Введите начало диапазона: \n>> ";
            cin >> start;
            cout << "Введите конец диапазона: \n>> ";
            cin >> end;
            cout << rangeSum(start, end);
            break;
        case 3:
            int num;
            cout << "Введите число: \n>> ";
            cin >> num;
            cout << isPerfect(num);
            break;
        case 4:
            printCard();
            break;
        case 5:
            int ticket;
            cout << "Введите число: \n>> ";
            cin >> ticket;
            cout << isLucky(ticket);
            break;
        default:
            break;
    }
    return 0;
}
