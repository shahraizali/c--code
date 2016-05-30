
//#include <iostream>
#include <process.h>
#include <iostream>
#include <windows.h>
using namespace std;


//structure
struct node {
	int data;
	node *next;
}*current = NULL, *head = NULL, *temp =NULL ;

// global variables
bool int_check = false;
bool wrong_char(char num);
//functions prototypes
void createll();
void delll();
void displayll();
void linkedlistmenu();
node* find(int number);
void addbyposition();
void updatebyposition();
//void addbyvalue();
void  min();

int main() {
	linkedlistmenu();
	system("pasue");
}

void linkedlistmenu() {
	int choice;
	char cchoice;
	while (1) {
		cout << "Enter 1 to create linked list " << endl;
		cout << "Enter 2 to delete linked list " << endl;
		cout << "Enter 3 to display linked list " << endl;
		cout << "Enter 4 to find element " << endl;
		cout << "Enter 5 to add element by position " << endl;
		cout << "Enter 6 to update element by poition " << endl;
		cout << "Enter 7 to smallest number " << endl;

		cout << "Enter -1 to exit program " << endl;


		do{
            cout << "Enter your choice : ";
            cin >> choice;
            int_check =  cin.fail();
                    if(int_check == true){

                        cout << "Entry should be an Integer "<< endl;
                    }
            cin.clear();
            cin.ignore(255,'\n');
		}while(int_check == true);


		switch (choice) {
		case 1:
			if (head != NULL) {
				system("cls");
				cout << "NOTE :\n  The list already exists want to overwrite (y/n)? ";
				do{
				cin >> cchoice;
                        if(cchoice == 'y' ||cchoice == 'Y' ||cchoice == 'n' ||cchoice == 'N' ){
                                break;

                        }else{  cout <<"\nWrong choice\nEnter your choice again (y/n) ? ";}
                }while(cchoice != 'y' ||cchoice != 'Y' ||cchoice != 'n' ||cchoice != 'N' );
				if (cchoice == 'y' || cchoice == 'Y') {
                        head=NULL;
					createll();
				}
			}
			else {
				createll();
			}

			break;
		case 2:
			if (head == NULL) {
				cout << "NOTE :\n  List does Not Exist create one first " << endl;
                    system("pause");
                    system("cls");
			}
			else {
				delll();
			}
			break;
		case 3:
			if (head == NULL) {

				cout << "NOTE :\n  List does Not Exist create one first " << endl;
                    system("pause");
                    system("cls");
			}
			else {
				displayll();
			}
			break;
		case 4:
			int number;
			node* returned;
			if (head == NULL) {
                cout << "NOTE :\n  List does Not Exist create one first " << endl;
                        system("pause");
                    system("cls");
			}
			else {
                do{
				cout << "Enter the element to find in list : ";
				cin >> number;
				int_check =  cin.fail();
                        if(int_check == true){

                            cout << "NOTE: Entry Should be an integer "<< endl;
                        }
                        cin.clear();
                        cin.ignore(255, '\n');
                }while(int_check == true );
				returned = find(number);
				if (returned == NULL) {

					cout << "The element \"" << number << "\" is not in the list " << endl;
                    system("pause");
                    system("cls");
				}
				else {
					cout << "Element found at " << returned << " location "<< endl;
                    system("pause");
                    system("cls");
				}
			}
			break;
		case 5:
			if (head == NULL) {
				cout << "NOTE :\n  List does Not Exist create one first " << endl;
                        system("pause");
                    system("cls");
			}
			else {
				addbyposition();
			}
			break;
		case 6:
			if (head == NULL) {
				cout << "NOTE :\n  List does Not Exist create one first " << endl;
                    system("pause");
                    system("cls");
			}
			else {
				//addbyvalue();
				updatebyposition();
			}
			break;

		case 7:
			if (head == NULL) {
				cout << "NOTE :\n  List does Not Exist create one first " << endl;
                        system("pause");
                    system("cls");
			}
			else {
				min();
			}
			break;
		case -1:
			exit(0);
			break;
		default:
			cout << "Note: Out Of Range "<< endl;
                system("pause");
                system("cls");
		}
	}

}

