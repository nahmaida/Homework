#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Hero {
    string name;
    int level;
    int health;

   public:
    Hero(string name, int level, int health) {
        this->name = name;
        this->level = level;
        this->health = health;
    }

    Hero() {
        name = "хз";
        level = 1;
        health = 100;
    }

    int getDamage() const { return level * 2; }
    int getHealth() const { return health; }
    string getName() const { return name; }

    void heal(int value) { health += value; }

    bool operator==(const Hero& other) const { return level == other.level; }

    bool operator!=(const Hero& other) const { return !(*this == other); }

    Hero operator+(const int value) {
        Hero temp = *this;
        temp.level += value;
        return temp;
    }

    Hero operator-(const int value) {
        Hero temp = *this;
        temp.health -= value;
        return temp;
    }

    void operator+=(const int value) { level += value; }

    string operator[](const int index) {
        switch (index) {
            case 0:
                return name;
            case 1:
                return to_string(level);
            case 2:
                return to_string(health);
            default:
                return "";
        }
        return "";
    }

    friend ostream& operator<<(ostream& os, const Hero& hero);
};

ostream& operator<<(ostream& os, const Hero& hero) {
    os << "Имя: " << hero.name << ", Уровень: " << hero.level
       << ", Здоровье: " << hero.health << ", Урон: " << hero.getDamage();
    return os;
}

class Fight {
    Hero& hero1;
    Hero& hero2;

   public:
    Fight(Hero& hero1, Hero& hero2) : hero1(hero1), hero2(hero2) {}
    Fight(const Fight& other) : hero1(other.hero1), hero2(other.hero2) {}

    void start() {
        cout << "Битва между " << hero1.getName() << " и " << hero2.getName() << endl;
        while (hero1.getHealth() > 0 && hero2.getHealth() > 0) {
            hero2 = hero2 - hero1.getDamage();
            if (hero2.getHealth() <= 0) {
                cout << "Победил " << hero1.getName() << endl;
                hero1 += 1;
                break;
            }
            hero1 = hero1 - hero2.getDamage();
            if (hero1.getHealth() <= 0) {
                cout << "Победил " << hero2.getName() << endl;
                hero2 += 1;
                break;
            }
        }
    }
};

Hero createHero() {
    string name;
    int level, health;
    cout << "Введите имя героя\n>> ";
    cin >> name;
    cout << "Введите уровень героя\n>> ";
    cin >> level;
    cout << "Введите здоровье героя\n>> ";
    cin >> health;
    return Hero(name, level, health);
}

Hero pickHero(vector<Hero>& heroes) {
    int choice;
    for (int i = 0; i < heroes.size(); i++) {
        cout << i + 1 << ". " << heroes[i].getName() << endl;
    }
    cout << ">> ";
    cin >> choice;
    if (choice < 1 || choice > heroes.size()) {
        cout << "Неверный выбор!\n";
        return pickHero(heroes);
    }
    return heroes[choice - 1];
}

int main(int argc, char const* argv[]) {
    vector<Hero> heroes;
    while (1) {
        int choice;
        cout << "\n1. Создать героя\n2. Битва!\n3. Статус героя\n4. Выйти\n>> ";
        cin >> choice;
        Hero hero1, hero2;
        Fight fight(hero1, hero2);
        switch (choice) {
            case 1: {
                heroes.push_back(createHero());
                break;
            }
            case 2: {
                if (heroes.size() < 2) {
                    cout << "Недостаточно героев для битвы!\n";
                    break;
                }
                cout << "Выберите героя 1" << endl;
                hero1 = pickHero(heroes);
                cout << "Выберите героя 2" << endl;
                hero2 = pickHero(heroes);
                fight.start();
                break;
            }
            case 3: {
                if (heroes.size() == 0) {
                    cout << "Нет героев!\n";
                    break;
                }
                cout << "Выберите героя" << endl;
                cout << pickHero(heroes);
                break;
            }
            case 4:
                return 0;
            default:
                cout << "Неверный выбор!\n";
                break;
        }
    }
    
    return 0;
}
