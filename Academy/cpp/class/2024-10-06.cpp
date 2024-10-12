#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int age = 0;
    int height = 0;

   public:
    Student(string name) : name{name} {}

    Student(string name, int age) : Student(name) { this->age = age; }

    Student(string name, int age, int height) : Student(name, age) {
        this->height = height;
    }

    void print() {
        cout << "имя: " << name << endl;
        cout << "воз: " << age << endl;
        cout << "выс: " << height << endl;
    }
};

int main(int argc, char const *argv[]) {
    Student s1("Иван");
    s1.print();
    Student s2("Петр", 18);
    s2.print();
    Student s3("Анна", 17, 160);
    s3.print();
    return 0;
}
