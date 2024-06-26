#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Word {
    string word;
    int count;
};

class Text {
   public:
    vector<Word> words;
    Text(string filename) { parseWords(filename); }

    vector<Word> parseWords(string filename) {
        fstream inFile(filename, ios::in);
        if (!inFile) {
            cout << "Файл с таким именем отсутствует";
            exit(1);
        }
        string word, text;
        int count = 0;
        text.assign((istreambuf_iterator<char>(inFile)),
                    (istreambuf_iterator<char>()));
        removePunctuation(text);
        for (int i = 0; i < text.length(); i++) {
            text[i] = tolower(text[i]);
        }
        istringstream iss(text);

        while (iss >> word) {
            if (isWord(word)) {
                for (int i = 0; i < words.size(); i++) {
                    if (words[i].word == word) {
                        words[i].count++;
                    }
                }
            } else {
                Word newWord;
                newWord.word = word;
                newWord.count = 1;
                words.push_back(newWord);
            }
        }
        inFile.close();
        return words;
    }

    void printWords() {
        sortByFrequency();
        for (int i = 0; i < words.size(); i++) {
            cout << words[i].word << " " << words[i].count << endl;
        }
        countWords();
    }

    void findWord(string word) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i].word == word) {
                cout << "Слово " << words[i].word << " найдено "
                     << words[i].count << " раз(а)" << endl;
                return;
            }
        }
        cout << "Слово не найдено" << endl;
    }

    void countWords() {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            count += words[i].count;
        }
        cout << "Общее количество слов: " << count << endl;
    }

   private:
    void sortByFrequency() {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (words[i].count > words[j].count) {
                    Word temp = words[i];
                    words[i] = words[j];
                    words[j] = temp;
                }
            }
        }
    }

    void removePunctuation(string& word) {
        string punctuation = "!@#$%^'.,&*;:?()_+-=/\"";
        for (int i = 0; i < word.length(); i++) {
            if (punctuation.find(word[i]) != string::npos) {
                word.erase(i, 1);
            }
        }
    }

    bool isWord(string word) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i].word == word) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    string filename, word;
    cout << "Введите имя файла:\n>> ";
    cin >> filename;
    int choice;
    Text text(filename);
    do {
        cout << "\n1. Вывести слова с частотой\n2. Найти слово\n3. Количество "
                "слов\n4. Выход\n>> ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 1:
                text.printWords();
                break;
            case 2:
                cout << "Введите слово (строчными):\n>> ";
                cin >> word;
                text.findWord(word);
                break;
            case 3:
                text.countWords();
                break;
            case 4:
                break;
            default:
                cout << "Неверный выбор\n";
        }
    } while (choice != 4);
    return 0;
}
