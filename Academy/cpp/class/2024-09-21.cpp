#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

namespace colors {
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";
}  // namespace colors

struct Character {
    int health = 100;
    int damageMod = 10;
    int hunger = 0;
    int thirst = 0;
    int money = 20;
    string name;
    map<string, int> inventory = {{"Аптечка", 1}, {"Патроны", 20}};
};

struct Enemy {
    string name;
    string weapon;
    int health;
    int damage;
};

class Game {
   public:
    Character self;
    int difficulty = 1;

    void intro() {
        cout << "Введите сложность (от 1 до 5)\n>> ";
        cin >> difficulty;
        difficulty = max(1, min(difficulty, 5));

        cout << "1920-е годы, эпоха джаза, великой депрессии и великих "
                "перемен.\n"
             << "В шумной Вене живёт " << colors::RED
             << "Некий австрийский художник" << colors::RESET
             << ".\nОднако он не подозревает, что на него идет охота из "
                "будущего.\n"
             << "Ваша миссия — защитить его, не нарушая ход времени.\n"
             << colors::YELLOW << "Как вас зовут?" << colors::RESET << "\n>> ";

        cin >> self.name;
        cout << colors::GREEN << "Привет, " << self.name << "!" << colors::RESET
             << "\nВы просыпаетесь с автоматом и кучкой патронов.";

        startMission();
    }

   private:
    int defeatedEnemies = 0;

    void startMission() {
        int attempts = 0;

        while (attempts < 5) {
            string choice;
            cout
                << "\nЧерез час, Австрийский Художник направится в университет."
                << endl
                << colors::YELLOW << "Пойти в университет (да/нет)?"
                << colors::RESET << "\n>> ";
            cin >> choice;

            if (choice == "да") {
                cout << "Вы приходите в университет и замечаете Художника. "
                        "Ваша цель - его защитить.\n";
                plot();
                return;
            } else if (choice == "нет") {
                cout << "Вы остались дома.\n";
                attempts++;
            } else {
                cout << "Неверный ввод.\n";
            }
        }

        cout << colors::RED
             << "Пока вы сидели дома, Художника застрелил водитель трамвая. "
                "Миссия провалена."
             << colors::RESET << endl;
    }

    void combat() {
        vector<string> enemies = {"Грабитель",
                                  "Ниндзя",
                                  "Ассасин",
                                  "Маг",
                                  "Джедай",
                                  "Паровой робот",
                                  "Гангстер-музыкант",
                                  "Безумный физик",
                                  "Пивной барон",
                                  "Зомби-джазист"};

        vector<string> weapons = {"пистолетом",
                                  "ножом",
                                  "мечом",
                                  "кулаками",
                                  "шляпой с лезвиями",
                                  "коктейлем Молотова",
                                  "зонтом-арбалетом",
                                  "радиоактивной сигарой",
                                  "паровой пушкой",
                                  "музыкальной шкатулкой, вызывающей бурю"};

        Enemy attacker;
        attacker.name = enemies[rand() % enemies.size()];
        attacker.weapon = weapons[rand() % weapons.size()];
        attacker.health = rand() % 100 + 50;
        attacker.damage = rand() % 10 + 10;

        cout << "На Художника напал " << colors::GREEN << attacker.name << " с "
             << attacker.weapon << colors::RESET << "!\n";

        while (self.health > 0 && attacker.health > 0) {
            cout << colors::CYAN
                 << "Характеристики врага:\nЗдоровье: " << attacker.health
                 << "\nУрон: " << attacker.damage << colors::RESET
                 << colors::RED << "\nВаше здоровье: " << self.health
                 << colors::RESET << endl;
            cout << colors::YELLOW
                 << "1. Выстрелить\n2. Ударить\n3. Защищаться\n4. Использовать "
                    "аптечку"
                 << colors::RESET << "\n>> ";

            int choice;
            cin >> choice;
            handleCombatChoice(choice, attacker);
        }
    }

