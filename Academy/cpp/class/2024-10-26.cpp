#include <iostream>
#include <string>
using namespace std;

class Goblin {
    int level;
    int health;

   public:
    Goblin(int level, int health) {
        this->level = level;
        this->health = health;
    }

    Goblin operator+(const Goblin& other) const {
        int newLevel = this->level + other.level;
        int newHealth = this->health + other.health;
        return Goblin(newLevel, newHealth);
    }

    Goblin operator-(const Goblin& other) const {
        int newLevel = this->level - other.level;
        int newHealth = this->health - other.health;
        return Goblin(newLevel, newHealth);
    }

    Goblin operator*(const Goblin& other) const {
        int newLevel = this->level * other.level;
        int newHealth = this->health * other.health;
        return Goblin(newLevel, newHealth);
    }

    Goblin operator/(const Goblin& other) const {
        int newLevel = this->level / other.level;
        int newHealth = this->health / other.health;
        return Goblin(newLevel, newHealth);
    }

    friend ostream& operator<<(ostream& os, const Goblin& goblin);

    void operator++() {
        level++;
        health++;
    }

    void operator--() {
        level--;
        health--;
    }

    bool operator==(const Goblin& other) const {
        return level == other.level && health == other.health;
    }

    bool operator!=(const Goblin& other) const { return !(*this == other); }

    bool operator<(const Goblin& other) const {
        return level < other.level && health < other.health;
    }

    bool operator>(const Goblin& other) const {
        return level > other.level && health > other.health;
    }
};

ostream& operator<<(ostream& os, const Goblin& goblin) {
    os << "Уровень: " << goblin.level << ", ХП: " << goblin.health;
    return os;
}

int main(int argc, char const* argv[]) {
    Goblin goblin1(1, 10);
    Goblin goblin2(2, 20);

    Goblin goblin3 = goblin1 + goblin2;
    Goblin goblin4 = goblin2 - goblin1;
    Goblin goblin5 = goblin1 * goblin2;
    Goblin goblin6 = goblin1 / goblin2;

    cout << goblin3 << endl;
    cout << goblin4 << endl;
    cout << goblin5 << endl;
    cout << goblin6 << endl;

    ++goblin1;
    --goblin2;

    cout << goblin1 << endl;
    cout << goblin2 << endl;

    if (goblin1 == goblin2) {
        cout << "Гоблины равны" << endl;
    } else {
        cout << "Гоблины не равны" << endl;
    }

    if (goblin1 != goblin2) {
        cout << "Гоблины не равны" << endl;
    } else {
        cout << "Гоблины равны" << endl;
    }

    if (goblin1 < goblin2) {
        cout << "Гоблин 1 меньше Гоблина 2" << endl;
    } else {
        cout << "Гоблин 1 не меньше Гоблина 2" << endl;
    }

    if (goblin1 > goblin2) {
        cout << "Гоблин 1 больше Гоблина 2" << endl;
    } else {
        cout << "Гоблин 1 не больше Гоблина 2" << endl;
    }
    return 0;
}
