#include <iostream>
using namespace std;

int getLength(char *text) {
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    return length;
}

char *strip(char *text) {
    int length = getLength(text);
    while (text[0] == ' ') {
        text++;
    }
    while (text[length - 1] == ' ') {
        text--;
    }
    return text;
}

char *removeChar(char *text, int toRemove) {
    int length = getLength(text);
    if (toRemove >= length) {
        return text;
    }
    char *newText = new char[length - 1];
    int temp = 0;

    for (int i = 0; i < length; ++i) {
        if (i != toRemove) {
            newText[temp] = text[i];
            temp++;
        }
    }
    newText[temp] = '\0';
    return newText;
}

char *fixSpaces(char *text) {
    int length = getLength(text);
    text = strip(text);
    char prevChar = text[0];
    for (int i = 1; i < length; ++i) {
        if (prevChar == ' ' && text[i] == ' ') {
            text = removeChar(text, i);
            length = sizeof(text) / sizeof(char);
        }
        prevChar = text[i];
    }
    return text;
}

int main(int argc, char const *argv[]) {
    char *text = "  hello  world  ";
    text = fixSpaces(text);
    cout << text << endl;
    return 0;
}
