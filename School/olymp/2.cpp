#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;
    long long count = 1;
    while (n > 0) { 
        if (count % 3) {   
            n--;
        }
        count += 2;
    }
    cout << count - 2 << endl;
    return 0;
}
