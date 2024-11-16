#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
double circleArea(T radius) {
    return M_PI * radius * radius;
}

template <typename T>
T rectangleArea(T a, T b) {
    return a * b;
}

template <typename T, typename K>
double altRectangleArea(T a, K b) {
    return a * b;
}

template <typename T, typename K>
class Pair {
    T one;
    K two;

   public:
    Pair(T one, K two) : one(one), two(two) {}

    T first() const { return one; }
    K second() const { return two; }

    void setFirst(T one) { this->one = one; }
    void setSecond(K two) { this->two = two; }

    Pair<K, T> swap() {
        return Pair<K, T>(this->two, this->one);
    }
};

template <typename T, typename K>
ostream& operator<<(ostream& os, Pair<T, K> p) {
    os << "(" << p.first() << ", " << p.second() << ")";
    return os;
}

int main(int argc, char const* argv[]) {
    // vector<int> radius = {1, 2, 3, 4, 5};
    // for (int i = 0; i < radius.size(); i++) {
    //     cout << "Площадь круга с радиусом " << radius[i] << " - "
    //          << circleArea(radius[i]) << endl;
    // }
    // vector<float> radius2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    // for (int i = 0; i < radius2.size(); i++) {
    //     cout << "Площадь круга с радиусом " << radius2[i] << " - "
    //          << circleArea(radius2[i]) << endl;
    // }
    // vector<double> radius3 = {1.221, 2.3212, 3.6583, 464.524, 69.1488};
    // for (int i = 0; i < radius3.size(); i++) {
    //     cout << "Площадь круга с радиусом " << radius3[i] << " - "
    //          << circleArea(radius3[i]) << endl;
    // }
    // cout << "Площадь круга с радиусом 'a' - " << circleArea('a') << endl;

    // cout << "Площадь прямоугольника с сторонами 2 и 3 - " << rectangleArea(2,
    // 3)
    //      << endl;

    // cout << "Площадь прямоугольника с сторонами 2.2 и 'a' - "
    //      << altRectangleArea(2.2, 'a') << endl;

    Pair<int, double> p(1, 2.2);
    cout << p << endl;
    Pair <double, int> p2 = p.swap();
    cout << p2 << endl;

    cout << p.first() << " " << p.second() << endl;
    p.setFirst(3);
    p.setSecond(4.4);
    cout << p << endl;

    vector<int> v = {1, 2, 3, 4, 5};
    vector<float> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < v.size(); i++) {
        cout << Pair<int, float>(v[i], v2[i]) << endl;
    }
    return 0;
}
