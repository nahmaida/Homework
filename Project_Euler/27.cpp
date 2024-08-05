#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> findMax();
int countPrimes(int a, int b);
bool isPrime(int n);

int main(int argc, char const* argv[]) {
    vector<int> values = findMax();
    cout << "a: " << values[0] << "\nb: " << values[1]
         << "\nN: " << values[2] << endl;
    return 0;
}

vector<int> findMax() {
    vector<int> max = {0, 0, 0};
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int nPrimes = countPrimes(a, b);
            if (nPrimes > max[2]) {
                max[2] = nPrimes;
                max[0] = a;
                max[1] = b;
            }
        }
    }
    return max;
}

int countPrimes(int a, int b) {
    int n = 0;
    while (isPrime(pow(n, 2) + (a * n) + b)) {
        n++;
    }
    return n;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}