#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
    string name;
    string major;
    string university;
    int age;
    double gpa;

   public:
    Student(string name, string major, string university, int age, double gpa) {
        this->name = name;
        this->major = major;
        this->university = university;
        this->age = age;
        this->gpa = gpa;
    }

    string getName() const { return name; }
    string getMajor() const { return major; }
    string getUniversity() const { return university; }
    int getAge() const { return age; }
    double getGpa() const { return gpa; }
};

class Aspirant : public Student {
    string thesis;

   public:
    Aspirant(string name, string major, string university, int age, double gpa,
             string thesis)
        : Student(name, major, university, age, gpa) {
        this->thesis = thesis;
    }

    string getThesis() const { return thesis; }
};

ostream& operator<<(ostream& os, const Student& student) {
    os << "Имя: " << student.getName() << endl;
    os << "Факультет: " << student.getMajor() << endl;
    os << "Университет: " << student.getUniversity() << endl;
    os << "Возраст: " << student.getAge() << endl;
    os << "Средний бал: " << student.getGpa() << endl;
    return os;
}

ostream& operator<<(ostream& os, const Aspirant& aspirant) {
    os << (Student&)aspirant;
    os << "Тема диссертации: " << aspirant.getThesis() << endl;
    return os;
}

struct DOB {
    int day;
    int month;
    int year;
};

class Passport {
    string name;
    string surname;
    string patronymic;
    string series;
    string number;
    DOB dob;

   public:
    Passport(string name, string surname, string patronymic, string series,
             string number, DOB dob) {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->series = series;
        this->number = number;
        this->dob = dob;
    }

    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getPatronymic() const { return patronymic; }
    string getSeries() const { return series; }
    string getNumber() const { return number; }
    DOB getDob() const { return dob; }
};

class ForeignPassport : public Passport {
    vector<string> visas;

   public:
    ForeignPassport(string name, string surname, string patronymic,
                    string series, string number, DOB dob, vector<string> visas)
        : Passport(name, surname, patronymic, series, number, dob) {
        this->visas = visas;
    }

    vector<string> getVisas() const { return visas; }
};

ostream& operator<<(ostream& os, const Passport& passport) {
    os << "Имя: " << passport.getName() << endl;
    os << "Фамилия: " << passport.getSurname() << endl;
    os << "Отчество: " << passport.getPatronymic() << endl;
    os << "Серия: " << passport.getSeries() << endl;
    os << "Номер: " << passport.getNumber() << endl;
    os << "Дата рождения: " << passport.getDob().day << "."
       << passport.getDob().month << "." << passport.getDob().year << endl;
    return os;
}

ostream& operator<<(ostream& os, const ForeignPassport& passport) {
    os << (Passport&)passport;
    os << "Визы: " << endl;
    for (string visa : passport.getVisas()) {
        os << visa << endl;
    }
    return os;
}

int main(int argc, char const* argv[]) {
    Student student("ваня", "Информатика", "МГУ", 20, 3.5);
    Aspirant aspirant("женя", "Информатика", "СФУ", 20, 4.6,
                      "генератор абстрактного интерфейса бутербродов");
    cout << student << endl;
    cout << aspirant << endl;
    DOB dom = {1, 1, 1900};
    DOB dom2 = {2, 4, 1666};
    Passport passport("ваня", "ванин", "ваневич", "1234", "567890", dom);
    ForeignPassport foreignPassport("женя", "женев", "женевич", "6914",
                                    "884203", dom2,
                                    {"шенген", "узбекистан", "кирибати"});
    cout << passport << endl;
    cout << foreignPassport << endl;
    return 0;
}
