#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Base {
   private:
    int hp;
    string name;

   public:
    Base() {
        this->hp = 100;
        this->name = "Это база.";
    }
    Base(int hp, string name) {
        this->hp = hp;
        this->name = name;
    }

    void restore() { this->hp = 100; }

    int getHp() { return hp; }

    void setHp(int hp) { this->hp = hp; }
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

    void attack(Base &base) { base.setHp(base.getHp() - this->skills); }
};

int main(int argc, char const *argv[]) {
    Goblin one{100, "Гоблин 1", 10};
    Goblin two{80, "Гоблин 2", 20};
    Goblin three{120, "Гоблин 3", 80};
    Goblin four{90, "Гоблин 4", 50};
    Goblin five{70, "Гоблин 5", 30};
    vector<Goblin> goblins = {one, two, three, four, five};

    Base base;
    for (int i = 0; i < goblins.size(); i++) {
        base.restore();
        goblins[i].attack(base);
        goblins[i].getInfo();
        cout << "База: " << base.getHp() << endl << endl;
    }
    return 0;
}