    void handleCombatChoice(int choice, Enemy& attacker) {
        cout << endl;
        int damage;
        switch (choice) {
            case 1:
                if (self.inventory["Патроны"] > 0) {
                    damage = rand() % 10 + self.damageMod;
                    attacker.health -= damage;
                    self.inventory["Патроны"]--;
                    self.health -= attacker.damage;
                    cout << colors::GREEN << "Вы нанесли " << damage
                         << " урона." << colors::RESET << endl;
                    cout << colors::RED << attacker.name << " нанёс вам "
                         << attacker.damage << " урона." << colors::RESET
                         << endl;
                } else {
                    cout << colors::RED << "У вас закончились патроны!"
                         << colors::RESET << endl;
                }
                break;
            case 2:
                damage = rand() % 10;
                attacker.health -= damage;
                self.health -= attacker.damage;
                cout << colors::GREEN << "Вы нанесли " << damage << " урона."
                     << colors::RESET << endl;
                cout << colors::RED << attacker.name << " нанёс вам "
                     << attacker.damage << " урона." << colors::RESET << endl;
                break;
            case 3:
                if (rand() % difficulty == 0) {
                    self.health += 50 / difficulty;
                    cout << colors::GREEN << "Вы защитились от атаки."
                         << colors::RESET << endl;
                } else {
                    self.health -= attacker.damage;
                    cout << colors::RED << "Вы не смогли защититься."
                         << colors::RESET << endl;
                }
                break;

            case 4:
                if (self.inventory["Аптечка"] > 0) {
                    self.health += 30;
                    self.inventory["Аптечка"]--;
                    cout << colors::GREEN
                         << "Вы использовали аптечку и восстановили здоровье."
                         << colors::RESET << endl;
                } else {
                    cout << colors::RED << "У вас нет аптечек." << colors::RESET
                         << endl;
                }
                break;

            default:
                cout << colors::RED << "Неверный выбор." << colors::RESET
                     << endl;
                break;
        }

        if (self.health <= 0) {
            cout << colors::RED << "Вы погибли. Миссия провалена."
                 << colors::RESET << endl;
        } else if (attacker.health <= 0) {
            cout << colors::GREEN << "Вы защитили Художника!" << colors::RESET
                 << endl;
            defeatedEnemies++;
            rewardPlayer();
        }
    }

    void rewardPlayer() {
        int reward = rand() % 50 + 50;
        self.money += reward;
        cout << colors::GREEN << "Вы получили " << reward << " шиллингов."
             << colors::RESET << endl;

        if (rand() % 2 == 0) {
            self.inventory["Патроны"] += 5;
            cout << colors::GREEN << "Вы также нашли 5 патронов!"
                 << colors::RESET << endl;
        }
    }

    void plot() {
        srand(time(0));
        while (self.health > 0) {
            updatePlayerStatus();

            if (self.hunger >= 100 || self.thirst >= 100) {
                self.health -= 10;
                cout << colors::RED << "Вы голодны и устали." << colors::RESET
                     << endl;
            }

            int choice;
            displayPlayerOptions();
            cin >> choice;
            handlePlayerChoice(choice);

            // ивенты
            if (rand() % 10 == 0) {
                cout << colors::BLUE
                     << "Внезапно начинается сильный дождь, "
                        "вы теряете время на укрытие."
                     << colors::RESET << endl;
                self.hunger += 10;
                self.thirst += 10;
            }

            if (rand() % 3 == 0) {
                combat();
            }

            if (defeatedEnemies >= difficulty + 3) {
                endMissionSuccess();
                return;
            }
        }

        cout << colors::RED << "Вы умерли! Миссия провалена." << colors::RESET
             << endl;
    }

    void updatePlayerStatus() {
        self.hunger += difficulty * 3;
        self.thirst += difficulty * 3;
        self.health += 6 - difficulty;
    }

