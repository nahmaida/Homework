// 6. Типы транспортных средств: Попросите пользователя выбрать тип транспортного средства, затем используйте switch case для вывода информации о типе и возможностях этого транспортного средства.

// 7. Статус заказа: Попросите пользователя ввести текущий статус заказа, затем используйте switch case для выполнения различных действий в зависимости от этого статуса.

// 8. Оценки студентов: Попросите пользователя ввести оценку студента, затем используйте switch case для вывода рекомендаций по этой оценке.

// 9. Времена года: Попросите пользователя ввести текущий месяц, затем используйте switch case для вывода сообщения о текущем времени года и характеристик каждого сезона.

// 10. Уровни доступа: Попросите пользователя ввести свой уровень доступа, затем используйте switch case для определения прав доступа к определенным функциям или ресурсам в зависимости от уровня доступа пользователя.

#include <iostream>
using namespace std;

void vehicleType() {
    char* type;
    cout << "1. Автомобиль\n2. Поезд\n3. Самолёт\n>> ";
    int mode;
    cin >> mode;
    switch (mode) {
        case 1:
            type = "Автомобиль";
            break;
        case 2:
            type = "Поезд";
            break;
        case 3:
            type = "Самолёт";
            break;
        default:
}

int main(int argc, char const *argv[]) {
    
    return 0;
}