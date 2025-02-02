#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Абстрактный базовый класс Employer
class Employer {
   public:
    virtual void Print() const = 0;
    virtual ~Employer() = default;
};

// Производный класс President
class President : public Employer {
   public:
    void Print() const override {
        cout << "президент: александр лукашенко." << endl;
    }
};

// Производный класс Manager
class Manager : public Employer {
   public:
    void Print() const override {
        cout << "менеджер: проверяет выполнение задач и принимает жалобы "
                "от бабушек."
             << endl;
    }
};

// Производный класс Worker
class Worker : public Employer {
   public:
    void Print() const override { cout << "рабочий: работает." << endl; }
};

// Абстрактный базовый класс Shape
class Shape {
   public:
    virtual double Area() const = 0;
    virtual ~Shape() = default;
};

// Производный класс Rectangle
class Rectangle : public Shape {
   private:
    double width, height;

   public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double Area() const override { return width * height; }
};

// Производный класс Circle
class Circle : public Shape {
   private:
    double radius;

   public:
    Circle(double r) : radius(r) {}
    double Area() const override { return M_PI * radius * radius; }
};

// Производный класс RightTriangle
class RightTriangle : public Shape {
   private:
    double base, height;

   public:
    RightTriangle(double b, double h) : base(b), height(h) {}
    double Area() const override { return 0.5 * base * height; }
};

// Производный класс Trapezoid
class Trapezoid : public Shape {
   private:
    double base1, base2, height;

   public:
    Trapezoid(double b1, double b2, double h)
        : base1(b1), base2(b2), height(h) {}
    double Area() const override { return 0.5 * (base1 + base2) * height; }
};

int main() {
    President president;
    Manager manager;
    Worker worker;

    Employer* employees[] = {&president, &manager, &worker};

    for (const auto& employee : employees) {
        employee->Print();
    }

    Rectangle rectangle(4, 5);
    Circle circle(3);
    RightTriangle rightTriangle(3, 4);
    Trapezoid trapezoid(2, 4, 3);
    Shape* shapes[] = {&rectangle, &circle, &rightTriangle, &trapezoid};

    for (const auto& shape : shapes) {
        cout << "S: " << shape->Area() << endl;
    }

    return 0;
}