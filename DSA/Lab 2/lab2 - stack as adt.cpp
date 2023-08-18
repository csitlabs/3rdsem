// Lab 2 : Stack as ADT

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void createEmpty(Stack& s) {
    s.top = -1;
}

bool isEmpty(const Stack& s) {
    return (s.top == -1);
}

bool isFull(const Stack& s) {
    return (s.top == MAX_SIZE - 1);
}

void push(Stack& s, int value) {
    if (isFull(s)) {
        cout << "Stack is full. Cannot push element." << endl;
    } else {
        s.top++;
        s.items[s.top] = value;
        cout << "Pushed element: " << value << endl;
    }
}

void pop(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty. Cannot pop element." << endl;
    } else {
        int popped = s.items[s.top];
        s.top--;
        cout << "Popped element: " << popped << endl;
    }
}

void peek(const Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
    } else {
        int topElement = s.items[s.top];
        cout << "Top element: " << topElement << endl;
    }
}

void traverse(const Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = 0; i <= s.top; i++) {
            cout << s.items[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack s;
    int choice, value;

    createEmpty(s);
	cout << "Choose one of the following options:" << endl;
        cout << "1. Create an Empty Stack" << endl;
        cout << "2. Make an Empty Stack" << endl;
        cout << "3. Push Operation" << endl;
        cout << "4. Pop Operation" << endl;
        cout << "5. Peek Operation" << endl;
        cout << "6. Traverse Stack" << endl;
        cout << "7. Exit" << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createEmpty(s);
                cout << "Stack created." << endl;
                break;
            case 2:
                createEmpty(s);
                cout << "Stack made empty." << endl;
                break;
            case 3:
                cout << "Enter the value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 4:
                pop(s);
                break;
            case 5:
                peek(s);
                break;
            case 6:
                traverse(s);
                break;
            case 7:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (true);

    return 0;
}

