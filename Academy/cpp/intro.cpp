#include <iostream>
using namespace std;

namespace Colors {
const char *RED = "\033[91m";
const char *ORANGE = "\033[33m";
const char *YELLOW = "\033[93m";
const char *GREEN = "\033[92m";
const char *CYAN = "\033[96m";
const char *BLUE = "\033[34m";
const char *PURPLE = "\033[35m";
const char *ENDL = "\033[0m\n";
const char *END = "\033[0m";
};  // namespace Colors

void verse(){
    cout
    << "\x1B[3m"
    << "\"The galaxies hum of shape and form in their essence.\nThat is their "
       "secret.\nThe particles whisper of the nature of proper interactions.\n"
       "That is their game.\nAnd during a storm, in the forest, on the right "
       "night, it is no secret that the leaves all sing of God.\""
    << "\x1B[0m\n\n\t\t\t\tThe fifth science - exurb1a";
};

void printColors() {
    // На все эти \t аж смотреть больно.
    // Можно их как-то сократить, как в питоне?
    cout
    << Colors::RED << "Каждый" << Colors::ENDL
    << Colors::ORANGE << "\tОхотник" << Colors::ENDL 
    << Colors::YELLOW << "\t\tЖелает" << Colors::ENDL
    << Colors::GREEN << "\t\t\tЗнать" << Colors::ENDL
    << Colors::CYAN << "\t\t\t\tГде" << Colors::ENDL
    << Colors::BLUE << "\t\t\t\t\tСидит" << Colors::ENDL
    << Colors::PURPLE << "\t\t\t\t\t\tФазан" << Colors::ENDL;
};

void forSale() {
    cout
    << Colors::PURPLE << "ПРОДАМ ШАВАРМУ." << Colors::ENDL
    << "Порода: Мексиканская (Тако)\n90 рублей.\n...\n"
    "Тел.: 1-800-255-5324\n800\t\t|  800  |\n255\t\t"
    "|  255  |\n5324\t\t|  5324 |\n";
};

int main(int argc, char const *argv[]) {
    int mode;
    cout << Colors::YELLOW << "1. Куплет\n2. Цвета (Стих)\n3. Обьявление"
         << Colors::ENDL << Colors::CYAN << ">> " << Colors::END;
    cin >> mode;
    switch (mode) {
        case 1:
            verse();
            break;
        case 2:
            printColors();
            break;
        case 3:
            forSale();
            break;
        default:
            break;
    }
    return 0;
}