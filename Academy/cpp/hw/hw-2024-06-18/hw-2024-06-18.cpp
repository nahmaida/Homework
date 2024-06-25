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

struct Order {
    string username;
    vector<Item> items;
    int totalPrice;
};

class Shop {
   public:
    vector<Item> items;
    vector<Account> accounts;
    vector<Order> orders;
    const string itemsFilename, accountsFilename;
    string session;
    Shop(string itemsFilename, string accountsFilename)
        : itemsFilename(itemsFilename), accountsFilename(accountsFilename) {
        items = handleItems(itemsFilename);
        accounts = handleAccounts(accountsFilename);
        session = "";
    }

    void signUp(string username, string password) {
        time_t currentTime = time(nullptr);
        string salt = to_string(currentTime);

        string combined = password + salt;
        string hashed = to_string(hash<string>{}(combined));

        fstream outFile(accountsFilename, ios::app);
        outFile << username << " " << hashed << " " << salt << endl;
        accounts = handleAccounts(Shop::accountsFilename);
    }

    string login() {
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
            signUp(username, password);
            cout << "Успешно!" << endl;
            return username;
        }
        return "";
    }

    void printItems() {
        int i = 0;
        for (Item item : items) {
            cout << ++i << ". " << item.name << " - " << item.price << endl;
        }
        cout << endl;
    }

    void printOrders() {
        for (Order order : orders) {
            cout << "Логин: " << order.username << endl;
            cout << "Товары:" << endl;
            for (Item item : order.items) {
                cout << "- " << item.name << " (" << item.price << ")" << endl;
            }
            cout << "Сумма: " << order.totalPrice << endl;
            cout << endl;
        }
    }

    void addItem(string name, string price) {
        fstream outFile(itemsFilename, ios::app);
        outFile << name << " " << price << endl;
        items = handleItems(Shop::itemsFilename);
    }

    void makeOrder() {
        vector<Item> orderItems;
        int totalPrice = 0;
        int choice;

        while (true) {
            printItems();
            cout << "Выберите номер товара (0 - подтвердить)\n>> ";
            cin >> choice;
            if (choice == 0) {
                break;
            }
            if (choice < 0 || choice >= items.size()) {
                cout << "Неверный выбор!" << endl;
                continue;
            }
            orderItems.push_back(items[choice - 1]);
            totalPrice += stoi(items[choice - 1].price);
        }

        Order order;
        order.username = session;
        order.items = items;
        order.totalPrice = totalPrice;
        orders.push_back(order);
        cout << "Успешно!" << endl;
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
    string name, price;
    Shop shop(itemsFilename, accountsFilename);
    while (shop.session == "") {
        shop.session = shop.login();
    }
    int choice;
    while (true) {
        cout << "1. Сделать заказ\n2. Показать заказы\n"
                "3. Показать товары\n4. Добавить товар\n5. Выход\n>> ";
        cin >> choice;
        switch (choice) {
            case 1:
                shop.makeOrder();
                break;
            case 2:
                shop.printOrders();
                break;
            case 3:
                shop.printItems();
                break;
            case 4:
                cout << "Название:\n>> ";
                cin >> name;
                cout << "Цена:\n>> ";
                cin >> price;
                shop.addItem(name, price);
                cout << "Успешно!" << endl;
                break;
            case 5:
                return 0;
            default:
                continue;
        }
    }
    return 0;
}
