#include <iostream>
using namespace std;

int divTriNum(int n) {
    int num = 0;
    int natNum = 1;
    for (;;) {
        num += natNum;
        natNum++;
        int nDivs = 2;
        for (int i = 2; i < num; i++) {
            if (not (num % i)) nDivs++;
            if (nDivs > n) {
                return num;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    int num = 500;
    cout << divTriNum(num);
    return 0;
}
