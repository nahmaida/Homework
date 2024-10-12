#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    vector<int> grades;
    int age;
}; // никаких методов там нет так что можно и не делать классом 

class Group {
    string name;
    vector<Student> students;

   public:
    Group(string name) : name(name) {}

    void addStudent() {
        Student newStudent;
        cout << "Введите имя студента\n>> ";
        cin >> newStudent.name;
        cout << "Введите возраст\n>> ";
        cin >> newStudent.age;
        students.push_back(newStudent);
        cout << "Успешно.\n";
    }

    void addGrade() {
        Student& student = selectStudent();
        int grade;
        cout << "Введите оценку\n>> ";
        cin >> grade;
        student.grades.push_back(grade);
    }

    void printGrades() {
        Student& student = selectStudent();
        // печатает все оценки кроме последней с запятой
        for (int i = 0; i < student.grades.size() - 1; i++) {
            cout << student.grades[i] << ", ";
        }
        cout << student.grades[student.grades.size() - 1] << endl;
    }

   private:
    void printStudents() {
        for (int i = 0; i < students.size(); i++) {
            cout << i << ": " << students[i].name << endl;
        }
    }

    Student& selectStudent() {
        printStudents();
        int index;
        cout << "Введите номер студента\n>> ";
        cin >> index;
        return students[index];
    }
};

int main(int argc, char const* argv[]) {
    Group group("13ы");
    while (1) {
        cout << "1. Добавить студента\n2. Добавить оценку\n3. Вывести "
                "оценки\n4. Выход\n>> ";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                group.addStudent();
                break;
            case 2:
                group.addGrade();
                break;
            case 3:
                group.printGrades();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
