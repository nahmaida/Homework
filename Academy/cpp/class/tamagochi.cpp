#include <iostream>
#include <string>
using namespace std;


// Структура для питомца
struct Pet {
    string name;
    int level;
    int health;
    int happiness;
};

class Game {
   public:
    // Функция для отображения ASCII-арта питомца
    void drawPet() {
        cout << " /\\_/\\ " << endl;
        cout << "( o.o )" << endl;
        cout << " > ^ < " << endl;
    }



    // Функция для отображения питомца
    void displayPet(const Pet& pet) {
        cout << "Имя питомца: " << pet.name << endl;
        cout << "Уровень: " << pet.level << endl;
        cout << "Здоровье: " << pet.health << endl;
        cout << "Счастье: " << pet.happiness << endl;
        drawPet(); // Отрисовка питомца
    }

    // Функция для отображения меню
    void displayMenu() {
        cout << "1. Играть с питомцем" << endl;
        cout << "2. Отправиться в путешествие" << endl;
        cout << "3. Купить перки" << endl;
        cout << "4. Выйти из программы" << endl;
    }

    void play() {
        Pet myPet;
        myPet.level = 1;
        myPet.health = 100;
        myPet.happiness = 100;

        cout << "Введите имя вашего питомца: ";
        getline(cin, myPet.name);

        bool isRunning = true;
        while (isRunning) {
            displayPet(myPet);
            displayMenu();

            int choice;
            cout << "Выберите действие: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    myPet.happiness += 10;
                    break;
                case 2:
                    // Здесь будет функция для путешествия
                    break;
                case 3:
                    // Здесь будет функция для покупки перков
                    break;
                case 4:
                    isRunning = false;
                    break;
                default:
                    cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            }
        }

    }
};

int main() {
    Game game;
    game.play();
    return 0;
}