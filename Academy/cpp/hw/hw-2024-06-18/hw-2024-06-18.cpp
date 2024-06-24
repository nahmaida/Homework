#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name;
    string price;
};

struct Account {
    string username;
    string password;
    string salt;
};

class Shop {
   public:
    vector<Item> items;
    vector<Account> accounts;
    const string itemsFilename, accountsFilename;
    string session;
    Shop(string itemsFilename, string accountsFilename)
        : itemsFilename(itemsFilename), accountsFilename(accountsFilename) {
        items = handleItems(itemsFilename);
        accounts = handleAccounts(accountsFilename);
        session = "";
    }

    void signUp(Shop shop, string username, string password) {
        time_t currentTime = time(nullptr);
        string salt = to_string(currentTime);

        string combined = password + salt;
        string hashed = to_string(hash<string>{}(combined));

        fstream outFile(shop.accountsFilename, ios::app);
        outFile << username << " " << hashed << " " << salt << endl;
        handleAccounts(Shop::accountsFilename);
    }

    string login(Shop shop) {
        string username, password;
        cout << "Логин:\n>> ";
        cin >> username;
        cout << "Пароль:\n>> ";
        cin >> password;

        for (Account account : accounts) {
            if (account.username == username) {
                if (verifyPassword(account, password)) {
                    cout << "Успешно!" << endl;
                    return username;
                } else {
                    cout << "Неверный пароль!" << endl;
                    return "";
                }
            }
        }
        cout << "Aккаунт не найден\nЗарегестрировать? (1/0)\n>> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            signUp(shop, username, password);
            cout << "Успешно!" << endl;
            return username;
        }
        return "";
    }

   private:
    vector<Item> handleItems(string filename) {
        fstream inFile(filename);
        vector<Item> items;
        string name, price;

        while (inFile >> name >> price) {
            Item item;
            item.name = name;
            item.price = price;
            items.push_back(item);
        }
        inFile.close();
        return items;
    }

    vector<Account> handleAccounts(string filename) {
        fstream inFile(filename);
        vector<Account> accounts;
        string username, password, salt;

        while (inFile >> username >> password >> salt) {
            Account account;
            account.username = username;
            account.password = password;
            account.salt = salt;
            accounts.push_back(account);
        }
        inFile.close();
        return accounts;
    }

    bool verifyPassword(Account account, string password) {
        string combined = password + account.salt;
        string hashed = to_string(hash<string>{}(combined));
        return hashed == account.password;
    }
};

int main(int argc, char const *argv[]) {
    const string itemsFilename = "items.txt";
    const string accountsFilename = "accounts.txt";
    Shop shop(itemsFilename, accountsFilename);
    while (shop.session == "") {
        shop.session = shop.login(shop);
    }
    return 0;
}
