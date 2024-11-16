#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ペット {
    int age;
    string name;
    double weigth;

   public:
    ペット(int age, string name, double weigth) {
        this->age = age;
        this->name = name;
        this->weigth = weigth;
    }

    virtual void 音() const = 0;
    virtual void 表示する() const { cout << name; }
    virtual void 種類() const = 0;
};

class 犬 : public ペット {
    string 種;

   public:
    犬(int age, string name, double weigth, string 種)
        : ペット(age, name, weigth) {
        this->種 = 種;
    }

    void 音() const override { cout << "ワンワン" << endl; }

    void 種類() const override {
        cout << "Порода вашей собаки: " << 種 << endl;
    }

    void 表示する() const override {
        cout << "Ваша собака: ";
        ペット::表示する();
        cout << endl;
    }
};

class 猫 : public ペット {
    string 種;
    bool 縞模様があります;

   public:
    猫(int age, string name, double weigth, string 種, bool 縞模様があります)
        : ペット(age, name, weigth) {
        this->種 = 種;
        this->縞模様があります = 縞模様があります;
    }

    void 音() const override { cout << "ニャーニャー" << endl; }

    void 種類() const override { cout << "Порода вашего кота: " << 種 << endl; }

    void 表示する() const override {
        cout << "Ваш кот: ";
        ペット::表示する();
        cout << "Ваш кот " << (縞模様があります ? "" : "не ") << "полосатый"
             << endl;
    }
};

class オウム : public ペット {
    string 色;
    string 種;

   public:
    オウム(int age, string name, double weigth, string 色, string 種)
        : ペット(age, name, weigth) {
        this->色 = 色;
        this->種 = 種;
    }

    void 音() const override { cout << "ピピピピ" << endl; }

    void 種類() const override { cout << "Вид вашего попугая: " << 種 << endl; }

    void 表示する() const override {
        cout << "Ваш попугай: ";
        ペット::表示する();
        cout << "Цвет: " << 色 << endl;
    }
};

class ハムスター : public ペット {
    string 種;
    bool 戦闘です;

   public:
    ハムスター(int age, string name, double weigth, string 種, bool 戦闘です)
        : ペット(age, name, weigth) {
        this->種 = 種;
        this->戦闘です = 戦闘です;
    }

    void 音() const override {
        cout << "Эта бэйби бомба я играю в Hamster Kombat
            Я срываю с нее блузку будто это пломба Прошло много времени,
            но это не часовня(удалено) раздевается -
                пять минут она готова Зависает здесь - это будто -
                бы дом 2(удалено)не понимает для чего ей Airdrop -
                это(удалено)(удалено) не понимает,
            как заработать(удалено) на бирже Вывести деньги -
                не знаю даже я Не знаю для чего эти baby " << endl;
    }

    void 種類() const override { cout << "Вид вашего хомяка: " << 種 << endl; }

    void 表示する() const override {
        cout << "Ваш хомяк: ";
        ペット::表示する();
        cout << "Ваш хомяк " << (戦闘です ? "" : "не ") << "боевой" << endl;
    }
};

class طعام {
    double بروتين;
    double دهن;
    double الكربوهيدرات;

   public:
    طعام(double بروتين, double دهن, double الكربوهيدرات) {
        this->بروتين = بروتين;
        this->دهن = دهن;
        this->الكربوهيدرات = الكربوهيدرات;
    }

    virtual void جعل() const = 0;
    virtual void أكل() const = 0;
    virtual void طبع() const {
        cout << "В 100г вашей великолепной пасты:" << endl;
        cout << "Белки: " << getبروتين() << " г, Жир: " << getدهن()
             << " г, Углеводы: " << getالكربوهيدرات() << " г\n"
             << endl;
        cout << "Калории: " << getالسعرات_الحراريه() << " ккал" << endl;
    };

    // جيترز
    double getبروتين() const { return بروتين; }
    double getدهن() const { return دهن; }
    double getالكربوهيدرات() const { return الكربوهيدرات; }
    double getالسعرات_الحراريه() const {
        return بروتين * 4 + دهن * 9 + الكربوهيدرات * 4;
    }

