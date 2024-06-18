#include <iostream>
#include <fstream>
using namespace std;

struct Adress {
    char city[256];
    char street[256];
    char house[256];
    char appartment[256];
};

Adress getAddress() {
    Adress a;
    cout << "Город:\n>> ";
    cin >> a.city;
    cout << "Улица:\n>> ";
    cin >> a.street;
    cout << "Номер дома:\n>> ";
    cin >> a.house;
    cout << "Квартира:\n>> ";
    cin >> a.appartment;
    return a;
}

void writeAdress(Adress a) {
    ofstream file("adress.txt");
    file << "Город: " << a.city << endl;
    file << "Улица: " << a.street << endl;
    file << "Номер дома: " << a.house << endl;
    file << "Квартира: " << a.appartment << endl;
    file.close();
}

int subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

int main(int argc, char const *argv[]) {
    cout << subtract(5, 3) << endl;
    Adress a = getAddress();
    writeAdress(a);
    return 0;
}
