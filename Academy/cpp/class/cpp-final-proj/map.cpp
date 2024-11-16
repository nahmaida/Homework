#include <cmath>
#include <iostream>
#include <string>
#include <vector>
// шанс того что планета будет обитаемой = 1/HAB_CHANCE * 100%
// т.е если HAB_CHANCE = 10, то шанс 10%
#define HAB_CHANCE = 10
#define MINERAL_PRICE = 2
#define METAL_PRICE = 10
#define GOODS_PRICE = 10
using namespace std;

// enum возможных типов обитаемых планет
enum habitableType {
    Пустынный,
    Сухой,
    Саванна,
    Океанический,
    Континентальный,
    Тропический,
    Арктический,
    Горный,
    Тундра
};
// вектор возможных названий для систем
vector<string> starNames = {};
// enum ресурсов
enum resource { Минералы, Энергия, Металлы, Блага };

struct Resources {
    resource name;
    int amount;
};

struct Building {
    string name;
    string description;
    vector<Resources> output;
};

vector<Resources> addResources(vector<Resources> one, vector<Resources> two) {
    for (int i = 0; i < one.size(); i++) {
        for (int j = 0; j < two.size(); j++) {
            if (one[i].name == two[j].name) {
                one[i].amount += two[j].amount;
            }
        }
    }
    return one;
}

// вирт класс небесное тело
class CelestialBody {
    string name;
    int size;
    vector<Resources> resources;
    Empire owner;

   public:
    CelestialBody(string name, int size, vector<Resources> resources)
        : name(name), size(size), resources(resources) {}

    virtual void fill() = 0;
    vector<Resources> getResources() { return resources; }
    string getName() { return name; }
    Empire getOwner() { return owner; }
    int getSize() { return size; }
};

// планета. звезда тоже своего рода планета.
class Planet : public CelestialBody {
   public:
    Planet(string name) : name(name), size(0), resources({}), owner(Empire()) {}

    void fill() {
        // случаный размер планеты от 10 до 30
        int size = rand() % 30 + 10;

        // 50% что будут минералы
        if (rand() % 2) {
            // колво минералов от 1 до 10
            int amount = rand() % 10 + 1;
            resources.push_back(Resources(Минералы, amount));
        }

        // 33% что будет энергия
        if (!(rand() % 3)) {
            // колво энергии от 1 до 10
            int amount = rand() % 10 + 1;
            resources.push_back(Resources(Энергия, amount));
        }
    }
};

// обитаемая планета
class HabitablePlanet : public Planet {
    vector<Buildings> buildings;  // Здания, т.е генераторы, институты и т.д.
    int population;      // Население в попах
    habitableType type;  // Тип

   public:
    HabitablePlanet(string name)
        : Planet(name), buildings({}), population(0), type("") {}

    void fill() override {
        // заполняет планету
        Planet::fill();

        // случайный тип планеты
        type = habitableType(rand() % 9);
    }
};

// звездная система с планетками
class System : public CelestialBody {
    vector<Planet> planets;

   public:
    System(string name, int size)
        : name(name), size(size), resources({}), owner(Empire()), planets({}) {}

    void fill() override {
        // создает планеты по размеру
        for (int i = 0; i < size; i++) {
            if (rand() % HAB_CHANCE == 0) {
                // если планета обитаемая
                HabitablePlanet planet(name + " " + to_string(i));
            } else {
                // если планета не обитаемая, то создает обычную планету
                Planet planet(name + " " + to_string(i));
            }
            // заполняет планету
            planet.fill();

            // прибавляет ресурсы планеты и добовляет ее
            resources = addResources(resources, planet.getResources());
            planets.push_back(planet);
        }
    }

    // возвращает, есть ли в планете обитаемые системы
    bool hasHabitables() {
        for (Planet planet : planets) {
            if (planet instanceof HabitablePlanet) {
                return true;
            }
        }
        return false;
    }
};

// галактика с вектором систем
class Galaxy {
    int size;
    vector<System> systems;

   public:
    Galaxy(int size) : size(size) {}

    void fill() {
        for (int i = 0; i < size; i++) {
            // выбирает случайное имя для системы из списка
            string name = starNames[rand() % starNames.size()];

            // выбирает случайное количество планет (от 1 до 6)
            int planetCount = rand() % 6 + 1;

            // Создает систему и заполняет ее, потом добавляет
            System system(name, planetCount + 1);
            system.fill();
            systems.push_back(system);
        }
    }
};