    // واضعي
    void setبروتين(double بروتين) { this->بروتين = بروتين; }
    void setدهن(double دهن) { this->دهن = دهن; }
    void setالكربوهيدرات(double الكربوهيدرات) {
        this->الكربوهيدرات = الكربوهيدرات;
    }
};

class معكرونة : public طعام {
    double length;
    double width;

   public:
    معكرونة(double بروتين, double دهن, double الكربوهيدرات, double length,
            double width)
        : طعام(بروتين, دهن, الكربوهيدرات) {
        this->length = length;
        this->width = width;
    }

    void جعل() const override {
        cout << "Осторожно срываем спагетти с пастового дерева..." << endl;
        cout << "Добываем воду из далеких комет пояса Койпера..." << endl;
        cout << "Осторожно доводим до кипения, добавляем соль..." << endl;
        cout << "Ждем 7 минут...\n...\n...\nАль Денте! Готово!" << endl;
    }

    void أكل() const override {
        for (int i = 0; i < 10; i++) {
            cout << "Наматываем на вилку..." << endl;
            cout << "Внимательно погружаем в ротовую полость..." << endl;
            cout << "Успешно поглощено!" << endl;
        }
    }

    void طبع() const override {
        طعام::طبع();
        cout << "Размер: " << length << "x" << width << " см" << endl;
    }
};

class مشروب : public طعام {
    double volume;
    double sugar;

   public:
    مشروب(double بروتين, double دهن, double الكربوهيدرات, double volume,
          double sugar)
        : طعام(بروتين, دهن, الكربوهيدرات) {
        this->volume = volume;
        this->sugar = sugar;
    }

    void جعل() const override {
        cout << "Выжимаем воду из воды..." << endl;
        cout << "Жарим сахар..." << endl;
        cout << "Говорим что немолоко лучше..." << endl;
        cout << "Готово!" << endl;
    }

    void أكل() const override {
        cout << "Наливаем в многогранный советский стакан..." << endl;
        cout << "Подносим к губам..." << endl;
        cout << "Страстно выпиваем..." << endl;
        cout << "Готово!" << endl;
    }

    void طبع() const override {
        طعام::طبع();
        cout << "Объем: " << volume << " мл" << endl;
        cout << "Сахар: " << sugar << " г" << endl;
    }
};

class دوشيراك : public طعام {
    string taste;
    bool isHalal;
    bool isKvisti;
    bool isDry;

   public:
    دوشيراك(double بروتين, double دهن, double الكربوهيدرات, string taste,
            bool isHalal, bool isKvisti, bool isDry)
        : طعام(بروتين, دهن, الكربوهيدرات) {
        this->taste = taste;
        this->isHalal = isHalal;
        this->isKvisti = isKvisti;
        this->isDry = isDry;
    }

    void جعل() const override {
        cout << "Разрываем упаковку..." << endl;
        cout << "Включаем чайник..." << endl;
        cout << "Все смешиваем..." << endl;
        cout << "Заливаем воду и ждем 5 минут...\n...\n...\nГотово!" << endl;
    }

    void أكل() const override {
        cout << "Намазываем на вилку..." << endl;
        cout << "Пьем бульончик..." << endl;
        cout << "Сьедено!" << endl;
    }

    void طبع() const override {
        طعام::طبع();
        cout << "Вкус: " << taste << endl;
        cout << "Халяль: " << (isHalal ? "Да" : "Нет") << endl;
        cout << "Квисти: " << (isKvisti ? "Да" : "Нет") << endl;
        cout << "Сухой: " << (isDry ? "Да" : "Фу") << endl;
    }
};

int main(int argc, char const *argv[]) {
    vector<طعام *> foods;
    foods.push_back(new معكرونة(10, 5, 20, 30, 30));
    foods.push_back(new مشروب(0, 0, 40, 200, 40));
    foods.push_back(new دوشيراك(5, 10, 20, "Говяжий", false, true, true));
    for (auto food : foods) {
        food->جعل();
        food->أكل();
        food->طبع();
        cout << endl;
    }
    return 0;
}
