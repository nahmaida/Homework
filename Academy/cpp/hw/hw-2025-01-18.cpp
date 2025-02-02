#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

// Предикат для проверки условий
bool isDivisibleBy2And5AndGreaterThan232(int number) {
    return (number % 2 == 0) && (number > 232) && (number % 5 == 0);
}

int main() {
    srand(time(0));

    vector<int> arr(100);
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rand() % 10000 + 1;
    }

    auto it =
        find_if(arr.begin(), arr.end(), isDivisibleBy2And5AndGreaterThan232);

    if (it != arr.end()) {
        cout << "Первое число, удовлетворяющее условиям: " << *it << endl;
    } else {
        cout << "Число не найдено." << endl;
    }

    sort(arr.begin(), arr.end());
    cout << "Отсортированный массив:\n";
    for (int num : arr) {
        cout << num << endl;
    }
    cout << endl;

    return 0;
}