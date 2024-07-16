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

int getBiggestPrimeFactor(long n) {
    if (isPrime(n)) {
        return n;
    }
    int biggestPrimeFactor = 1;
    while (n % 2 == 0) {
        n /= 2;
        biggestPrimeFactor = 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            biggestPrimeFactor = i;
        }
    }
    if (n > 2) {
        biggestPrimeFactor = n;
    }
    return biggestPrimeFactor;
}

// what the actual fuck
// how can python be so slow

int main(int argc, char const *argv[]) {
    long num = 600851475143;
    cout << getBiggestPrimeFactor(num) << endl;
    return 0;
}