    void shop() {
        int choice;
        cout << colors::YELLOW << "Добро пожаловать в мир капитализма!"
             << colors::RESET
             << "\n1. Купить аптечку (30 шиллингов)\n2. Купить 10 патронов (30 "
                "шиллингов)\n3. Отполировать винтовку (50 шиллингов, +5 к "
                "урону)\n>> ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (self.money >= 30) {
                    self.inventory["Аптечка"]++;
                    self.money -= 30;
                    cout << colors::GREEN << "Вы купили аптечку."
                         << colors::RESET << endl;
                } else {
                    cout << colors::RED << "Недостаточно денег."
                         << colors::RESET << endl;
                }
                break;
            case 2:
                if (self.money >= 30) {
                    self.inventory["Патроны"] += 10;
                    self.money -= 30;
                    cout << colors::GREEN << "Вы купили 10 патронов."
                         << colors::RESET << endl;
                } else {
                    cout << colors::RED << "Недостаточно денег."
                         << colors::RESET << endl;
                }
            case 3:
                if (self.money >= 50) {
                    self.damageMod += 5;
                    self.money -= 50;
                    cout << colors::GREEN << "Вы отполировали винтовку."
                         << colors::RESET << endl;
                } else {
                    cout << colors::RED << "Недостаточно денег."
                         << colors::RESET << endl;
                }
        }
    }

    void displayPlayerOptions() {
        cout << colors::CYAN << "\nВаши характеристики:\nГолод: " << self.hunger
             << "\nЖажда: " << self.thirst << "\nЗдоровье: " << self.health
             << "\nДеньги: " << self.money
             << "\nАптечек: " << self.inventory["Аптечка"]
             << "\nПатронов: " << self.inventory["Патроны"] << colors::RESET
             << endl;

        cout << colors::YELLOW
             << "\n1. Купить воду (10 шиллингов)\n2. Поесть (20 шиллингов)\n3. "
                "Ограбить незнакомца\n4. Пойти в магазин\n5. Ничего"
             << colors::RESET << "\n>> ";
    }
    void handlePlayerChoice(int choice) {
        switch (choice) {
            case 1:
                buyWater();
                break;
            case 2:
                buyFood();
                break;
            case 3:
                attemptRobbery();
                break;
            case 4:
                shop();
                break;
            default:
                break;
        }
    }

    void buyWater() {
        if (self.money >= 10) {
            self.thirst = max(0, self.thirst - 30);
            self.money -= 10;
            cout << colors::GREEN << "Вы выпили воду." << colors::RESET << endl;
        } else {
            cout << colors::RED << "Недостаточно денег." << colors::RESET
                 << endl;
        }
    }

    void buyFood() {
        if (self.money >= 20) {
            self.hunger = max(0, self.hunger - 30);
            self.money -= 20;
            cout << colors::GREEN << "Вы поели." << colors::RESET << endl;
        } else {
            cout << colors::RED << "Недостаточно денег." << colors::RESET
                 << endl;
        }
    }

    void attemptRobbery() {
        if (rand() % 2) {
            cout << colors::GREEN << "Вы успешно ограбили незнакомца."
                 << colors::RESET << endl;
            self.money += 50;
        } else {
            self.health -= 20;
            cout << colors::RED
                 << "Незнакомец оказался сильнее! Вы получили урон."
                 << colors::RESET << endl;
        }
    }

    void useMedkit() {
        if (self.inventory["Аптечка"] > 0) {
            self.health += 50;
            self.inventory["Аптечка"]--;
            cout << colors::GREEN
                 << "Вы использовали аптечку и восстановили 50 здоровья."
                 << colors::RESET << endl;
        } else {
            cout << colors::RED << "У вас нет аптечек!" << colors::RESET
                 << endl;
        }
    }

    void bossFight() {
        Enemy boss;
        boss.name = "Тень времени";
        boss.weapon = "косой";
        boss.health = 100 * difficulty;
        boss.damage = 10 * difficulty;

        cout << colors::RED << "Внезапно появляется " << boss.name << " с "
             << boss.weapon << "!" << colors::RESET << endl;

        while (self.health > 0 && boss.health > 0) {
            cout << colors::CYAN
                 << "Характеристики босса:\nЗдоровье: " << boss.health
                 << "\nУрон: " << boss.damage << colors::RESET << colors::RED
                 << "\nВаше здоровье: " << self.health << colors::RESET << endl;
            cout << colors::YELLOW
                 << "1. Атаковать\n2. Ударить\n3. Защищаться\n4. Использовать "
                    "аптечку"
                 << colors::RESET << "\n>> ";

            int choice;
            cin >> choice;
            handleCombatChoice(choice, boss);

            if (boss.health <= 0) {
                cout << colors::GREEN
                     << "Вы победили босса и защитили Художника!"
                     << colors::RESET << endl;
                defeatedEnemies += 2;
                rewardPlayer();
                break;
            }
        }

        if (self.health <= 0) {
            cout << colors::RED << "Босс вас убил. Миссия провалена."
                 << colors::RESET << endl;
        }
    }

    void endMissionSuccess() {
        bossFight();
        cout << colors::GREEN
             << "\nТень времени побеждена, и Художник теперь в "
                "безопасности.\nСолнце заходит, и вы спокойно идете домой, "
                "выполнив свой долг."
             << colors::RESET << endl;
    }
};

int main() {
    Game game;
    game.intro();
    return 0;
}
