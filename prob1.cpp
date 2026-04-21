#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int main() {
    Stack s;
    init(&s);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;

        if (!isOperator(token)) {
            push(&s, stoi(token));
        } else {
            int b = peek(&s); pop(&s);
            int a = peek(&s); pop(&s);

            int hasil;

            if (token == "+") hasil = a + b;
            else if (token == "-") hasil = a - b;
            else if (token == "*") hasil = a * b;
            else hasil = a / b;

            push(&s, hasil);
        }
    }

    cout << peek(&s) << endl;

    return 0;
}