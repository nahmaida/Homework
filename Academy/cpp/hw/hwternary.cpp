#include <iostream>
using namespace std;

void studentGrade(int grade) {
    if (grade >= 60) {
        cout << "Прошел";
    } else {
        cout << "Не прошел";
    }
}

void studentGroup(int age) {
    // зачем тут switch case
    switch (age > 14) {
        case true:
            switch (age > 18) {
                case true:
                    cout << "Старшая";
                    break;
                case false:
                    cout << "Средняя";
                    break;
            }
            break;
        case false:
            cout << "Младшая";
            break;
    }
}

void season(int month) {
    // больно, почему не if ):
    switch (month) {
        case 12:
        case 1:
        case 2:
            cout << "Зима";
            break;
        case 3:
        case 4:
        case 5:
            cout << "Весна";
            break;
        case 6:
        case 7:
        case 8:
            cout << "Лето";
            break;
        case 9:
        case 10:
        case 11:
            cout << "Осень";
            break;
    }
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Оценка студента\n2. Группа студента\n3. Время года\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            int grade;
            cout << "Оценка: ";
            cin >> grade;
            studentGrade(grade);
            break;
        case 2:
            int age;
            cout << "Возраст: ";
            cin >> age;
            studentGroup(age);
            break;
        case 3:
            int month;
            cout << "Месяц: ";
            cin >> month;
            season(month);
            break;
    }
    return 0;
}
