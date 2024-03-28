#include <cmath>
#include <iostream>
using namespace std;

int raiseTo(int number, int power) {
    int product = number;
    for (int i = 0; i < power; i++) {
        product *= number;
    }
    return product;
}

void reversePrintArray(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

bool detectLetter(const char* symbol) { return !(isdigit(*symbol)); }

int someWeirdoFunction(int a, int c, int m) {
    if (m >= 0 && m <= 9) {
        return m;
    } else {
        int power = pow(a, (m + c));
        int remainder = (power % 10);
        return (remainder * someWeirdoFunction(a, c, m - 1 - remainder) + m);
    }
}

unsigned factorial(int n) {
    if (n <= 1) {
        return n;
    } else {
        return n * factorial(n-1);
    }
}

int main(int argc, char const* argv[]) {
    cout << factorial(5);
    return 0;
}