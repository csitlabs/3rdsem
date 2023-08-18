// queue as ADT

#include<iostream>
#include<stdlib.h>
using namespace std;

#define max 100

struct queue{
	int item[max];
	int rear, front;
};

int main(){
	queue s;
	int ch, x;
	int temp;
	char choice;

	do{
		cout << "0. Make empty 1. Check empty 2. Check full 3. Enqueue 4. Dequeue 5. Traverse 6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> ch;

		switch (ch){
			case 0:
				s.rear = -1;
				s.front = 0;
				break;

			case 1:
				if(s.rear < s.front){
					cout << "Queue is empty.";
				}
				else{
					cout << "Queue is not empty.";
				}
				break;

			case 2:
				if(s.rear == max-1){
					cout << "The queue is full.";
				}
				else{
					cout << "The queue is not full.";
				}
				break;

			case 3:
				if(s.rear == max-1){
					cout << "The queue is full.";
				}
				else{
					cout << "Enter the number you want to enter: ";
					cin >> x;
					s.rear = s.rear + 1;
					s.item[s.rear] = x;
					cout << "Data Entered Succesfully!" << endl;
				}
				break;

			case 4:
				if(s.rear < s.front){
					cout << "Queue is empty." << endl;
				}
				else{
					temp = s.item[s.front];
					s.front = s.front + 1;
					cout << "Deleted item is: " << temp << endl;
					cout << "Dequeue successfull!" << endl;
				}
				break;

			case 5:
				cout << "The queue is: " << endl;
				for(int i = s.front; i <= s.rear; i++){
					cout << s.item[i] << ",";
				}
				cout << endl;
				break;

			case 6:
				exit(0);

			default:
				cout << "Invalid choice!" << endl;
		}
		cout << endl << "Do you want to continue? (Y/N): " << endl;
		cin >> choice;
	} while(choice == 'y');

	return 0;
}

