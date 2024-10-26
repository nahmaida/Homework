#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Создайте программу, имитирующую многоквартирный
// дом. Необходимо иметь классы “Человек”, “Квартира”,
// “Дом”. Класс “Квартира” содержит динамический массив
// объектов класса “Человек”. Класс “Дом” содержит массив
// объектов класса “Квартира”.
// Создайте методы для отображения кол-ва квартир в доме, какие люди в этих
// квартирах реализуйте static поле, которое подсчитывает общее кол-во людей в
// программе. сделайте static метод чтобы делать return этого static поля.
// --------------------------------------------------
// vector разрешаю используем с кайфом

class Person {
   private:
    string name;
    static inline int total = 0;

   public:
    Person(string name) : name(name) { total++; }
    static int getTotal() { return total; }
    static void setTotal(int value) { total = value; }
    string getName() { return name; }
    ~Person() {
        total--;
        cout << "Гражданин " << name << " погиб." << endl;
    }
};

class Apartment {
   private:
    vector<Person*> residents;

   public:
    void addResident(Person* person) { residents.push_back(person); }
    void displayResidents() {
        cout << "Граждане здесь живущие:" << endl;
        for (Person* person : residents) {
            cout << person->getName() << endl;
        }
    }
    ~Apartment() {
        for (Person* person : residents) {
            delete person;
        }
        cout << "Квартира сгорела." << endl;
    }
};

class House {
   private:
    vector<Apartment*> apartments;

   public:
    void addApartment(Apartment* apartment) { apartments.push_back(apartment); }
    void displayApartments() {
        cout << "В доме " << apartments.size() << " квартир(ы):" << endl;
        for (int i = 0; i < apartments.size(); i++) {
            cout << "Квартира " << i + 1 << ":" << endl;
            apartments[i]->displayResidents();
            cout << endl;
        }
    }
    ~House() {
        for (Apartment* apartment : apartments) {
            delete apartment;
        }
        cout << "В дом прилетела ракета." << endl;
    }
};

int main(int argc, char const* argv[]) {
    House* doctor = new House();
    Apartment* apartment1 = new Apartment();
    Apartment* apartment2 = new Apartment();
    Person* person1 = new Person("Иван");
    Person* person2 = new Person("Мария");
    Person* person3 = new Person("Петр");
    apartment1->addResident(person1);
    apartment1->addResident(person2);
    apartment2->addResident(person3);
    doctor->addApartment(apartment1);
    doctor->addApartment(apartment2);
    doctor->displayApartments();
    cout << "Всего граждан: " << Person::getTotal() << endl;
    delete doctor;
    return 0;
}
