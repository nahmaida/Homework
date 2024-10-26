#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;
    long long temp = (n / 2) + (bool) (n % 2);
    cout << temp*temp << endl;
    return 0;
}
