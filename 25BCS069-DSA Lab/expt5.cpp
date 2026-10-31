#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    bool pop(int &value) {              
        if (top == -1) return false;
        value = arr[top--];
        return true;
    }

    bool isEmpty() { return top == -1; }
};

bool calculate(int a, int b, char op, int &result) {
    switch (op) {
        case '+': result = a + b; return true;
        case '-': result = a - b; return true;
        case '*': result = a * b; return true;
        case '/':
            if (b == 0) { cout << "Error: Division by zero!" << endl; return false; }
            result = a / b;
            return true;
        case '%':
            if (b == 0) { cout << "Error: Modulo by zero!" << endl; return false; }
            result = a % b;
            return true;
        default:
            cout << "Invalid operator: " << op << endl;
            return false;
    }
}

bool evaluatePostfix(const string &expression, int &answer) {
    Stack s;
    size_t i = 0;

    while (i < expression.length()) {
        char ch = expression[i];

        if (ch == ' ') {               
            i++;
            continue;
        }

        if (isdigit(ch)) {              
            int value = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            if (!s.push(value)) return false;
        }
        else {                          
            int a, b, result;
            if (!s.pop(b) || !s.pop(a)) {
                cout << "Stack Underflow! Invalid postfix expression." << endl;
                return false;
            }
            if (!calculate(a, b, ch, result)) return false;
            s.push(result);
            i++;
        }
    }

    if (!s.pop(answer)) {
        cout << "Invalid postfix expression: nothing to evaluate." << endl;
        return false;
    }
    if (!s.isEmpty()) {                
        cout << "Invalid postfix expression: too many operands." << endl;
        return false;
    }
    return true;
}

int main() {
    string expression;

    cout << "Enter postfix expression (separate numbers with spaces): ";
    getline(cin, expression);

    int answer;
    if (evaluatePostfix(expression, answer))
        cout << "Result = " << answer << endl;

    cout << "\nPress Enter to exit...";
    cin.get();                          
    return 0;
}