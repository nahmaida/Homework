#include <iostream>
using namespace std;

long longestCollatz() {
    int maxSteps = 1;
    long maxNum = 1;
    for (int i = 2; i < 1000000; i++) {
        int num = i;
        int steps = 0;
        while (i != 1) {
            steps++;
            if (i % 2) {
                i = 3*i + 1;
            } else {
                i /= 2;
            }
        }
        if (steps > maxSteps) {
            maxSteps = steps;
            maxNum = num;
        }
    }
    return maxNum;
}

int main(int argc, char const *argv[]) {
    cout << longestCollatz() << endl;
    return 0;
}
