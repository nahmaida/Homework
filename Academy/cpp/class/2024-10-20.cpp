#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Kabanchik {
   private:
    string name;
    int hp;
    int happiness;
    vector<string> food;

   public:
    Kabanchik() {
        this->name = "ваня";
        this->hp = 100;
        this->happiness = 100;
        this->food = {"кровь врагов", "мертвая плоть", "души грешников"};
    }
    Kabanchik(string name, int hp, int happiness, vector<string> food) {
        this->name = name;
        this->hp = hp;
        this->happiness = happiness;
        this->food = food;
    }
    Kabanchik(const Kabanchik& other) {
        this->name = other.name;
        this->hp = other.hp;
        this->happiness = other.happiness;
        this->food = other.food;
    }

    string getName() const { return this->name; }
    int getHp() const { return this->hp; }
    int getHappiness() const { return this->happiness; }
    vector<string> getFood() const { return this->food; }

    void feed(string foodToFeed) {
        for (int i = 0; i < this->food.size(); i++) {
            if (this->food[i] == foodToFeed) {
                this->food.erase(this->food.begin() + i);
                this->happiness += 10;
                this->hp += 5;
                cout << "Ням-ням" << endl;
                return;
            }
        }
        cout << "Нет такой еды" << endl;
    }

    void heal() {
        this->hp += 30;
        cout << "Кабанчик исцелен" << endl;
    }

    void hurt() { this->hp -= 20; }

    void hurtEmotionally() { this->happiness -= 10; }

    void brutallyMurder() { this->hp = 0; }

    void printStatus() const {
        cout << "Имя: " << this->name << endl;
        cout << "Здоровье: " << this->hp << endl;
        cout << "Счастье: " << this->happiness << endl;
        cout << "Еда: ";
        for (string f : this->food) {
            cout << f << endl;
        }
    }

    void addFood(string food) { this->food.push_back(food); }

    void restore() {
        this->hp = 100;
        this->happiness = 100;
    }
};

class Game {
   private:
    Kabanchik* player;
    vector<string> foodInShop;

    void shop() {
        cout << "Велкам в магазин" << endl;
        cout << "Выберите еду:" << endl;
        for (int i = 0; i < this->foodInShop.size(); i++) {
            cout << i + 1 << ". " << this->foodInShop[i] << endl;
        }
        cout << ">> ";
        int choice;
        cin >> choice;
        if (choice >= 1 && choice <= this->foodInShop.size()) {
            this->player->addFood(this->foodInShop[choice - 1]);
            cout << "Спасибо за покупку!" << endl;
        } else {
            cout << "Неверный выбор." << endl;
        }
    }

    void find() {
        srand(time(NULL));
        while (1) {
            this->player->hurt();

            if (this->player->getHp() <= 0) {
                break;
            }

            cout << "Вы отправляетесь на поиски кабанчика..." << endl;
            int random = rand() % 3;
            if (!random) {
                cout << "Кабанчик найден!" << endl;
                break;
            } else {
                cout << "Кабанчик не найден. Вы пробуете еще раз." << endl;
            }
        }
    }

   public:
    Game() {
        this->player = new Kabanchik();
        this->foodInShop = this->player->getFood();
    }
    Game(Kabanchik* player, vector<string> food) {
        this->player = player;
        this->foodInShop = food;
    }

    Kabanchik* getPlayer() const { return this->player; }
    vector<string> getFood() const { return this->foodInShop; }

    void startGame() {
        bool isLost = false;
        while (1) {
            this->player->hurtEmotionally();
            if (this->player->getHp() <= 0) {
                cout << "Кабанчик умер ):\nИгра окончена." << endl;
                break;
            }
            if (this->player->getHappiness() <= 20) {
                cout << "Кабанчик сбежал от вашей диктатуры!" << endl;
                isLost = true;
            }

            if (isLost) {
                cout << "1. Пойти на поиски кабанчика\n" << endl;
            } else {
                cout
                    << "\n1. Покормить кабанчика\n2. Состояние\n3. Купить "
                       "еды\n4. "
                       "Вылечить кабанчика\n5. Приготовить шашлык\n6. Ничего\n";
            }
            cout << ">> ";
            int choice;
            cin >> choice;
            string food;
            vector<string> foods = this->player->getFood();
            int i;
            switch (choice) {
                case 1:
                    if (isLost) {
                        this->find();
                        this->player->restore();
                        isLost = false;
                        break;
                    }
                    cout << "Выберите еду:\n";

                    for (i = 0; i < foods.size(); i++) {
                        cout << i + 1 << ". " << foods[i] << endl;
                    }
                    cout << ">> ";
                    cin >> i;
                    if (i >= 1 && i <= foods.size()) {
                        food = foods[i - 1];
                        this->player->feed(food);
                    } else {
                        cout << "Неверный выбор." << endl;
                    }
                    break;
                case 2:
                    cout << "Состояние кабанчика:" << endl;
                    this->player->printStatus();
                    break;
                case 3:
                    this->shop();
                    break;
                case 4:
                    this->player->heal();
                    break;
                case 5:
                    this->player->brutallyMurder();
                    cout << "Шашлык готов! Приятного аппетита." << endl;
                    break;
                default:
                    break;
            }
        }
    }

    void addFood(string food) { this->foodInShop.push_back(food); }
};

int main(int argc, char const* argv[]) {
    Kabanchik kaban = Kabanchik();
    vector<string> food = {
        "Hamburger", "Double Cheeseburger", "Triple Cheeseburger",
        "Big Mac",   "Quarter Pounder",     "Big N' Tasty",
        "McDouble",  "Bacon McDouble",      "Daily Double",
        "McFeast"};
    Game game = Game(&kaban, food);
    game.startGame();
    while (1) {
        Kabanchik clone = kaban;
        clone.restore();
        cout << "Какое совпадение! Родился кабанчик с ровно таким же именем."
             << endl;
        Game newGame = Game(&clone, food);
        newGame.startGame();
    }
    return 0;
}