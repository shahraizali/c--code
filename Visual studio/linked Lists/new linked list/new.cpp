
//#include <iostream>
#include <process.h>
#include <iostream>

using namespace std;
//functions prototypes
void createll();
void deletell();
void displayll();
void mainmenu();

//structure
struct node {
	int data;
	node *next;
}*current = NULL, *head = NULL;

// global variables



int main() {
	mainmenu( );
	system("pasue");
}

void mainmenu() {
	int choice;
	char cchoice;
	while (1) {
		cout << "Enter 1 to create linked list " << endl;
		cout << "Enter 2 to delete linked list " << endl;
		cout << "Enter 3 to display linked list " << endl;
		/*cout << "Enter 4 to create linked list " << endl;
		cout << "Enter 5 to create linked list " << endl;
		*/
		cout << "Enter -1 to exit program " << endl;
		cout << "Enetr your choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (head != NULL) {
				cout << "the list already exists want to overwrite (y/n)? ";
				cin >> cchoice;
				if (choice == 'y' || choice == 'Y') {
					createll();
				}
			}
			else {
				createll();
			}
			system("cls");
			break;
		case 2:
			if (head == NULL) {
				cout << "List does Not Exist create one first " << endl;
			}
			else {
				deletell();
			}
			break;
		case 3:
			if (head == NULL) {
				cout << "List does Not Exist create one first " << endl;
			}
			else {
				displayll();
			}
			break;
		case -1:
			exit(0);
		}
	}

}

void createll() {
	system("cls");
	int value;
	head = new node;
	cout << "Enter the value : ";
	cin >> value;
	current = head;
	current->data = value;
	current->next = NULL;
}

void displayll() {
	current = head;
	if (current->next == NULL) {
		cout << current->data << "   --->  NULL" << endl;
	}
	else {
		do {
			cout << "current data = " << current->data << " , current next " << current->next << endl;
			current = current->next;
		} while (current != NULL);
	}

}