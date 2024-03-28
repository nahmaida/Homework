#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createMatrix(int height, int width) {
    return vector<vector<int>>(height, vector<int>(width, 0));
}

void identityMatrix(int size) {
    int matrix[size][size];
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            matrix[i][j] = 0;
            matrix[i][i] = 1;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> fillMatrix(int size) {
    vector<vector<int>> matrix = createMatrix(size, size);
    srand(time(NULL));
    int upperBound = 100;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % upperBound + 1;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

int matrixSum(vector<vector<int>> matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int returnMax(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = fillMatrix(5);
    cout << matrixSum(matrix, 5);
    return 0;
}
