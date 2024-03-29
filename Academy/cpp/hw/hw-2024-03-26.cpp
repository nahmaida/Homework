#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createMatrix(int height, int width) {
    return vector<vector<int>>(height, vector<int>(width, 0));
}

vector<vector<int>> fillMatrix(vector<vector<int>> matrix, int bound) {
    int height = matrix.size();
    int width = matrix[0].size();
    srand(time(NULL));
    int upperBound = bound;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = rand() % upperBound;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

int countZeros(vector<vector<int>> matrix) {
    // в задании 3x4, здесь на любой размер
    int height = matrix.size();
    int width = matrix[0].size();
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

int findMaxInArea(vector<vector<int>> matrix) {
    // б
    int size = matrix.size();
    int max = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Количество нулей\n2. Максимальное значение\n>> ";
    cin >> mode;
    vector<vector<int>> matrix = fillMatrix(createMatrix(4, 4), 10);
    switch (mode) {
        case 1:
            cout << countZeros(matrix);
            break;
        case 2:
            cout << findMaxInArea(matrix);
        default:
            break;
    }
    return 0;
}
