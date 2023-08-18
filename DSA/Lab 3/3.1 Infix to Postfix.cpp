#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    else if (C == '$')
        return 4;
    return 0;
}

string infixToPostfix(const string& infix) {
    string modifiedInfix = '(' + infix + ')';
    int length = modifiedInfix.size();
    stack<char> charStack;
    string postfix;

    for (int i = 0; i < length; i++) {
        if (isalpha(modifiedInfix[i]) || isdigit(modifiedInfix[i]))
            postfix += modifiedInfix[i];
        else if (modifiedInfix[i] == '(')
            charStack.push('(');
        else if (modifiedInfix[i] == ')') {
            while (charStack.top() != '(') {
                postfix += charStack.top();
                charStack.pop();
            }
            charStack.pop();
        } else {
            if (isOperator(charStack.top())) {
                if (modifiedInfix[i] == '^') {
                    while (getPriority(modifiedInfix[i]) <= getPriority(charStack.top())) {
                        postfix += charStack.top();
                        charStack.pop();
                    }
                } else {
                    while (getPriority(modifiedInfix[i]) < getPriority(charStack.top())) {
                        postfix += charStack.top();
                        charStack.pop();
                    }
                }
                charStack.push(modifiedInfix[i]);
            }
        }
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

