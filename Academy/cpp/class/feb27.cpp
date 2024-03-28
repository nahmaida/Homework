#include <iostream>
#include <vector>
using namespace std;

void printRhombus(int height) {
    int spaces = height - 1;
    int i = 0;
    for (i; i < height - 1; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        spaces--;
        for (int k = 0; k < i + 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }

    for (i; i >= 0; i--) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        spaces++;
        for (int k = 0; k < i + 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void twoTriangles(int height) {
    int spaces = height - 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        spaces--;
        for (int k = 1; k < height; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int rangeSum(int end) {
    int sum = 0;
    for (int i = 1; i <= end; i++) {
        sum += i;
    }
    return sum;
}

void multTable() {
    for (int i = i; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int result = i * j;
            cout << i << " * " << j << " = " << result << endl;
        }
        cout << endl;
    }
}

unsigned int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return n;
    }
    return n * factorial(n - 1);
}

bool checkPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if ((num % i) == 0) {
            return false;
        }
    }
    return true;
}

unsigned int fibonacci(int n) {
    if (n < 3) {
        return n - 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void count(int n) {
    for (n; n > 0; n--) {
        cout << n << endl;
    }
}

int evenSum(int start, int end) {
    int sum = 0;
    int i = start;
    if ((start % 2) != 0) {
        sum = start - 1;
        i++;
    }
    for (i; i <= end; i += 2) {
        sum += i;
    }
    return sum;
}

void chessBoard() {
    int length, width;
    cout << "Введите длину\n>> ";
    cin >> length;
    cout << "Введите ширину\n>> ";
    cin >> width;
    for (length; length > 0; length--) {
        if ((length % 2) != 0) {
            cout << " ";
        }

        for (int i = 0; i < width; i++) {
            cout << " *";
        }

        cout << endl;
    }
}

void primeFactors(int n) {
    for (int i = 2; i <= n; i++) {
        if (!(checkPrime(i))) {
            continue;
        }
        while ((n % i) == 0) {
            cout << i << endl;
            n = n / i;
        }
    }
}

void printUneven(int n) {
    for (n; n > 0; --n) {
        if ((n % 2) != 0) {
            cout << n << endl;
            continue;
        }
    }
}

int findPrime(int start, int end) {
    if (end < start) {
        int temp;
        temp = start;
        start = end;
        end = temp;
    }
    for (start; start <= end; start++) {
        if (checkPrime(start)) {
            return start;
        }
    }
    return -1;
}

int positiveSum(int start, int end) {
    int sum = 0;

    if (start < 0) {
        start = 1;
    }

    if (end < 0) {
        end = 1;
    }

    if (end < start) {
        int temp;
        temp = start;
        start = end;
        end = temp;
    }

    for (start; start <= end; start++) {
        sum += start;
    }

    return sum;
}

void printFactors(int n) {
    for (int i = 1; i <= n; i++) {
        if ((n % i) == 0) {
            cout << i << endl;
        }
    }
}

void skipFiveSeven(int n) {
    for (int i = 1; i <= n; i++) {
        if ((i == 5) || (i == 7)) {
            continue;
        }
        cout << i << endl;
    }
}

void printNEvens(int n) {
    int numOfEvens = 0;
    for (int i = 2;; i++) {
        if (numOfEvens >= n) {
            break;
        }
        if ((i % 2) == 0) {
            cout << i << endl;
            numOfEvens++;
        }
    }
}

void skipThreeFiveFactors(int n) {
    for (n; n > 0; n--) {
        if ((n % 3 == 0) || (n % 5 == 0)) {
            continue;
        }
        cout << n << endl;
    }
}

void countPositives() {
    int numOfPositives = 0;
    for (int n = 1; n != 0;) {
        cout << "Введите число (0 - выход)\n>> ";
        cin >> n;
        if (n == 0) {
            break;
        }
        if (n > 0) {
            numOfPositives++;
        }
    }
    cout << numOfPositives;
}

void threeNegatives() {
    int numOfNegatives = 0;
    for (int n = 1;;) {
        cout << "Введите число (0 - выход)\n>> ";
        cin >> n;
        if (numOfNegatives >= 2) {
            break;
        }
        if (n < 0) {
            numOfNegatives++;
        }
    }
}

vector<int> bubbleSort(vector<int> unsorted) {
    bool sorted = false;
    for (;;) {
        for (int i = 0; i <= size(unsorted); i++) {
            // TODO
        }
    }
}

int main(int argc, char const *argv[]) {
    threeNegatives();
    return 0;
}
