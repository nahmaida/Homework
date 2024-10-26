#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Reservoir {
   private:
    string name;
    string type;
    double maxDepth;
    double length;
    double width;

   public:
    // конструктор с параметрами
    Reservoir(string name, string type, double maxDepth, double length,
              double width) {
        this->name = name;
        this->type = type;
        this->maxDepth = maxDepth;
        this->length = length;
        this->width = width;
    }
    // конструктор копирования
    Reservoir(const Reservoir &other) {
        this->name = other.name;
        this->type = other.type;
        this->maxDepth = other.maxDepth;
        this->length = other.length;
        this->width = other.width;
    }
    // конструктор по умолчанию
    Reservoir() {
        this->name = "";
        this->type = "";
        this->maxDepth = 0;
        this->length = 0;
        this->width = 0;
    }

    // гетеры
    string getName() { return name; }
    string getType() { return type; }
    double getMaxDepth() { return maxDepth; }
    double getLength() { return length; }
    double getWidth() { return width; }
    double getVolume() { return length * width * maxDepth; }
    double getArea() { return length * width; }

    // сетеры
    void setName(string name) { this->name = name; }
    void setType(string type) { this->type = type; }
    void setMaxDepth(double maxDepth) { this->maxDepth = maxDepth; }
    void setLength(double length) { this->length = length; }
    void setWidth(double width) { this->width = width; }

    bool isSameType(Reservoir other) { return this->type == other.type; }

    void compareArea(Reservoir other) {
        if (!this->isSameType(other)) {
            cout << "Ошибка: Резервуары имеют разные типы" << endl;
        } else if (this->getArea() > other.getArea()) {
            cout << "Площадь первого резервуара больше" << endl;
        } else if (this->getArea() < other.getArea()) {
            cout << "Площадь второго резервуара больше" << endl;
        } else {
            cout << "Площади равны" << endl;
        }
    }

    void print() {
        cout << "Имя: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Макс. глубина (м): " << maxDepth << endl;
        cout << "Длина (м): " << length << endl;
        cout << "Ширина (м): " << width << endl;
        cout << "Обьем (м3): " << getVolume() << endl;
        cout << "Площадь (м2): " << getArea() << endl;
        cout << endl;
    }
};

void listReservoirs(vector<Reservoir> reservoirs) {
    for (int i = 0; i < reservoirs.size(); i++) {
        cout << "Резервуар " << i + 1 << ":" << endl;
        reservoirs[i].print();
    }
}

int main(int argc, char const *argv[]) {
    vector<Reservoir> reservoirs;
    while (1) {
        int choice;
        cout
            << "1. Показать резервуары\n2. Создать резервуар\n3. Сравнить "
               "типы\n4. Сравнить площади\n5. Удалить резервуар\n6. Выход\n>> ";
        cin >> choice;
        int i, j;
        double maxDepth, length, width;
        string name, type;
        switch (choice) {
            case 1:
                listReservoirs(reservoirs);
                break;
            case 2:
                cout << "Введите имя\n>> ";
                cin >> name;
                cout << "Введите тип\n>> ";
                cin >> type;
                cout << "Введите макс. глубину\n>> ";
                cin >> maxDepth;
                cout << "Введите длину\n>> ";
                cin >> length;
                cout << "Введите ширину\n>> ";
                cin >> width;
                reservoirs.push_back(
                    Reservoir(name, type, maxDepth, length, width));
                break;

            case 3:
                listReservoirs(reservoirs);
                cout << "Введите номера резервуара 1\n>> ";
                cin >> i;
                cout << "Введите номера резервуара 2\n>> ";
                cin >> j;
                if (reservoirs[i - 1].isSameType(reservoirs[j - 1])) {
                    cout << "Одинаковый тип" << endl;
                } else {
                    cout << "Разные типы" << endl;
                }
                break;
            case 4:
                listReservoirs(reservoirs);
                cout << "Введите номера резервуара 1\n>> ";
                cin >> i;
                cout << "Введите номера резервуара 2\n>> ";
                cin >> j;
                reservoirs[i - 1].compareArea(reservoirs[j - 1]);
                break;
            case 5:
                listReservoirs(reservoirs);
                cout << "Введите номер резервуара\n>> ";
                cin >> i;
                reservoirs.erase(reservoirs.begin() + i - 1);
                cout << "Резервуар удален" << endl;
                break;
            case 6:
                return 0;
            default:
                break;
        }
    }
    return 0;
}