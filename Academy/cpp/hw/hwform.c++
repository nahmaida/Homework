#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double resistanceFinder(vector<double> resistances) {
    double sum = 0;
    for (double value : resistances) {
        sum += pow(value, -1);
    }
    return pow(sum, -1);
}

double circleArea(double circumference) {
    const double pi = 3.141;
    double area;
    area = pow(circumference, 2) / (pi * 4);
    return area;
}

double movement(double v, double t, double a) {
    double S;
    S = v * t + (a * pow(t, 2)) / 2;
    return S;
}

int main(int argc, char const *argv[]) {
    int mode;
    cout << "1. Сопротивление\n2. Площадь круга\n3. Расстояние\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            cout << resistanceFinder({2, 15, 22});
            break;
        case 2:
            cout << circleArea(15);
            break;
        case 3:
            cout << movement(13, 2, 14);
        default:
            break;
    }
    return 0;
}
