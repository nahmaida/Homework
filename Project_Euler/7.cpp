#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long getNthPrime(int n) {
    int count = 0;
    int num = 1;
    while (count < n) {
        if (isPrime(num)) count++;
        num++;
    }
    return num - 1;
}

int main(int argc, char const *argv[]) {
    cout << getNthPrime(10001);
    return 0;
}
