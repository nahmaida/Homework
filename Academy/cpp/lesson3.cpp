#include <iostream>
#include <random>
using namespace std;

float area() {
    float length;
    float width;
    float area;

    cout << "Введите длину: ";
    cin >> length;

    cout << "Введите ширину: ";
    cin >> width;

    area = length * width;
    return area;
};

float volume() {
    float length;
    float width;
    float depth;
    float volume;

    cout << "Введите длину: ";
    cin >> length;

    cout << "Введите ширину: ";
    cin >> width;

    cout << "Введите глубину: ";
    cin >> depth;

    volume = length * width * depth;
    return volume;
};

void ship() {
    int passangers;
    int pirates;

    cout << "Сколько пассажиров?: ";
    cin >> passangers;

    pirates = (rand() % passangers) + 1;
    cout << "На вас напали " << pirates << " пиратов!\n";

    for (pirates; pirates > 0; pirates--) {
        passangers--;
        cout << "Кого то убили! Осталось " << passangers << " пассажиров.\n";
    }

    cout << "Выжило " << passangers << " человек!";
};

void convert() {
    int a;
    double b;
    short c;
    bool d;
    float e;
    int mode;

    cout << "Введите int: ";
    cin >> a;

    cout << "Введите double: ";
    cin >> b;

    cout << "Введите short: ";
    cin >> c;

    cout << "Введите bool: ";
    cin >> d;

    cout << "Введите float: ";
    cin >> e;

    cout << "1. Сумма\n2. Умножение\n3. Деление\n4. Вычитание\n >>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            float sum;
            sum = a + b + c + d + e;
            cout << sum;
            break;
        case 2:
            float prod;
            prod = a * b * c * d * e;
            cout << prod;
            break;
        case 3:
            float div;
            div = a / b / c / d / e;
            cout << div;
            break;
        case 4:
            float min;
            min = a - b - c - d - e;
            cout << min;
            break;
        default:
            break;
    }
};

void jobs() {
    int salary;
    int workDays;
    int workHours;
    bool remote;

    cout << "Введите желаемую зарплату: ";
    cin >> salary;

    cout << "Введите желаемое количество рабочих дней: ";
    cin >> workDays;

    cout << "Введите желаемое количество часов в раб.дне: ";
    cin >> workHours;

    cout << "Удаленка 1 - да; 0 - нет: ";
    cin >> remote;

    if (salary < 30000 && workDays > 4 &&
        (workHours > 8 || (workDays > 7 && workHours > 5)) && !remote) {
        if (salary > 20000) {
            cout << "Офигевшие.\n";
        }
        cout << "Вы приняты!";
    } else {
        cout << "фу. безработный.";
    }
};

bool drive(){
    int age;

    cout << "Возраст: ";
    cin >> age;

    return (age >= 18);
};

int discount() {
    cout << "склад сгорел, денег не будет ):";
    return -1;
};

int main(int argc, char const *argv[]) {
    // cout << "Площадь:\n" << area();
    // cout << "\n\nОбъём:\n" << volume();
    // ship();
    // convert();
    // jobs();
    while (1) {
        cout << drive() << endl;
    };
    return 0;
}