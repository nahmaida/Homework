#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
// шанс того что планета будет обитаемой = 1/HAB_CHANCE * 100%
// т.е если HAB_CHANCE = 10, то шанс 10%
#define HAB_CHANCE 15
#define MINERAL_PRICE 2
#define METAL_PRICE 10
#define GOODS_PRICE 10
using namespace std;

double phi = (1 + sqrt(5)) / 2;

class Empire {};

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

class Resources {
   public:
    resource name;
    int amount;
    Resources(resource name, int amount) : name(name), amount(amount) {}
};

struct Building {
    string name;
    string description;
    vector<Resources> output;
};

class Point {
   public:
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
};

struct Line {
    Point start;
    Point end;

    Line(Point s, Point e) : start(s), end(e) {}
};

// распределяет n точек в круг
vector<Point> sunflower(int n, int alpha = 0, bool geodesic = false) {
    vector<Point> points;
    double angleStride = (geodesic) ? 360 * phi : 2 * M_PI / pow(phi, 2);
    int b = round(alpha * sqrt(n));  // кол-во точек на границе

    for (int k = 1; k < n + 1; k++) {
        double radius = sqrt(k - 0.5) / sqrt(n - (b + 1) / 2);
        double theta = k * angleStride;
        int x = round(49.5 * (radius * cos(theta) + 1));
        int y = round(49.5 * (radius * sin(theta) + 1));

        x = max(0, min(99, x));
        y = max(0, min(99, y));
        points.push_back(Point(x, y));
    }
    return points;
}

vector<Resources> addResources(vector<Resources> one, vector<Resources> two) {
    for (int j = 0; j < two.size(); j++) {
        bool found = false;
        for (int i = 0; i < one.size(); i++) {
            if (one[i].name == two[j].name) {
                one[i].amount += two[j].amount;
                found = true;
                break;
            }
        }
        if (!found) one.push_back(two[j]);
    }
    return one;
}

// вирт класс небесное тело
class CelestialBody {
   protected:
    string name;
    int size;
    vector<Resources> resources;
    Empire owner;

   public:
    CelestialBody(string name, int size, vector<Resources> resources,
                  Empire owner)
        : name(name), size(size), resources(resources), owner(owner) {}

    virtual void fill() = 0;
    vector<Resources> getResources() { return resources; }
    string getName() { return name; }
    Empire getOwner() { return owner; }
    int getSize() { return size; }
};

// планета. звезда тоже своего рода планета.
class Planet : public CelestialBody {
   private:
    bool habitable;              // обитаемость
    vector<Building> buildings;  // здания (если обитаемая)
    int population;      // население (если обитаемая)
    habitableType type;  // тип планеты (если обитаемая)

   public:
    Planet(string name, bool isHabitable = false)
        : CelestialBody(name, 0, {}, Empire()),
          habitable(isHabitable),
          population(0),
          type(static_cast<habitableType>(0)) {}

    void fill() override {
        // случайный размер планеты от 10 до 30
        this->size = rand() % 30 + 10;

        // 50% что будут минералы
        if (rand() % 2) {
            int amount = rand() % 10 + 1;  // кол-во минералов от 1 до 10
            resources.push_back(Resources(Минералы, amount));
        }

        // 33% что будет энергия
        if (!(rand() % 3)) {
            int amount = rand() % 10 + 1;  // кол-во энергии от 1 до 10
            resources.push_back(Resources(Энергия, amount));
        }

        // если планета обитаемая, добавить дополнительные свойства
        if (habitable) {
            // случайный тип планеты
            type = static_cast<habitableType>(rand() % 9);
        }
    }

    bool isHabitable() const { return habitable; }
    int getPopulation() const { return population; }
    habitableType getType() const { return type; }
};

// звездная система с планетками
class System : public CelestialBody {
    vector<Planet> planets;
    Point location;

   public:
    System(string name, int size)
        : CelestialBody(name, size, {}, Empire()),
          planets({}),
          location(Point()) {}

    void fill() override {
        for (int i = 0; i < size; i++) {
            bool isHabitable =
                (rand() % HAB_CHANCE == 0);  // определяем обитаемость
            Planet* planet = new Planet(name + " " + to_string(i), isHabitable);

            planet->fill();

            // добавляет ресурсы планеты к системе
            resources = addResources(resources, planet->getResources());
            planets.push_back(*planet);

            delete planet;  // очищаем память
        }
    }

    // возвращает, есть ли в планете обитаемые системы
    bool hasHabitables() const {
        for (Planet planet : planets) {
            if (planet.isHabitable()) {
                return true;
            }
        }
        return false;
    }

    void setLocation(Point point) { location = point; }
    Point getLocation() const { return location; }
};

// галактика с вектором систем
class Galaxy {
    int size;
    vector<System> systems;
    vector<Line> connections;  // хранит гиперлинии между системами

   public:
    Galaxy(int size) : size(size) {}

    void fill() {
        for (int i = 0; i < size; i++) {
            string name = starNames[rand() % starNames.size()];
            int planetCount = rand() % 6 + 1;
            System system(name, planetCount + 1);
            system.fill();
            systems.push_back(system);
        }

        vector<Point> points = sunflower(systems.size());
        for (int j = 0; j < points.size(); j++) {
            systems[j].setLocation(points[j]);
        }

        connectSystems();
    }

