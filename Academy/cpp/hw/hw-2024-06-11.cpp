#include <iostream>
#include <stack>
#include <string>
using namespace std;

// алгоритмом сортировочной станции и какими-то перевернутыми поляками
// не слишком жестоко ли

class Calc {
   public:
    int evaluate(string expression) {
        int i;
        stack<int> numbers;
        stack<char> ops;

        for (i = 0; i < expression.length(); i++) {
            if (expression[i] == ' ') {
                continue;
            } else if (expression[i] == '(') {
                ops.push(expression[i]);
            } else if (isdigit(expression[i])) {
                int val = 0;

                while (i < expression.length() && isdigit(expression[i])) {
                    val = (val * 10) + (expression[i] - '0');
                    i++;
                }
                numbers.push(val);
            }

            else if (expression[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int val2 = numbers.top();
                    numbers.pop();

                    int val1 = numbers.top();
                    numbers.pop();

                    char op = ops.top();
                    ops.pop();
                    numbers.push(maths(val1, val2, op));
                }

                ops.pop();
            }

            else {
                while (!ops.empty() &&
                       operators(ops.top()) >= operators(expression[i])) {
                    int val2 = numbers.top();
                    numbers.pop();

                    int val1 = numbers.top();
                    numbers.pop();

                    char op = ops.top();
                    ops.pop();
                    numbers.push(maths(val1, val2, op));
                }
                ops.push(expression[i]);
            }
        }

        while (!ops.empty()) {
            int val2 = numbers.top();
            numbers.pop();

            int val1 = numbers.top();
            numbers.pop();

            char op = ops.top();
            ops.pop();
            numbers.push(maths(val1, val2, op));
        }
        return numbers.top();
    }

   private:
    int operators(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        } else {
            return 0;
        }
    }

    int maths(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
};

int main() {
    Calc calc;
    cout << calc.evaluate("10 + 9 * 10") << "\n";
    cout << calc.evaluate("3 + 1 / 2 + ( 23 - 5 )") << "\n";
    cout << calc.evaluate("100 * ( 2 + 12 )") << "\n";
    cout << calc.evaluate("100 * ( 45 + 8 ) / 7") << "\n";
    return 0;
}