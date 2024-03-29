#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printVector(vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

vector<int> fillVector(int size, int bound) {
    vector<int> vector = {};
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        vector.push_back(rand() % bound);
    }
    return vector;
}

void printEvens(vector<int> vector) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] % 2 == 0) {
            cout << vector[i] << " ";
        }
    }
}

vector<int> middleInsert(vector<int> vector, int element) {
    int middle = vector.size() / 2;
    vector.insert(vector.begin() + middle, element);
    return vector;
}

int countNum(vector<int> vector, int num) {
    int count = 0;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == num) {
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Нахождение четных чисел\n2. Вставка элементов в середину "
            "вектора\n3. Подсчет вхождений элемента\n>> ";
    cin >> mode;
    vector<int> vector = fillVector(10, 10);
    printVector(vector);
    switch (mode) {
        case 1:
            printEvens(vector);
            break;
        case 2:
            char *choice;
            int num;
            while (*choice != 'q') {
                cout << "Число: ";
                cin >> num;
                vector = middleInsert(vector, num);
                printVector(vector);
                cout << "Продолжить? (q - выход): ";
                cin >> choice;
            }
            break;
        case 3:
            int flag;
            cout << "Число: ";
            cin >> flag;
            cout << countNum(vector, flag);
            break;
        default:
            break;
    }
    return 0;
}
