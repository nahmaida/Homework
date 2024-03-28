#include <iostream>
using namespace std;

void checkPrime() {
    int num;
    cout << "Введите число:\n>> ";
    cin >> num;

    if (num < 2) {
        cout << "Меньше двух, не простое.";
        return;
    }

    int i = 2;
    while (i < num) {
        if ((num % i) == 0) {
            cout << "Составное.";
            return;
        }
        i++;
    }
    cout << "Простое.";
}

void printRange() {
    int start, end;
    cout << "Введите первое число:\n>> ";
    cin >> start;
    cout << "Введите последнее число:\n>> ";
    cin >> end;

    if (end < start) {
        int temp;
        temp = start;
        start = end;
        end = temp;
    }

    while (start <= end) {
        cout << start << endl;
        start++;
    }
}

void rockPaperScissors() {
    int choice;
    int moves = 0;
    int score = 0;
    int pcScore = 0;
    while (moves < 3) {
        cout << "\n1. Камень\n2. Ножницы\n3. Бумага\n>> ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "Неверный ввод\n";
            continue;
        }

        srand((unsigned)time(NULL));
        int pcChoice = 1 + (rand() % 3);

        if (choice == pcChoice) {
            cout << "Ничья\n";
        } else if ((choice == 1 && pcChoice == 3) ||
                   (choice == 2 && pcChoice == 1) ||
                   (choice == 3 && pcChoice == 2)) {
            cout << "Ты выиграл\n";
            score++;
        } else {
            cout << "Ты проиграл\n";
            pcScore++;
        }

        cout << "Твой счёт: " << score << "\nСчёт компьютера: " << pcScore
             << endl;
        moves++;
    }

    if (score > pcScore) {
        cout << "Победа!\n";
    } else if (score < pcScore) {
        cout << "Поражение!\n";
    } else {
        cout << "Ничья!\n";
    }
}

void numberGuesser() {
    int guess;
    int attempts = 1;
    bool guessed = false;

    srand((unsigned)time(NULL));
    int number = 1 + (rand() % 100);

    while (!guessed) {
        cout << "Попытка " << attempts << ".\nВведите число:\n>> ";
        cin >> guess;

        if (guess == number) {
            cout << "Вы угадали!\n";
            guessed = true;
        } else if (guess > number) {
            cout << "Загаданное число меньше\n";
            attempts++;
        } else if (guess < number) {
            cout << "Загаданное число больше\n";
            attempts++;
        }
    }
    cout << "Вы угадали число за " << attempts << " попыток!\n";
}

double approximateRoot(double number, int precision) {
    double guess = number;
    while (precision > 0) {
        guess = (guess + number / guess) / 2;
        precision--;
    }
    return guess;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Проверка на простое число\n"
            "2. Вывод последовательности\n"
            "3. Камень ножницы бумага\n"
            "4. Угадать число\n"
            "5. Примерный корень числа\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            checkPrime();
            break;
        case 2:
            printRange();
            break;
        case 3:
            rockPaperScissors();
            break;
        case 4:
            numberGuesser();
            break;
        case 5:
            double number, precision;
            cout << "Введите число:\n>> ";
            cin >> number;
            cout << "Введите точность (натуральное число):\n>> ";
            cin >> precision;
            cout << approximateRoot(number, precision);
            break;
        default:
            break;
    }
    return 0;
}
