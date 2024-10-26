#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GoblinArmy;

class Date {
   private:
    int year;
    int month;
    int day;

   public:
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    string getDate() const {
        return to_string(year) + "." + to_string(month) + "." + to_string(day);
    }

    int getYear() const { return this->year; }
    int getMonth() const { return this->month; }
    int getDay() const { return this->day; }

    void setYear(int year) { this->year = year; }
    void setMonth(int month) { this->month = month; }
    void setDay(int day) { this->day = day; }
    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};

class Goblin {
   private:
    int hp;
    string name;
    int skills;

   public:
    Goblin() {
        this->hp = 100;
        this->name = "";
        this->skills = 1;
    }

    Goblin(int hp, string name) {
        this->hp = hp;
        this->name = name;
    }

    Goblin(int hp, string name, int skills) : Goblin(hp, name) {
        this->skills = skills;
    }

    void getInfo() {
        cout << "Имя: " << name << endl;
        cout << "ХП: " << hp << endl;
        cout << "Уровень: " << skills << endl;
    }

    void setInfo(int hp, string name, int skills) {
        this->hp = hp;
        this->name = name;
        this->skills = skills;
    }

    friend void battle(GoblinArmy &one, GoblinArmy &two);
};

class GoblinArmy {
   private:
    vector<Goblin> goblins;
    string name;

   public:
    GoblinArmy(string name) { this->name = name; }

    void addGoblin(Goblin goblin) { this->goblins.push_back(goblin); }

    void spawnArmy() {
        cout << "Спавним армию " << this->name << "...\n";
        int size;
        cout << "Введите количество гоблинов\n>> ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            Goblin goblin(rand() % 100, "Гоблин " + to_string(i + 1),
                          rand() % 100 + 1);
            this->addGoblin(goblin);
        }
        cout << "Армия родилась." << endl;
    }

    friend void battle(GoblinArmy &one, GoblinArmy &two);
};

void battle(GoblinArmy &one, GoblinArmy &two) {
    cout << "\nИдет жестокий бой..." << endl;
    srand(time(NULL));
    int oneSize = one.goblins.size();
    int twoSize = two.goblins.size();
    int oneIndex = 0;
    int twoIndex = 0;
    while (oneSize > 0 && twoSize > 0) {
        int oneDamage = rand() % one.goblins[oneIndex].skills + 1;
        int twoDamage = rand() % two.goblins[twoIndex].skills + 1;
        one.goblins[oneIndex].hp -= twoDamage;
        two.goblins[twoIndex].hp -= oneDamage;
        if (one.goblins[oneIndex].hp <= 0) {
            one.goblins.erase(one.goblins.begin() + oneIndex);
            oneSize--;
            oneIndex++;
        }
        if (two.goblins[twoIndex].hp <= 0) {
            two.goblins.erase(two.goblins.begin() + twoIndex);
            twoSize--;
            twoIndex++;
        }
    }
    if (oneSize > 0) {
        cout << "Армия \"" << one.name << "\" победила!";
    } else {
        cout << "Армия \"" << two.name << "\" победила!";
    }
}

int main(int argc, char const *argv[]) {
    // Date one(2024, 10, 19);
    // cout << one.getDate() << endl;
    // one.setDate(2024, 10, 20);
    // cout << one.getDate() << endl;
    // Date two(2022, 10, 21);
    // cout << two.getDate() << endl;
    // two.setYear(2321);
    // cout << two.getYear() << endl;
    // Date three(2023, 5, 12);
    // cout << three.getMonth() << endl;
    // three.setMonth(10);
    // cout << three.getMonth() << endl;

    // const Date four(2023, 5, 12);
    // cout << four.getDate() << endl;
    // const Date five(2023, 5, 12);
    // cout << five.getDate() << endl;

    GoblinArmy one("ЧВК Пригоблина");
    one.spawnArmy();

    GoblinArmy two("Телегизованная Бригада ВСГ");
    two.spawnArmy();

    battle(one, two);

    return 0;
}
