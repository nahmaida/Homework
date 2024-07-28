#include <iostream>
#include "InfInt.h"

InfInt fibo(InfInt n) {
    if (n < 2) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(int argc, char const *argv[]) {
    InfInt i = 1;
    while (fibo(i).toString().length() < 1000) {
        i++;
    }
    // probably takes like a day to compute
    std::cout << i << std::endl;
    return 0;
}
