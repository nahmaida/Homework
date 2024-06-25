#include <iostream>
#include <vector>
using namespace std;

void calendar(int year) {
    cout << "Год ";
    switch (year % 12) {
        case 0: cout << "крысы"; break;
        case 1: cout << "зайца"; break;
        case 2: cout << "коровы"; break;
        case 3: cout << "тигра"; break;
        case 4: cout << "лошади"; break;
        case 5: cout << "змеи"; break;
        case 6: cout << "овцы"; break;
        case 7: cout << "дракона"; break;
        case 8: cout << "обезьяны"; break;
        case 9: cout << "петуха"; break;
        case 10: cout << "собаки"; break;
        case 11: cout << "свиньи"; break;
    }
}

void calendar(string month) {
    if (month == "Март" || month == "Апрель") {
        cout << "Овен";
    } else if (month == "Май") {
        cout << "Телец";
    } else if (month == "Июнь") {
        cout << "Близнецы";
    } else if (month == "Июль") {
        cout << "Рак";
    } else if (month == "Август") {
        cout << "Лев";
    } else if (month == "Сентябрь") {
        cout << "Дева";
    } else if (month == "Октябрь") {
        cout << "Весы";
    } else if (month == "Ноябрь") {
        cout << "Скорпион";
    } else if (month == "Декабрь") {
        cout << "Стрелец";
    } else if (month == "Январь") {
        cout << "Козерог";
    } else if (month == "Февраль") {
        cout << "Водолей";
    } else {
        cout << "Неверный месяц";
    }
}

double arr(vector<int> nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    return sum / nums.size();
}

double arr(vector<double> nums) {
    double max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

double arr(vector<float> nums) {
    double product = 1;
    for (int i = 0; i < nums.size(); i++) {
        product *= nums[i];
    }
    return product;
}

int main(int argc, char const *argv[]) {
    calendar(2000);
    cout << endl;
    calendar("Май");
    cout << endl;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << arr(nums) << endl;
    vector<double> nums1 = {90, 80, 70, 60, 50};
    cout << arr(nums1) << endl;
    vector<float> nums2 = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    cout << arr(nums2) << endl;
    return 0;
}