void createll() {
	system("cls");
	int value;int number, counter=0;



	//cout << "How many elements you wnat to enter : ";
	//cin >> number;

    do {
		cout << "How many elements you want to add: ";


		cin >> number;


		int_check = cin.fail();
		if (cin.fail() == true) {
			cout << "Entry should be an integer " << endl;
		}
		if(number <= 0){
                cout << "Note : Entry should be greater than 0 "<<endl;

		}
		cin.clear();
		cin.ignore(100, '\n');

	} while (int_check == true || number <= 0);


for (int i =	0; i < number; i++)
	{
		current = new node;
		if (head == NULL) {
			head = current;
			temp = current;
			do{
			cout << "Enter value : ";
			cin >> current->data;
			int_check =  cin.fail();
                if(cin.fail() ==  true){
                    cout << "ENtry should be an integer "<< endl;
                }
                cin.clear();
                cin.ignore(255 ,'\n');
			}while(int_check == true);

			current->next = NULL;
		}
		else {
			do {
                do{
                cout << "Enter value : ";
                cin >> current->data;
                int_check =  cin.fail();
                    if(cin.fail() ==  true){
                        cout << "ENtry should be an integer "<< endl;
                    }
                    cin.clear();
                    cin.ignore(255 ,'\n');
                }while(int_check == true);
				current->next = NULL;
				if (find(current->data) != NULL) {
					cout << " The element already exist at " << find(current->data) << " position " << endl;
				}
			} while (find(current->data) != NULL);

		//	current->next = NULL;
			temp->next = current;
			temp = temp->next;
		}
	}
      cout << "List of "<< number << " node"; if(number > 1)cout <<"s"; cout <<" has been created"<<endl;
      system("pause");
      system("cls");
}

void displayll() {
	system("cls");
	current = head;

	if (current->next == NULL) {
		cout << current->data << "   --->  NULL" << endl;
	}
	else {
            cout << "+---------------+-----------------------+-----------------------+"<< endl;
            cout << "|current adress\t|\tcurrent Data\t|\tNext Adress\t|"<< endl;
            cout << "+---------------+-----------------------+-----------------------+"<< endl;

		do {
			cout << "|" << current << "\t|\t" << current->data << "\t\t|\t";
			if (current->next == NULL) {
				cout << " NULL\t\t|"<< endl;
			}
			else {
				cout << current->next<<"\t|" << endl;
			}
			current = current->next;
		} while (current != NULL);
	 cout << "+---------------+-----------------------+-----------------------+"<< endl;

	}
	system("pause");
	system("cls");

}

void delll() {
	head = NULL;
	system("cls");
	cout << "List has been successfully deleted " << endl;

}
node* find(int number) {
	node *c;
	c = head;

	do {

		if (c->data == number) {
			return c;
		}

		c = c->next;
	} while (c != NULL);
	return NULL;
}

void addbyposition() {

	int p;
	node* t;
	temp = new node;
	cout << "Enter the position : ";
	do {
		cin >> p;
		if (p < 1) { cout << "Position should be positive i.e > 0 ! "<< endl; }
	} while (p < 1);
	if (p ==1) {

		do {
               do{
            cout << "Enter value : ";
			cin >> temp->data;
			int_check =  cin.fail();
                if(cin.fail() ==  true){
                    cout << "ENtry should be an integer "<< endl;
                }
                cin.clear();
                cin.ignore(255 ,'\n');
			}while(int_check == true);
			if (find(temp->data) != NULL) {
				cout << " The element already exist at " << find(temp->data) << " position " << endl;
			}
		} while (find(temp->data) != NULL);

		temp->next = head;
		head = temp;
	}
	else {
		current = head;
		for (int i = 1; i < p-1; i++) {
			if (current->next == NULL) {
				break;
			}
			current = current->next;
		}
		do {


			cout << "Enter value : ";
			cin >> temp->data;
			if (find(temp->data) != NULL) {
				cout << " The element already exist at " << find(temp->data) << " position " << endl;
			}
		} while (find(temp->data) != NULL);

		current = head;
		for (int i = 1;i<p - 1;i++) {
			if (current->next == NULL) {
				break;
			}
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		current = temp;
		cout << "Successfully Added."<< endl;

	}
	system("pause");
                    system("cls");
}

void updatebyposition() {

	int p;node *t;
	do {
		do {
			cout << "Enter Position To Update :";
			cin >> p;
		} while (p<1);
		current = head;
		for (int i = 1;i<p;i++) {
			current = current->next;
			if (current == NULL) {
				break;
			}
		}
	} while (current == NULL);
	int value; t = current;
	do {
		cout << "Enter Value : ";
		cin >> value;
	} while (find(value) != NULL);
	t->data = value;
	system("cls");
	cout << "Successfully Updated."<< endl;


}


void min() {
	node * search;
	search = head;
	node* last;
	int value =  search -> data;
	do {
		last = search;
		search = search->next;
		if (search->data < value) {
			value = search->data;

		}
	}while (search->next != NULL);
	system("cls");
	cout <<"adress -> "<< last<<"smallest is " << value <<" next -> "<< search << endl;
}


bool wrong_char(char num) {
	if (num != 'Y' || num != 'y' || num != 'n' || num != 'N')
	{

		return true;
	}
	else
		return false;


}

