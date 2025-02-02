#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
   private:
    string name;
    string species;
    int age;

   public:
    Animal(const string& name, const string& species, int age)
        : name(name), species(species), age(age) {}

    void makeSound() const { cout << name << " что-то сказало" << endl; }

    string getName() const { return name; }
    string getSpecies() const { return species; }
    int getAge() const { return age; }
};

class Enclosure {
   private:
    int id;
    vector<Animal*> animals;

   public:
    Enclosure(int id) : id(id) {}

    void addAnimal(Animal* animal) { animals.push_back(animal); }

    void displayAnimals() const {
        cout << "В вольере " << id << ":" << endl;
        for (const auto& animal : animals) {
            cout << "- " << animal->getName() << " (" << animal->getSpecies()
                 << ", " << animal->getAge() << " лет)" << endl;
        }
    }
};

class Zookeeper {
   private:
    string name;
    Enclosure* assignedEnclosure;

   public:
    Zookeeper(const string& name) : name(name), assignedEnclosure(nullptr) {}

    void assignEnclosure(Enclosure* enclosure) {
        assignedEnclosure = enclosure;
    }

    void feedAnimals() const {
        if (assignedEnclosure) {
            cout << name << " кормит животных: " << endl;
            assignedEnclosure->displayAnimals();
        } else {
            cout << name << " нигде не работает." << endl;
        }
    }
};

class Zoo {
   private:
    string name;
    vector<Enclosure*> enclosures;
    vector<Zookeeper*> zookeepers;

   public:
    Zoo(const string& name) : name(name) {}

    void addEnclosure(Enclosure* enclosure) { enclosures.push_back(enclosure); }

    void addZookeeper(Zookeeper* zookeeper) { zookeepers.push_back(zookeeper); }

    void displayZooInfo() const {
        cout << "Добро пожаовать в зоопарк " << name << "!" << endl;
        cout << "Вольеры:" << endl;
        for (const auto& enclosure : enclosures) {
            enclosure->displayAnimals();
        }
        cout << "Сотрудники:" << endl;
        for (const auto& zookeeper : zookeepers) {
            zookeeper->feedAnimals();
        }
    }
};

int main(int argc, char const* argv[]) {
    Zoo zoo("Роева Река");

    Enclosure enclosure1(1);
    Enclosure enclosure2(2);

    Animal lion("Симба", "Лев", 5);
    Animal tiger("Сигма", "Волк", 4);
    Animal giraffe("JIRA", "Жираф", 7);

    enclosure1.addAnimal(&lion);
    enclosure1.addAnimal(&tiger);
    enclosure2.addAnimal(&giraffe);

    Zookeeper zookeeper1("Ваня");
    Zookeeper zookeeper2("Аня");

    zookeeper1.assignEnclosure(&enclosure1);
    zookeeper2.assignEnclosure(&enclosure2);

    zoo.addEnclosure(&enclosure1);
    zoo.addEnclosure(&enclosure2);
    zoo.addZookeeper(&zookeeper1);
    zoo.addZookeeper(&zookeeper2);

    zoo.displayZooInfo();

    return 0;
}