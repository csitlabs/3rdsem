//5.2 Stack Operation Using Linked List

#include <iostream>
using namespace std;

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;

void push() {
    int val;
    struct node* ptr = new node;
    if (ptr == NULL) {
        cout << "Not able to push the element";
    } else {
        cout << "Enter the value: ";
        cin >> val;
        if (head == NULL) {
            ptr->val = val;
            ptr->next = NULL;
            head = ptr;
        } else {
            ptr->val = val;
            ptr->next = head;
            head = ptr;
        }
        cout << "Item pushed";
    }
}

void pop() {
    int item;
    struct node* ptr;
    if (head == NULL) {
        cout << "Underflow";
    } else {
        item = head->val;
        ptr = head;
        head = head->next;
        delete ptr;
        cout << "Item popped";
    }
}

void display() {
    struct node* ptr;
    ptr = head;
    if (ptr == NULL) {
        cout << "Stack is empty\n";
    } else {
        cout << "Printing Stack elements:\n";
        while (ptr != NULL) {
            cout << ptr->val << endl;
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice = 0;
    while (choice != 4) {
    	cout<<endl<<"Stack Operations Using Linked List" << endl;
        cout << "1. Push 2. Pop 3. Show 4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting....";
                break;
            default:
                cout << "Please enter a valid choice";
        }
    }
    return 0;
}

