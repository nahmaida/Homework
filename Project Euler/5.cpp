#include <iostream>
using namespace std;

int smallestMultiple() {
    bool count = 0;
    for (int i = 1;; i++) {
        if (count) {
            return i-1;
        }
        for (int j = 2; j <= 20; j++) {
            count = 1;
            if (i % j) {
                count = 0;
                break;
            }
        } 
    }
    
}

int main(int argc, char const *argv[]) {
    cout << smallestMultiple() << endl;
    return 0;
}