    void connectSystems() {
        set<pair<int, int>>
            addedConnections;  // чтобы избежать дублирования соединений
        const int connectionRadius =
            10;  // максимальная дистанция для поиска соседей
        random_device rd;
        mt19937 rng(rd());  // генератор случайных чисел

        for (int i = 0; i < systems.size(); i++) {
            vector<int> nearbySystems;

            // поиск соседей в пределах радиуса
            Point currentLocation = systems[i].getLocation();
            for (int j = 0; j < systems.size(); j++) {
                if (i == j) continue;  // Пропуск самой себя
                Point neighborLocation = systems[j].getLocation();

                // вычисление евклидова расстояния
                double distance =
                    sqrt(pow(neighborLocation.x - currentLocation.x, 2) +
                         pow(neighborLocation.y - currentLocation.y, 2));

                if (distance <= connectionRadius) {
                    nearbySystems.push_back(j);
                }
            }

            // перемешивание соседних систем для случайного выбора
            std::shuffle(nearbySystems.begin(), nearbySystems.end(), rng);

            // случайный выбор 1–3 соседей для соединения
            int numConnections = min((int)nearbySystems.size(), rand() % 3 + 1);
            for (int k = 0; k < numConnections; k++) {
                int neighbor = nearbySystems[k];

                // избежание дублирования соединений
                if (addedConnections.count({i, neighbor}) ||
                    addedConnections.count({neighbor, i})) {
                    continue;
                }

                // запись соединения
                addedConnections.insert({i, neighbor});

                // зобавление линии между системами
                Point start = systems[i].getLocation();
                Point end = systems[neighbor].getLocation();
                connections.emplace_back(start, end);
            }
        }
    }

    void printMap() const {
        const int maxHeight = 50;  // максимальная высота карты
        const int maxWidth = 120;  // максимальная ширина карты

        // динамическое создание карты
        vector<vector<string>> map(maxHeight, vector<string>(maxWidth, " "));

        // рисуем системы
        for (const System& system : systems) {
            string uninhabitableName =
                "\033[1;33mS\033[0m";  // желтая если нет обитаемых систем
            string inhabitableName = "\033[30;42mS\033[0m";  // зеленая если есть
            string name =
                (system.hasHabitables()) ? inhabitableName : uninhabitableName;

            Point location = system.getLocation();

            // пропорционально масштабируем координаты под размер карты
            int scaledX = (location.x * maxHeight) / 100;
            int scaledY = (location.y * maxWidth) / 100;

            if (scaledX >= 0 && scaledX < maxHeight && scaledY >= 0 &&
                scaledY < maxWidth) {
                map[scaledX][scaledY] = name;
            }
        }

        // рисуем соединения
        for (const Line& line : connections) {
            Point start((line.start.x * maxHeight) / 100,
                        (line.start.y * maxWidth) / 100);
            Point end((line.end.x * maxHeight) / 100,
                      (line.end.y * maxWidth) / 100);
            drawLine(map, start, end);
        }

        // печатаем карту
        for (const auto& row : map) {
            for (const auto& cell : row) {
                cout << cell;
            }
            cout << endl;
        }
    }

   private:
    void drawLine(vector<vector<string>>& map, Point start, Point end) const {
        int x0 = start.x, y0 = start.y;
        int x1 = end.x, y1 = end.y;

        // алгоритм Брезенхэма для рисования линии
        int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
        int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
        int err = dx + dy, e2;

        while (true) {
            if (x0 >= 0 && x0 < map.size() && y0 >= 0 && y0 < map[0].size() &&
                map[x0][y0] == " ") {
                map[x0][y0] = ".";  // отметка пути линии
            }
            if (x0 == x1 && y0 == y1) break;
            e2 = 2 * err;
            if (e2 >= dy) {
                err += dy;
                x0 += sx;
            }
            if (e2 <= dx) {
                err += dx;
                y0 += sy;
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    srand(time(NULL));
    // заполняет список имен
    // временно, потом буду брать мз файла
    starNames.push_back("Alpha Centauri");
    starNames.push_back("Barnard's Star");
    starNames.push_back("Betelgeuse");
    starNames.push_back("Canopus");
    starNames.push_back("Capella");
    starNames.push_back("Deneb");
    starNames.push_back("Epsilon Eridani");
    starNames.push_back("Fomalhaut");
    starNames.push_back("Gacrux");
    starNames.push_back("Hadar");
    starNames.push_back("Iota Orionis");
    starNames.push_back("Jupiter");
    starNames.push_back("Kappa Ceti");
    starNames.push_back("Lambda Ceti");
    starNames.push_back("Mira");
    starNames.push_back("Naiad");
    starNames.push_back("Omega Centauri");
    starNames.push_back("Procyon");
    starNames.push_back("Rigel");
    starNames.push_back("Sigma Draconis");
    starNames.push_back("Tau Ceti");
    starNames.push_back("Upsilon Andromedae");
    starNames.push_back("Vega");
    starNames.push_back("Zeta Puppis");

    // ввод размера галактики пользователем
    int galaxySize = 0;
    while (galaxySize < 90) {
        cout << "Введите количество систем в галактике (минимум - 90, "
                "рекомендуемое - 100): ";
        cin >> galaxySize;
    }

    // создает галактику и заполняет ее
    Galaxy galaxy(galaxySize);
    galaxy.fill();

    // печатает карту
    galaxy.printMap();
    return 0;
}