#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
    const char* name = "Активатор угля";
    int price = 99;
    int amount;
    cout << "Выберите количество товара " << name 
         << " (стоимость: " << price << ")\n>> ";
    cin >> amount;
    int total = amount * price;
    int discount = 0;

    if (total > 1000) {
        discount = total * 0.25;
    } else if (total > 500) {
        discount = total * 0.1;
    } else if (total > 100) {
        discount = total * 0.05;
    }

    cout << "Итого: " << amount << " " << name << " на сумму " 
         << total << ", скидка " << discount;
    cout << "\nИтого к оплате: " << total - discount;
    return 0;
}
