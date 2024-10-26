#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Создайте приложение "Телефонная книга". Необходимо
// хранить данные об абоненте (ФИО, домашний телефон,
// рабочий телефон, мобильный телефон, дополнительная
// информация о контакте) внутри соответствующего класса. Наполните класс
// переменными-членами, функциями-членами, конструкторами. реализуйте
// деструктор. string ФИО. Предоставьте пользователю возможность добавлять новых
// абонентов, удалять абонентов, искать абонентов по ФИО, показывать всех
// абонентов,

// class Abonent
// class phoneBook
// ~Abonent(){
// }

class Abonent {
   private:
    string fullName = "Нет";
    string homePhone = "Нет";
    string workPhone = "Нет";
    string mobilePhone = "Нет";
    string additionalInfo = "Скуф";

   public:
    Abonent(string fullName, string homePhone, string workPhone,
            string mobilePhone, string additionalInfo) {
        this->fullName = fullName;
        this->homePhone = homePhone;
        this->workPhone = workPhone;
        this->mobilePhone = mobilePhone;
        this->additionalInfo = additionalInfo;
    }

    string getFullName() { return fullName; }
    string getHomePhone() { return homePhone; }
    string getWorkPhone() { return workPhone; }
    string getMobilePhone() { return mobilePhone; }
    string getAdditionalInfo() { return additionalInfo; }

    void setFullName(string fullName) {
        // Проверяет что имя не содержит цифр
        if (fullName.length() > 0 &&
            string::npos == fullName.find_first_of("0123456789")) {
            this->fullName = fullName;
        } else {
            cout << "имя некрасивое." << endl;
        }
    }
    void setHomePhone(string homePhone) { this->homePhone = homePhone; }
    void setWorkPhone(string workPhone) { this->workPhone = workPhone; }
    void setMobilePhone(string mobilePhone) { this->mobilePhone = mobilePhone; }
    void setAdditionalInfo(string additionalInfo) {
        this->additionalInfo = additionalInfo;
    }
};

class Phonebook {
   private:
    vector<Abonent> abonents;

    void sort() {
        // сортирует книжку пузырьком по первой букве потому что могу
        int n = abonents.size();

        for (int i = 0; i < n - 1; i++) {
            bool flag = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (abonents[j].getFullName()[0] >
                    abonents[j + 1].getFullName()[0]) {
                    swap(abonents[j], abonents[j + 1]);
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }

    void addAbonent(Abonent abonent) {
        abonents.push_back(abonent);
        sort();
    }

    bool AbonentExist(string fullName) {
        for (int i = 0; i < abonents.size(); i++) {
            if (abonents[i].getFullName() == fullName) {
                return true;
            }
        }
        return false;
    }

   public:
    void print() {
        // выводит имя абонентов
        for (int i = 0; i < abonents.size(); i++) {
            cout << i + 1 << ". Имя: " << abonents[i].getFullName() << endl;
        }
    }

    void printAbonent() {
        string fullname;
        cout << "Введите ФИО\n>> ";
        cin >> fullname;
        for (int i = 0; i < abonents.size(); i++) {
            if (abonents[i].getFullName() == fullname) {
                Abonent abonent = abonents[i];
                cout << "Имя: " << abonent.getFullName() << endl;
                cout << "Домашний телефон: " << abonent.getHomePhone() << endl;
                cout << "Рабочий телефон: " << abonent.getWorkPhone() << endl;
                cout << "Мобильный телефон: " << abonent.getMobilePhone()
                     << endl;
                cout << "Дополнительная информация: "
                     << abonent.getAdditionalInfo() << endl;
                return;
            }
        }
        cout << "Не нашли такого.";
    }

    void createAbonent() {
        string fullName;
        string homePhone;
        string workPhone;
        string mobilePhone;
        string additionalInfo;

        cout << "Введите ФИО\n>> ";
        cin >> fullName;
        cout << "Введите домашний телефон\n>> ";
        cin >> homePhone;
        cout << "Введите рабочий телефон\n>> ";
        cin >> workPhone;
        cout << "Введите мобильный телефон\n>> ";
        cin >> mobilePhone;
        cout << "Введите дополнительную информацию\n>> ";
        cin >> additionalInfo;

        Abonent abonent(fullName, homePhone, workPhone, mobilePhone,
                        additionalInfo);
        addAbonent(abonent);
    }

    void deleteAbonent() {
        string fullname;
        cout << "Введите имя цели\n>> ";
        cin >> fullname;
        for (int i = 0; i < abonents.size(); i++) {
            if (abonents[i].getFullName() == fullname) {
                abonents.erase(abonents.begin() + i);
                cout << "Абонент был уничтожен.";
                return;
            }
        }
        cout << "Нет такого абонента.";
    }

    ~Phonebook() {
        cout << "Все абоненты были убиты. Книга была сожжена. Свидетелей не "
                "осталось."
             << endl;
    }
};

int main(int argc, char const *argv[]) {
    Phonebook phonebook;
    while (1) {
        cout << "\n1. Создать абонента\n2. Показать абонентов\n3. Поиск "
                "абонента\n4. Удалить абонента\n5. Выход\n>> ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                phonebook.createAbonent();
                break;
            case 2:
                phonebook.print();
                break;
            case 3:
                phonebook.printAbonent();
                break;
            case 4:
                phonebook.deleteAbonent();
                break;
            case 5:
                return 0;
            default:
                cout << "Неверный выбор." << endl;
                break;
        }
    }
    return 0;
}
