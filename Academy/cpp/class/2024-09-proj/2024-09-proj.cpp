#include <sqlite3.h>

#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Question {
    string text;
    vector<string> options;
    int answer;
};

class Interface {
   private:
    sqlite3* DB;
    string session;

    vector<string> encrypt(string password) {
        // Использует текущее время в качестве соли
        string now = to_string(time(0));

        // Добавляет соль и хеширует пароль
        string hashed = now + password;
        hashed = to_string(std::hash<string>{}(hashed));

        // Возвращает соль и хеш
        vector<string> encrypted = {now, hashed};
        return encrypted;
    }

   public:
    Interface(sqlite3* DB) {
        // Пытается открыть базу данных, иначе выдает ошибку
        int exit = 0;
        exit = sqlite3_open("tests.db", &DB);
        if (exit) {
            std::cerr << "Ошибка в базе данных" << sqlite3_errmsg(DB) << std::endl;
        } else {
            this->DB = DB;
        }
    }

    void signUp() {
        string username, salt, password;
        cout << "Введите имя пользователя: ";
        cin >> username;
        cout << "Введите пароль: ";
        cin >> password;

        // Шифрует пароль и возвращает соль и хеш
        vector<string> encrypted = encrypt(password);
        salt = encrypted[0];
        password = encrypted[1];

        // Проверяет, есть ли пользователь с таким именем в базе данных
        string query =
            "SELECT * FROM users WHERE username = '" + username + "';";

        // Если пользователь существует, то выдает ошибку
        int exit = sqlite3_exec(DB, query.c_str(), NULL, 0, NULL);
        if (exit == SQLITE_OK) {
            cout << "Пользователь с таким именем уже существует!" << endl;
        }

        // Иначе, добавляет пользователя в базу данных
        query =
            "INSERT INTO users (username, is_admin, salt, password) VALUES ('" +
            username + "', 0,'" + password + "','" + salt + "');";
        exit = sqlite3_exec(DB, query.c_str(), NULL, 0, NULL);
        if (exit != SQLITE_OK) {
            cerr << "Ошибка в базе данных" << sqlite3_errmsg(DB) << std::endl;
        } else {
            cout << "Пользователь зарегистрирован" << endl;
        }
    }
};

int main(int argc, char const* argv[]) {
    sqlite3* DB;
    Interface* interface = new Interface(DB);
    interface->signUp();
    return 0;
}
