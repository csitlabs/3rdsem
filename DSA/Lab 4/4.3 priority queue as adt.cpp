// priority queue as adt

#include <iostream>
#define size 100
using namespace std;

struct PriorityQueue {
    int items[size];
    int front;
    int rear;
};

void createEmptyQueue(PriorityQueue& pq) {
    pq.front = -1;
    pq.rear = -1;
}

bool isQueueEmpty(PriorityQueue& pq) {
    return pq.front == -1;
}

bool isQueueFull(PriorityQueue& pq) {
    return pq.rear == size - 1;
}

void enqueue(PriorityQueue& pq, int data) {
    if (isQueueFull(pq)) {
        cout << "Priority queue is full." << endl;
        return;
    }
    if (isQueueEmpty(pq)) {
        pq.front = 0;
        pq.rear = 0;
        pq.items[pq.rear] = data;
    } else {
        int i;
        for (i = pq.rear; i >= pq.front; i--) {
            if (data > pq.items[i])
                pq.items[i + 1] = pq.items[i];
            else
                break;
        }
        pq.items[i + 1] = data;
        pq.rear++;
    }
    cout << "Element enqueued successfully." << endl;
}

void dequeue(PriorityQueue& pq) {
    if (isQueueEmpty(pq)) {
        cout << "Priority queue is empty." << endl;
        return;
    }
    int item = pq.items[pq.front];
    if (pq.front == pq.rear) {
        pq.front = -1;
        pq.rear = -1;
    } else {
        pq.front++;
    }
    cout << "Dequeued item: " << item << endl;
}

void peek(PriorityQueue& pq) {
    if (isQueueEmpty(pq)) {
        cout << "Priority queue is empty." << endl;
        return;
    }
    cout << "Front item: " << pq.items[pq.front] << endl;
}

void traversal(PriorityQueue& pq) {
    if (isQueueEmpty(pq)) {
        cout << "Priority queue is empty." << endl;
        return;
    }
    cout << "Priority queue elements: ";
    for (int i = pq.front; i <= pq.rear; i++) {
        cout << pq.items[i] << " ";
    }
    cout << endl;
}

int main() {
    PriorityQueue pq;
    int choice, data;
    char ch;
    createEmptyQueue(pq);
    
    do {
    //	system("cls");
        cout << "Choose option:" << endl;
        cout << "1.Create empty priority queue	2.Check empty 3.Check full 4.Enqueue element 5.Dequeue element 6.Peek front element 7.Traverse 8.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                createEmptyQueue(pq);
                cout << "Empty priority queue created." << endl;
                break;
                
            case 2:
                if (isQueueEmpty(pq))
                    cout << "Priority queue is empty." << endl;
                else
                    cout << "Priority queue is not empty." << endl;
                break;
                
            case 3:
                if (isQueueFull(pq))
                    cout << "Priority queue is full." << endl;
                else
                    cout << "Priority queue is not full." << endl;
                break;
                
            case 4:
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(pq, data);
                break;
                
            case 5:
                dequeue(pq);
                break;
                
            case 6:
                peek(pq);
                break;
                
            case 7:
                traversal(pq);
                break;
                
            case 8:
                exit(0);
                
            default:
                cout << "Invalid choice." << endl;
        }
        
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    
    return 0;
}
