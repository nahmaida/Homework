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

long primeSum(int n) {
    long sum = 2;
    for (int i = 3; i < n; i += 2) {
        if (isPrime(i)) sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    cout << primeSum(2000000) << endl;
    return 0;
}
