#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Pair {
   private:
    T firstValue;
    T secondValue;

   public:
    Pair(T first, T second) : firstValue(first), secondValue(second) {}

    T first() const { return firstValue; }

    T second() const { return secondValue; }
};

template <typename T>
class Stack {
   private:
    vector<T> elements;

   public:
    void push(const T& value) { elements.push_back(value); }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        }
    }

    bool isEmpty() const { return elements.empty(); }

    T top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        throw out_of_range("Стак пустой");
    }
};

template <typename T1, typename T2>
class MixedPair {
   private:
    T1 firstValue;
    T2 secondValue;

   public:
    MixedPair(T1 first, T2 second) : firstValue(first), secondValue(second) {}

    T1 first() const { return firstValue; }

    T2 second() const { return secondValue; }

    void display() const {
        cout << "1: " << firstValue << ", 2: " << secondValue << endl;
    }
};

template <typename T>
class Queue {
   private:
    vector<T> elements;
    int frontIndex;
    int rearIndex;

   public:
    Queue() : frontIndex(0), rearIndex(0) {}

    void enqueue(const T& value) {
        elements.push_back(value);
        rearIndex++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw out_of_range("Очередь пустая");
        }
        frontIndex++;
        if (frontIndex >= rearIndex) {
            frontIndex = rearIndex = 0;
            elements.clear();
        }
    }

    bool isEmpty() const { return frontIndex == rearIndex; }

    T front() const {
        if (isEmpty()) {
            throw out_of_range("Очередь пустая");
        }
        return elements[frontIndex];
    }

    void print() const {
        for (int i = frontIndex; i < rearIndex; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

void testQueue() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Передний элемент: " << queue.front() << endl;
    queue.print();

    queue.dequeue();
    cout << "Передний элемент: " << queue.front() << endl;
    queue.print();

    queue.dequeue();
    queue.dequeue();

    if (queue.isEmpty()) {
        cout << "Пустая" << endl;
    }
}

void testMixedPair() {
    MixedPair<int, double> mp1(10, 20.5);
    MixedPair<string, bool> mp2("Hello", true);
    MixedPair<char, int> mp3('A', 65);

    mp1.display();
    mp2.display();
    mp3.display();
}

void testPair() {
    Pair<int> pair1(10, 20);
    Pair<string> pair2("Hello", "World");
    Pair<double> pair3(3.14, 2.71);
    cout << "1: " << pair1.first() << ", 2: " << pair1.second() << endl;
    cout << "1: " << pair2.first() << ", 2: " << pair2.second() << endl;
    cout << "1: " << pair3.first() << ", 2: " << pair3.second() << endl;
}

void testStack() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Верхний элемент: " << stack.top() << endl;
    stack.pop();
    cout << "Верхний элемент: " << stack.top() << endl;
}

int main(int argc, char const* argv[]) {
    testPair();
    testStack();
    testQueue();
    testMixedPair();
    return 0;
}
