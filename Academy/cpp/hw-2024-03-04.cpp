#include <iostream>
using namespace std;

void printTenEvens () {

    for (int i = 1; i < 11; i++) {
        cout << i * 2 << " ";
    }
}

int main(int argc, char const *argv[]) {
    printTenEvens();
    return 0;
}
