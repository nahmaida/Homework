#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

class Elevator {
   public:
    void goToFloor(int floor) {
        if (isWorking && floor >= bottomFloor && floor <= topFloor) {
            // считает, сколько этажей нужно проехать
            int timeToWait = abs(floor - currentFloor);
            cout << "Едем..." << endl;
            // ждет по секунде на этаж
            for (int i = 0; i < timeToWait; i++) {
                cout << "..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            setCurrentFloor(floor);
            cout << "Приехали. На " << currentFloor << " этаж.\n";
        } else {
            cout << "лифт не работает. или этаж плохой. читайте инструкцию."
                 << endl;
        }
    }

    void status() {
        cout << endl;
        getIsWorking();
        getCurrentFloor();
        getBottomFloor();
        getTopFloor();
        cout << endl;
    }

    void settings() {
        int choice;
        cout << "0. Выключить\n1. Включить\n2. Телепортировать на этаж\n3. "
                "Изменить нижний этаж\n4. Изменить верхний этаж\n>> ";
        cin >> choice;
        int floor, lower, upper;
        switch (choice) {
            case 0:
                setIsWorking(false);
                break;
            case 1:
                setIsWorking(true);
                break;
            case 2:
                cout << "Введите этаж: ";
                cin >> floor;
                goToFloor(floor);
                break;
            case 3:
                cout << "Введите этаж\n>> ";
                cin >> lower;
                setBottomFloor(lower);
                break;
            case 4:
                cout << "Введите этаж\n>> ";
                cin >> upper;
                setBottomFloor(upper);
            default:
                break;
        }
        cout << "Сделано.\n";
    }

   private:
    int bottomFloor;
    int topFloor;
    int currentFloor;
    bool isWorking;

    // гетеро
    void getBottomFloor() const {
        cout << "Нижний этаж: " << bottomFloor << endl;
    }
    void getTopFloor() const { cout << "Верхний этаж: " << topFloor << endl; }
    void getCurrentFloor() const {
        cout << "Текущий этаж: " << currentFloor << endl;
    }
    void getIsWorking() const {
        if (isWorking) {
            cout << "Лифт работает." << endl;
        } else {
            cout << "Лифт не работает." << endl;
        }
    }

    // сетеро
    void setBottomFloor(int bottomFloor) {
        if (bottomFloor < topFloor) {
            this->bottomFloor = bottomFloor;
        } else {
            cout << "Нижний этаж должен быть меньше верхнего." << endl;
        }
    }
    void setTopFloor(int topFloor) {
        if (topFloor > bottomFloor) {
            this->topFloor = topFloor;
        } else {
            cout << "Верхний этаж должен быть больше нижнего." << endl;
        }
    }
    void setCurrentFloor(int currentFloor) {
        if (currentFloor >= bottomFloor && currentFloor <= topFloor) {
            this->currentFloor = currentFloor;
        } else {
            cout << "Этаж должен быть в пределах диапазона." << endl;
        }
    }
    void setIsWorking(bool isWorking) { this->isWorking = isWorking; }

   public:
    Elevator(int bottomFloor, int topFloor)
        : bottomFloor(bottomFloor),
          topFloor(topFloor),
          currentFloor(bottomFloor),
          isWorking(true) {}
};

int main(int argc, char const *argv[]) {
    Elevator lift(1, 10);
    cout << "Добро пожаловать в ✨ЛИФТ™✨" << endl;
    while (1) {
        int choice;
        cout << "0. Поехать на этаж\n1. Инструкция\n2. Настройки\n3. Взорвать "
                "лифт (выход)\n>> ";
        cin >> choice;
        switch (choice) {
            case 0:
                int floor;
                cout << "Введите этаж: ";
                cin >> floor;
                lift.goToFloor(floor);
                break;
            case 1:
                lift.status();
                break;
            case 2:
                lift.settings();
                break;
            case 3:
                cout << "Лифт был уничтожен." << endl;
                return 0;
            default:
                break;
        }
    }
    return 0;
}
