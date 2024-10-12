#include <iostream>
#include <string>
using namespace std;

void length() {
    string str;
    cout << "Введите строку:\n>> ";
    cin >> str;
    int counter = 0;
    while (str[counter] != '\0') {
        counter++;
    }
    cout << "Длина строки: " << counter << endl;
}

int main(int argc, char const *argv[]) {
    length();
    return 0;
}
