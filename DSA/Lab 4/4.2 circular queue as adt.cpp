// circular queue as adt

#include <iostream>
#include <stdlib.h>
using namespace std;

#define max 100

struct queue {
    int item[max];
    int rear, front;
};

int main() {
    queue s;
    int ch, x;
    int temp;
    char choice;

    // Initialize front and rear pointers for an empty queue
    s.front = -1;
    s.rear = -1;

    do {
        cout << "0. Make empty 1. Check empty 2. Check full 3. Enqueue 4. Dequeue 5. Traverse 6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 0:
            s.front = s.rear = -1; // Reset front and rear to indicate an empty queue
            break;

        case 1:
            if (s.rear == -1) {
                cout << "Queue is empty";
            }
            else {
                cout << "Queue is not empty";
            }
            break;

        case 2:
            if (s.front == (s.rear + 1) % max) { // Use '==' for comparison
                cout << "The queue is full";
            }
            else {
                cout << "The queue is not full";
            }
            break;

        case 3:
            if (s.front == (s.rear + 1) % max) { // Use '==' for comparison
                cout << "The queue is full";
            }
            else {
                cout << "Enter the number you want to enter: ";
                cin >> x;
                if (s.rear == -1) {
                    s.front = s.rear = 0; // If it's the first element, set front and rear to 0
                }
                else {
                    s.rear = (s.rear + 1) % max; // Increment rear pointer with wrap-around
                }
                s.item[s.rear] = x;
                cout << "Data entered successfully" << endl;
            }
            break;

        case 4:
            if (s.front == -1) {
                cout << "Queue is empty" << endl;
            }
            else {
                temp = s.item[s.front];
                if (s.front == s.rear) {
                    s.front = s.rear = -1; // Reset front and rear to indicate an empty queue
                }
                else {
                    s.front = (s.front + 1) % max; // Increment front pointer with wrap-around
                }
                cout << "Deleted item is " << temp << endl;
                cout << "Dequeue successful" << endl;
            }
            break;

        case 5:
            if (s.front == -1) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "The queue is" << endl;
                int i = s.front;
                while (true) {
                    cout << s.item[i] << ",";
                    if (i == s.rear) // Check if we have reached the rear element
                        break;
                    i = (i + 1) % max; // Move to the next index with wrap-around
                }
                cout << endl;
            }
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid choice" << endl;
        }

        cout << endl << "Do you want to continue (Y/N):";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

