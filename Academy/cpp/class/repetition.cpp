#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Book {
    char* author;
    char* title;
    char* genre;
    unsigned int year;
};

class Library {
   public:
    vector<Book> Books;
    unsigned int size;

    void printBook(Book book) {
        cout << "Автор:  " << book.author << endl;
        cout << "Название: " << book.title << endl;
        cout << "Жанр: " << book.genre << endl;
        cout << "Год выпуска: " << book.year << endl;
    }

    void addBook(Book book) {
        Books.push_back(book);
        size++;
    }

    void findBook(char* title, char* author) {
        for (int i = 0; i < size; i++) {
            if (Books[i].title == title && Books[i].author == author) {
                printBook(Books[i]);
            }
        }
        cout << "Не найдено!" << endl;
    }

    void removeBook(char* title, char* author) {
        for (int i = 0; i < size; i++) {
            if (Books[i].title == title && Books[i].author == author) {
                Books.erase(Books.begin() + i);
                size--;
            }
        }
    }
};

struct Point {
    int x;
    int y;
};

template <typename T>
T maxOfThree(T x, T y, T z) {
    if (x > y && x > z) {
        return x;
    } else if (y > z) {
        return y;
    } else {
        return z;
    }
}

int arraySum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void multiplyByTwo(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

double distance(Point a, Point b) {
    double sum = pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
    return sqrt(sum);
}


int main(int argc, char const* argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    int mode;
    cout << "1. Шаблоны\n2. Указатели\n3. Дин. массивы\n4. Структуры\n5. Ст. и "
            "функции\n6. Указ. на фунцкии\n7. Дин. массивы 2\nСтруктуры 2\n>> ";
    cin >> mode;
    switch (mode) {
        case 1:
            int x, y, z;
            cout << "Введите три числа: ";
            cin >> x >> y >> z;
            cout << "Максимальное:" << maxOfThree(x, y, z) << endl;
            break;
        case 2:
            cout << "Сумма элементов массива: " << arraySum(arr, 5) << endl;
            break;
        case 3:
            multiplyByTwo(arr, 5);
            for (int i = 0; i < 5; i++) {
                cout << arr[i] << " ";
            }
            break;
        case 4:
            Point a, b;
            cout << "Введите точку a (x,y): ";
            cin >> a.x >> a.y;
            cout << "Введите точку b (x,y): ";
            cin >> b.x >> b.y;
            cout << "Расстояние: " << distance(a, b) << endl;
            break;
    }

    return 0;
}
