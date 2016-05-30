#include <iostream>
#include <windows.h>
using namespace std;

int top=0;
char lolo;
void astackmenu();
char astackpop();
void astackdelete();
void astackclear();
bool wrong_char(char);
void astackdisplay();
void create_astack();
void parenthesize();
void astackpush(char);
char* stack = new char[100];
char* stack1 = new char[100];

int top1 = 0;

bool stack_created = false;
int main() {

astackmenu();
	system("pause");
}

void astackmenu() {
	int choice;
	char c;
	char cha;
	while (1) {
		cout << "Enter 1 to create stack" << endl;
		cout << "Enter 2 to delete stack" << endl;
		cout << "Enter 3 to pop a number " << endl;
		cout << "Enetr 4 to push a number " << endl;
		cout << "Enter 5 to show stack " << endl;
		cout << "Enter 6 to paranthesize " << endl;
		cout << "Enter 7 to clear stack" << endl;
		cout << "Enter -1 to go back " << endl;
		cout << "Enter -2 to exit " << endl;

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
						create_astack();
						break;
					}
					if (c == 'N' || c == 'n') {
						system("cls");
						break;
					}

				} while(wrong_char(c) == true);
			}else {
				system("cls");
				create_astack();

			}
			break;
        case 2:
            if(stack_created == false){

                cout << "Stack Does Not exist"<< endl;
                system("pause");
                system("cls");
            }else
            astackdelete();
            break;
		case 4:
			if (stack_created == false) {
				cout << "Stack is not created" << endl;
                system("pause");
                system("cls");
			}
			else {
				system("cls");
				cout << "Enter the number you want to push to stack : ";
				cin >> cha;
				astackpush(cha);

			}

			break;
		case 3:
			if (stack_created == false) {

				cout << "Stack is not created" << endl;
                system("pause");
                system("cls");
			}
			else {
				system("cls");
				cha = astackpop();
				cout << "The character " << cha << " is popped out " << endl;
			}
			break;
		case 5:
			if (stack_created == false) {

				cout << "stack is not created"<< endl;
                    system("pause");
                system("cls");
			}
			else {

				astackdisplay();
			}

			//cout << "Wrong choice!" << endl;
			break;
		case 6:
			if (stack_created == false) {

				cout << "Stack is not created " << endl;
				system("pause");
                system("cls");
			}
			else if(top <=0){

				cout << "Stack is empty " << endl;
				system("pause");
                system("cls");
			}
			else {

				parenthesize();
			}
			break;

        case 7:
            if (stack_created == false) {

				cout << "Stack is not created " << endl;
				system("pause");
                system("cls");
			}
			else if(top1 <=0){

				cout << "Stack is empty " << endl;
				system("pause");
                system("cls");
			}
			else {

                astackclear();
			}
        case -1:
            break;
        case -2:

           exit(0);

        default:
            cout << "Choice out Of range "<< endl;
            system("pause");
                system("cls");


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
void create_astack() {

	cout << "Enter the size of stack ";
	cin >> top;
	top1 = top;

	cout << "Enetr the expression : ";
	for (int i = 0; i < top; i++) {

		cin >> stack[i];
		stack1[i] =  stack[i];
	}

	stack_created = true;
	cout << "Expression has been added to stack "<< endl;
	system("pause");

    system("cls");
}

void astackdisplay() {
	cout << "Stack = { ";
	for (int i = 0; i < top1; i++) {
		cout << stack1[i] << ", ";
	}
	cout << " }" << endl;
system("pause");
                system("cls");
}

void parenthesize() {
	int c = 0;
	char lc;
	for (int i = 0; i < top; i++)
	{
		lc = stack[i];

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
			cout << "\nThe expression is fully paranthesized " << endl;
		}
		else {
			cout << "Now fully parenthesized "<< endl;
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


system("pause");
system("cls");


}

void astackpush(char num) {

	stack1[top1] = num;
	top1++;
}

char astackpop(){
	top1--;
	return stack1[top1];
}


void astackdelete(){
    top = -1;
    stack_created = false;
    cout << "Stack has been deleted"<< endl;
    system("pause");
    system("cls");
}

void astackclear(){
top = 0;
top1 = 0;
cout << "Stack has been cleared"<< endl;

system("pause");
system("cls");
}
