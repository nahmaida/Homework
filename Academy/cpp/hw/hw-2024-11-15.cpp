#include <iostream>
#include <string>
using namespace std;

// Базовый класс Person
class Person {
   protected:
    string name;
    int age;

   public:
    Person(const string& name, int age) : name(name), age(age) {}

    string getInfo() const {
        return "Имя: " + name + ", Возраст: " + to_string(age);
    }
};

// Базовый класс Employee
class Employee {
   protected:
    int employeeID;
    string department;

   public:
    Employee(int employeeID, const string& department)
        : employeeID(employeeID), department(department) {}

    string getEmployee() const {
        return "ID: " + to_string(employeeID) + ", Отдел: " + department;
    }
};

// Производный класс Manager от Person и Employee
class Manager : public Person, public Employee {
   private:
    string level;

   public:
    Manager(const string& name, int age, int employeeID,
            const string& department, const string& level)
        : Person(name, age), Employee(employeeID, department), level(level) {}

    string managerInfo() const {
        return getInfo() + ", " + getEmployee() + ", Уровень: " + level;
    }
};

// Базовый класс A
class A {
   public:
    virtual void method1() const { cout << "это класс A" << endl; }
};

// Производный класс B от A
class B : public A {
   public:
    void method1() const override { cout << "это класс B" << endl; }
};

int main() {
    Manager manager("ваня ваня", 35, 12345, "IT", "сеньор");
    cout << manager.managerInfo() << endl;

    A a;
    a.method1();
    B b;
    b.method1();

    return 0;
}