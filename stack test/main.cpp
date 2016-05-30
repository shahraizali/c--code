#include <iostream>
#include <windows.h>
using namespace std;

int top=0;
char lolo;
void menu();
char pop();
bool wrong_char(char);
void display();
void create_stack();
void parenthesize();
void push(char);
char* stack = new char[100];
char* stack1 = new char[100];

int top1 = 0;

bool stack_created = false;
int main() {

	menu();
	system("pause");
}

void menu() {
	int choice;
	char c;
	char cha;
	while (1) {
		cout << "Enter 1 to create stack" << endl;
		cout << "Enter 2 to delete stack" << endl;
		cout << "Enter 3 to pop a number " << endl;
		cout << "Enetr 4 to push a number " << endl;
		cout << "Enter  5 to show stack " << endl;
		cout << "Enter 6 to paranthesize " << endl;
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice) {
		case 1:
			if(stack_created == true) {
				cout << "You want to overwrite the stack (y/n)";
				do {

					cin >> c;
					if (c == 'y' || c == 'Y') {
						system("cls");
						create_stack();
						break;
					}
					if (c == 'N' || c == 'n') {
						system("cls");
						break;
					}

				} while(wrong_char(c) == true);
			}else {
				system("cls");
				create_stack();

			}
			break;
		case 4:
			if (stack_created == false) {
				system("cls");
				cout << "Stack is not created" << endl;
			}
			else {
				system("cls");
				cout << "Enter the number you want to push to stack : ";
				cin >> cha;
				push(cha);

			}

			break;
		case 3:
			if (stack_created == false) {
				system("cls");
				cout << "Stack is not created" << endl;
			}
			else {
				system("cls");
				cha = pop();
				cout << "The character " << cha << " is popped out " << endl;
			}
			break;
		case 5:
			if (stack_created == false) {
				system("cls");
				cout << "stack is not created"<< endl;

			}
			else {
				system("cls");
				display();
			}

			//cout << "Wrong choice!" << endl;
			break;
		case 6:
			if (stack_created == false) {
				system("cls");
				cout << "Stack is not created " << endl;
			}
			else if(top <=0){
				system("cls");
				cout << "Stack is empty " << endl;
			}
			else {
				system("cls");
				parenthesize();
			}
			break;


		}

	}
}
bool wrong_char(char c) {
	if (c != 'y' || c != 'Y' || c != 'N' || c != 'n') {
		cout << "Wrong choice! \n Try again: " << endl;
		return true;

	}
	return false;
}
void create_stack() {

	cout << "Enter the size of stack ";
	cin >> top;
	top1 = top;

	cout << "Enetr the expression : ";
	for (int i = 0; i < top; i++) {

		cin >> stack[i];
		stack1[i]=stack[i];
	}

	stack_created = true;
}

void display() {
	cout << "Stack = { ";
	for (int i = 0; i < top1; i++) {
		cout << stack1[i] << ", ";
	}
	cout << " }" << endl;

}

void parenthesize() {
	int c = 0;
	char lc;
	for (int i = 0; i < top; i++)
	{
		lc = stack1[i];

		if (lc == '(')
		{
			c++;

		}
		else if (lc == ')') {
			c--;
		}
		else {

		}

	}if (c == 0) {
			cout << "\nThe expression was fully paranthesized " << endl;
		}
		else {
			cout << "The expression is Now fully parenthesized "<< endl;
			if (c > 0) {
				top1 =  c+top;
				for (int i = 0; i < top1; i++) {
					if (i < top) {
						stack1[i] = stack[i];
					}
					else
					{
						stack1[i] = ')';
					}
				}
				//cout << "Fully parenthesized ";
			}
			else
			{
				c = c*-1;
				top1 = c + top;
				for (int i = 0; i < top1; i++)
				{
					if (i < c) {
						stack1[i] = '(';

					}
					else
					{
						stack1[i] = stack[i-c];

					}
				}


			}
		}





}

void push(char num) {

	stack1[top1] = num;
	top1++;
	top++;
}

char pop(){
	top1--;
	top--;
	return stack1[top1];
}
