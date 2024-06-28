#include <iostream>
using namespace std;

long longestCollatz() {
    int maxSteps = 1;
    long maxNum = 1;
    for (int i = 2; i < 100; i++) {
        int num = i;
        int steps = 0;
        while (num != 1) {
            steps++;
            if (num % 2) {
                num = 3*num + 1;
            } else {
                num /= 2;
            }
        }
        if (steps > maxSteps) {
            maxSteps = steps;
            maxNum = i;
        }
    }
    return maxNum;
}

int main(int argc, char const *argv[]) {
    cout << longestCollatz() << endl;
    return 0;
}
