#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int count = 0;

    while (n > 0) {
        count++;
        int copy = n;
        while (!(copy % 10)) {
            copy /= 10;
        }
        n -= copy % 10;
    }
    cout << count << endl;
    return 0;
}
