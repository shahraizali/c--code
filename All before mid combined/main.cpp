    #include <iostream>
    #include <Windows.h>
    #include <process.h>
    #include <sstream>
    #include <conio.h>
    using namespace std;



    void mainmenu();
    //global


    /*----List functions prototypes */
    #define exist -1
    #define donotexist 0
    int list_check = 0;
    int element_counter = 0;
    int list[100];
    int copy_list[100];
    //functions



    bool wrong_char(char num);
    void listmenu();
    void addelements();
    void createlist();
    void deletelist();
    void clearlist();
    void copy();
    void display();
    int find_by_position(int p);
    void updatebyposition(int value, int position);
    bool int_check = false;

    /*----end of List functions prototypes */


    /*----stack functions prototypes */

        int stacksize=0;
        int* mystack =  new int[stacksize];

    int top =-1;

    void stackmenu();
    void createstack();
    void displaystack();
    void push(int number);
    void deletestack();
    int pop();
// stack functions end

//stack app starts

//int top=0;
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

//stack app ends

// linked list functions start
struct node {
	int data;
	node *next;
}*current = NULL, *head = NULL, *temp =NULL ;

// global variables
//bool int_check = false;
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
//linked list functions end

//queue starts here
int size=0;
int front=0;
int rear = -1;
int* x= new int[size];
void createqueue();
 int element;
   void displayqueue();
void enqueue(int);
int dequeue();
//bool int_check = false;
void queuemenu();

// queue ends here


// stack linked list
int ts;
float *stk = new float[ts];
void SSmenu();
void displayStack();
bool isEmpty();
void isFull();
void SScreateStack();
void deleteStack();
void clearStack();
void queuepush(float);
int newpop();
int isLenght();
// stack linked list




//queue  using linked list

void QQUEUEMenu();
//queue
    int main() {
        mainmenu();

        system("pause");
    }
    //stringstream ss;

    void mainmenu(){
        int choice;
                while(1){
                        system("cls");
                    cout << "Enter 1 to go to simple list menu "<< endl;
                    cout << "Enter 2 to go to simple stack menu "<< endl;
                     cout << "Enter 3 to go to linked list menu "<< endl;
                    cout << "Enter 4 to go to queue menu"<< endl;
                    cout << "Enter 5 to go to stack application menu "<< endl;
                    cout << "Enter 6 to go to stack using linked list menu "<< endl;
                    cout << "Enter 7 to go to queue using linked list menu"<< endl;
                    cout << "Enter -1 to exit "<< endl;
                    do {

                cout << "Enter your choice : ";
                cin >> choice;
                int_check = cin.fail();
                if (cin.fail() == true) {
                    cout << "Entry should be an integer " << endl;

                }
                cin.clear();
                cin.ignore(100, '\n');

            }
            while(int_check == true);

                   switch(choice){
                    case 1:
                        system("cls");
                        listmenu();

                        break;
                    case 2:
                        system("cls");
                        stackmenu();
                        break;
                    case 3:
                        system("cls");
                        linkedlistmenu();
                        break;
                    case 4:
                        system("cls");
                        queuemenu();
                        break;
                    case 5:
                       // cout << "Working on it"<< endl;
                          //  system("pause");
                           // system("cls");
                        system("cls");
                            astackmenu();
                            break;
                    case 6:
                        system("cls");
                        SSmenu();
                        break;
                    case 7:
                        system("cls");
                        QQUEUEMenu();
                        break;
                    case -1:
                        exit(0);
                    default:
                       // system("cls");
                        cout << "Wrong choice Try again "<< endl;
                        system("pause");
                        system("cls");

                   }

                }
    }
    // +-----------------------------+
    // |List all functions definition|
    // +-----------------------------+
    void listmenu() {
        int choice;
        char y_n;

        while (1) {

            cout << "Enter 1 of create list : " << endl;
            cout << "Enter 2 to delete list : " << endl;
            cout << "Enter 3 to copy list : " << endl;
            cout << "Enter 4 to clear list : " << endl;
            cout << "Enter 5 to display list : " << endl;
            cout << "Enter 6 to add elements to list(append) : " << endl;
            cout << "Enter 7 to update by position : " << endl;
        //cout << "Enter 9 to update list by value : " << endl;
            cout << "Enter 8 to find element by position : " << endl;
            //cout << "Enter 10 to swap values by value : " << endl;
            cout << "Enter -1 to go back "<< endl;
            cout << "Enter -2 to exit program "<< endl;
            do {

                cout << "Enter your choice : ";
                cin >> choice;
                int_check = cin.fail();
                if (cin.fail() == true) {
                    cout << "Entry should be an integer " << endl;
                }
                cin.clear();
                cin.ignore(100, '\n');

            }
            while(int_check == true);
            switch (choice) {
            case 1:

                if (list_check == exist) {
                    cout << "List already exists do you want to overwrite (y/n)? :";

                    do {

                        cin >> y_n;
                        if (y_n == 'y' || y_n == 'Y') {
                            system("cls");
                            createlist();
                            break;
                        } if (y_n == 'n' || y_n == 'N') {
                            system("cls");
                            break;
                        }
                    } while (wrong_char(y_n) == true);
                }
                else {
                    createlist();
                }
                break;

            case 2:

                if (list_check == donotexist) {
                    cout << "The list does not exist, create the list first \n";
                            system("pause");
                            system("cls");

                }else {
                    cout << "Are you sure you want to delete the list (y/n) : ";
                    do {

                        cin >> y_n;
                        if (y_n == 'y' || y_n == 'Y') {
                            system("cls");
                            deletelist();
                            break;
                        } if (y_n == 'n' || y_n == 'N') {
                            system("cls");
                            break;
                        }
                    } while (wrong_char(y_n) == true);

                }
                break;
            case 3:

                if (list_check == donotexist) {
                    cout << "List does not exists , Create the list first \n";
                     system("pause");
                            system("cls");
                }else {
                    cout << "Are you sure you want to copy the list (y/n) : ";
                    do {

                        cin >> y_n;
                        if (y_n == 'y' || y_n == 'Y') {
                            system("cls");
                            copy();
                            break;
                        } if (y_n == 'n' || y_n == 'N') {
                            system("cls");
                            break;
                        }
                    } while (wrong_char(y_n) == true);

                }
                break;
            case 4:

                if (list_check == donotexist) {
                    cout << "List does not exist , Create the list first \n";
                     system("pause");
                            system("cls");
                }else {
                    cout << "Are you sure you want to clear the list (y/n) : ";
                    do {

                        cin >> y_n;
                        if (y_n == 'y' || y_n == 'Y') {
                            system("cls");
                            clearlist();
                            break;
                        } if (y_n == 'n' || y_n == 'N') {
                            system("cls");
                            break;
                        }
                    } while (wrong_char(y_n) == true);

                }break;
            case 5:

                if (list_check == donotexist) {

                    cout << "List does not exist , Create the list first \n";
                     system("pause");
                            system("cls");
                }else
                display();
                break;

            case 6:

                if (list_check == donotexist) {
                    cout << "List does not exist, Create the list first \n";
                     system("pause");
                            system("cls");
                }
                else {
                    addelements();
                }
                break;

            case 7:

                int pos;
                int val;
                if (list_check == donotexist) {
                    cout << "List does not exist , Crete the list first " << endl;
                     system("pause");
                            system("cls");
                }
                else {
                    do {
                        cout << "Enter the position of element : ";
                        cin >> pos;
                        cout << "Enter the value you want to replavce it with : ";
                        cin >>  val;
                    //	updatebyposition(pos, val);

                    } while ( pos <0 || pos > element_counter);
                    //	updatebyposition();
                }
                break;

            case 8:

            int value;

            if (list_check == donotexist) {
                cout << "List does not exist , Crete the list first " << endl;
                system("pause");
        system("cls");
            }
            else {
                do
                {
                    cout << "Enter the position to find value of " << endl;
                    cin >> pos;
                    if (pos > element_counter-1 || pos < 0) {
                        system("cls");
                        cout << "Entry out of range ! ";
                    }
                } while (pos  > element_counter-1 || pos <0);

                value = find_by_position(pos-1);
                cout << "Element at " << pos << " is " << value << endl;
            }
                break;
            case -1:
                mainmenu();
            case -2:
                exit(0);
            default:
                cout << "\n choice should be between 1 - 14 \n";
                system("pause");
                system("cls");
            }

        }

    }


    void createlist() {
        system("cls");
        int number;

        do {
    cout << "How many elements you want to add to list : ";


            cin >>number;
            int_check = cin.fail();
            if (cin.fail() == true || number <= 0) {
                cout << "Entry should be a positive integer i.e greater than 0 " << endl;
                system("pause");
        system("cls");
            }
            cin.clear();
            cin.ignore(100, '\n');

        } while (int_check == true || number <= 0);
        if (number < 0) { cout << " could not be less than 0 " << endl; }
        else {
            //cin >> number;
            element_counter = number;
            for (size_t i = 0; i < number; i++)
            {
                do {
                    cout << "Enter the number at " << i + 1 << " index: ";
                    cin >> list[i];
                    if (cin.fail() == true) {
                        cout << "Entry should be any integer\n\n";
                        cin.clear();
                        cin.ignore(100, '\n');
                        i--; if (i <= 0) i = 0;
                    }
                } while (cin.fail() == true);
                if (number > 1 && i >0) {
                    for (int j = 0; j < i; j++) {
                        if (list[j] == list[i]) {
                            cout << "number " << list[i] << " already exists at " << j + 1 << " index " << endl;
                            i--;
                        }
                    }
                }
            }
        }

        cout << "list of " << number << " numbers is created\n" << endl;
        list_check = exist;
        system("pause");
        system("cls");
    }

    void deletelist() {
        list_check = donotexist;
        element_counter = 0;
        cout << "List has been successfully deleted \n";
        system("pause");
        system("cls");
    }

    void clearlist() {

        element_counter = 0;

        cout << "List has been successfully cleared "<< endl;
        system("pause");
        system("cls");
    }

    void copy() {
        for (int i = 0; i < element_counter; i++) {
            copy_list[i] = list[i];
        }
        cout << "list has been copid successfully "<< endl;
        system("pause");
        system("cls");
    }

    void display() {
        system("cls");
        cout << "+-----------------------+" << endl;
        cout << "|index\t|\tdata\t|"<< endl;
        cout << "+-----------------------+ "<< endl;
        for (int i = 0; i < element_counter; i ++){
            cout <<"| "<< i+1 << "\t|\t" << list[i] << "\t|"<< endl;
        }
        cout << "+-----------------------+" << endl;
    system("pause");
        system("cls");
    }


    bool wrong_char(char num) {
        if (num != 'Y' || num != 'y' || num != 'n' || num != 'N')
        {
            cout << "Wrong choice \n try again :";
            return true;
        }
        else
            return false;


    }

    void addelements() {


        int number;

        do {
            cout << "How many elements you want to add to list : ";


            cin >> number;
            int_check = cin.fail();
            if (cin.fail() == true) {
                cout << "Entry should be an integer " << endl;
            }
            cin.clear();
            cin.ignore(100, '\n');

        } while (int_check == true);
        int old = element_counter;
        //cin >> number;
        element_counter += number;
        for (size_t i = old; i < number+old; i++)
        {
            cout << "Enter the number at " << i + 1 << " index: ";
            cin >> list[i];
            if (number > 1 && i >0) {
                for (int j = 0; j < i; j++) {
                    if (list[j] == list[i]) {
                        cout << "number " << list[i] << " already exists at " << j + 1 << " index " << endl;
                        i--;
                    }
                }
            }
        }

        cout << number << " more numbers added to the list\n Total elements in list = "<< number+old << endl;
        list_check = exist;
        system("pause");
        system("cls");
    }

    int find_by_position(int p) {
        return list[p];
    }

    // +------------------------------------+
    // |End of List all functions definition|
    // +------------------------------------+

    // +---------------------------------------+
    // |start of stack all functions definition|
    // +---------------------------------------+


    void stackmenu(){

        while(1){

                cout << "Enter 1 to create stack " << endl;
                cout << "Enter 2 to display stack "<< endl;
                cout << "Enter 3 to push element "<< endl;
                cout << "Enter 4 to pop element "<< endl;
                cout << "Enter 5 to delete Stack "<< endl;
                cout << "Enter -1 to go back "<< endl;
                cout << "Enter -2 to exit program "<< endl;
                cout << "Enter Your choice : ";
                int choice =0;char cchoice ='y';
               do {

                cout << "Enter your choice : ";
                cin >> choice;
                int_check = cin.fail();
                if (cin.fail() == true) {
                    cout << "Entry should be an integer " << endl;
                }
                cin.clear();
                cin.ignore(100, '\n');

            }
            while(int_check == true);
                switch(choice){
                case 1:
                    if(top > -1){
                            cout << "stack already exist you want to overwrite (y/n)?  ";
                            cin >> cchoice;

                    }
                    if(cchoice == 'y' || choice == 'Y' ){
                            system("cls");
                            createstack();
                    }

                    break;
                case 2:
                    if(top <=-1){cout << "stack does not exist "<< endl;
                    system("pause");
                    system("cls");
                     }
                    else{
                    displaystack();
                    }
                    break;
                case 3:
                    int element;
                    if(top < 0 ){
                        cout << "Stack does not exist "<< endl;
                        system("pause");
                        system("cls");
                    }else{
                        if(top < stacksize){
                        cout << "Enter element ";
                        cin >> element;
                        push(element);
                        }
                        else{
                         cout << "Stack Over flow "<< endl;
                        }
                    }
                    break;
                case 4:
                 if(top < 0 ){
                        cout << "Stack does not exist "<< endl;
                        system("pause");
        system("cls");
                    }else if(top ==0 ){
            cout << "Stack Empty "<< endl;
            system("pause");
            system("cls");

                }else
                    {
                        cout << "element "<< pop() << " is popped out "<<endl;
                        cout << "Now stack is \n   "<<endl;
                        displaystack();
                    }
                    break;
                case 5:
                     if(top < 0 ){
                        cout << "Stack does not exist "<< endl;
                        system("pause");
                        system("cls");
                    }else{
                    deletestack();

                        }
                    break;
                case -1:
                    mainmenu();
                    break;
                case -2 :
                    exit(0);
                default:
                    cout << "\n Wrong Choice \n";
                system("pause");
                system("cls");
                }

        }
    }

    void createstack()  {

            cout <<"Enter the size of stack : ";
            cin >> stacksize;
            top =0;
            cout << "Stack of size "<<stacksize<<" has been successfully created "<< endl;
                system("pause");
                system("cls");
    }

    void  displaystack(){
        if(top > 0 ){
           cout << " [ ";
            for(int i=0 ; i < top ; i++){

                cout <<  mystack[i]<<" ,";
            }
            cout << "]"<< endl;
        }else{
            cout << "EMPTY STACK"<< endl;
        }
            system("pause");
                system("cls");
    }

    void push (int number ){
            mystack[top]=  number;
            top++;
            cout << number <<" successfuly pushed to stack "<< endl;
            cout << "Now stack is ";
            displaystack();
    }
    int pop(){


        int number;
        top--;
        number =  mystack[top];
        return number;

    }

    void deletestack(){

            char ch = 'n';
            cout << "You sure you want to delete stack (y/n)? ";
            cin >> ch;
            if(ch == 'y' || ch == 'Y'){ top = -1;
            cout << "Stack has been deleted "<< endl;
            }else{
                cout <<" Stack Not deleted "<< endl;
            }
            system("pause");
            system("cls");

    }



    // +------------------------------------+
    // |Linked List all functions definition|
    // +------------------------------------+

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
		cout << "Enter -1 to go back " << endl;
        cout << "Enter -2 to exit program " << endl;


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
				}system("cls");
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
                mainmenu();
		case -2:
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

	cout << "List has been successfully deleted " << endl;
    system("pause");
    system("cls");
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

	do {
          	cout << "Enter the position : ";
		cin >> p;
        int_check =  cin.fail();
		if (p < 1) { cout << "Position should be positive i.e > 0 ! "<< endl; }
        if(int_check == true ){ cout << "Entry should be integer "<< endl;}
        cin.clear();
        cin.ignore(255, '\n');
	}while (p < 1|| int_check == true);
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
                cout << "Enter the position to update : ";
                cin >> p;
                int_check =  cin.fail();
                if (p < 1) { cout << "Position should be positive i.e > 0 ! "<< endl; }
                if(int_check == true ){ cout << "Entry should be integer "<< endl;}
                cin.clear();
                cin.ignore(255, '\n');
            }while (p < 1|| int_check == true);
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
        do{
		cout << "Enter Value : ";
		cin >> value;
		int_check =  cin.fail();
		if(int_check== true){cout << "Wntry should be an integer "<< endl;}
		cin.clear();
		cin.ignore(255, '\n');
        }while(int_check== true );
	} while (find(value) != NULL);
	t->data = value;

	cout << "Successfully Updated."<< endl;
    system("pause");
    system("cls");

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

	cout <<"current adress -> "<< last<<" smallest is " << value <<" next adress -> "<< search << endl;

        system("pause");
        system("cls");
}



    // +-------------------------------------------+
    // |Linked List end of all functions definition|
    // +-------------------------------------------+



    // +----------=---------------------------------+
    // |stack app start of all functions definition|
    // +--------------------------------------------+

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
		 do {

                cout << "Enter your choice : ";
                cin >> choice;
                int_check = cin.fail();
                if (cin.fail() == true) {
                    cout << "Entry should be an integer " << endl;
                }
                cin.clear();
                cin.ignore(100, '\n');

            }
            while(int_check == true);
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
            mainmenu();
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


    // +----------=---------------------------------+
    // |stack app end of all functions definition|
    // +--------------------------------------------+

   // +----------=---------------------------------+
    // |queue start     of all functions definition|
    // +--------------------------------------------+

void queuemenu(){
while(1){
    int choice;
    cout << "enter 1 to create queue" << endl;
    cout << "Enter 2 to enqueue element"<< endl;
    cout << "Enter 3 to dequeue element"<< endl;
    cout << "Enter 4 to display queue"<< endl;
    cout << "Enter -1 to go back"<< endl;
    cout << "Enter -2 to exit"<< endl;
    cout << "Enter your choice: ";
    do {

                cout << "Enter your choice : ";
                cin >> choice;
                int_check = cin.fail();
                if (cin.fail() == true) {
                    cout << "Entry should be an integer " << endl;
                }
                cin.clear();
                cin.ignore(100, '\n');

            }
            while(int_check == true);
    char y_n='n';
    switch(choice){
        case 1:
            if(rear >= 0){
                cout << "queue already exists want to overwrite (y/n)?";
                do{
                cin >> y_n;
                        if(y_n == 'y'|| y_n == 'Y'||y_n == 'n'|| y_n == 'N'){
                               if(y_n == 'y'|| y_n == 'Y')
                                    createqueue();
                                break;
                        }else{
                            cout << "Enter again : ";
                        }
                }while(y_n != 'y'|| y_n != 'Y'||y_n != 'n'|| y_n != 'N');

                system("pause");
                system("cls");
            }else{
            createqueue();
            system("pause");
                system("cls");
            }
            break;
        case 2:
            if(rear >= size){
                cout << "Queue is full ";
                system("pause");
                system("cls");
            }else if(rear <= 0){
                cout << "Queue dows not exist "<< endl;
                system("pause");
                system("cls");
            }else{
            do{
            cout << "Enetr element : ";
            cin >>element;
            int_check = cin.fail();
                if(int_check ==  true){cout << "NOTE: Entry Should be an integer "<< endl;}
                cin.clear();
                cin.ignore(255, '\n');
            }while(int_check == true);
            enqueue(element);
            }
            break;
        case 3:
            int number;
            number=dequeue();
           cout << number <<" is dequeued from queue "<< endl;
            break;
        case 4:
            if(rear <=0){
                cout << "Queue dows not exist "<< endl;
                system("pause");
                system("cls");
            }else{
            displayqueue();
            }
            break;
        case -1:
            mainmenu();
            break;
        case -2:
            exit(0);
            break;
        default:
            cout << "Out of range"<< endl;
            system("pause");
            system("cls");

    }

}
}
void createqueue(){
do{
    cout << "enter size of queue: ";
    cin>> size;
     int_check = cin.fail();
                if(int_check ==  true || size <=0){cout << "NOTE: Entry Should be an integer and size should be positive "<< endl;}

                cin.clear();
                cin.ignore(255, '\n');
}while(size <= 0 || int_check == true);
    rear = 0;
 cout << "queue has been created of size :"<< size<< endl;


}
int dequeue(){
    int ret;
    if(rear ==0){
            cout << "Queue empty "<< endl;
               system("pause");
    system("cls");
        rear =0;
    }else{
    ret = x[0];
   for (int i=0 ; i <size ; i++){
        x[i]=x[i+1];
   }

   rear-=1;
   return ret;
}

}
void enqueue(int element){

    x[rear] =  element;
rear ++;
cout << element << " has been enqueued "<< endl;
system("pause");
system("cls");
}
void displayqueue(){
    if(rear>0){
       cout << "Queue = {";
        for(int i=0; i < rear ; i ++){
            cout << x[i]<< ", ";
        }
        cout << " }";
    }else{
    cout << "Empty "<< endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}




  // +----------=---------------------------------+
    // |queue start     of all functions definition|
    // +--------------------------------------------+


// stack using linked list



void SSmenu(){
	int choice;
	while(1){
		system("cls");
		cout<<"Enter 1 to Create Stack\n";
		cout<<"Enter 2 to Display Stack\n";
		cout<<"Enter 3 toPush Stack\n";
		cout<<"Enter 4 to Pop Stack\n";
		cout<<"Enter 5 to check if Full\n";
		cout<<"Enter 6 to check if Empty\n";
		cout<<"Enter 7 to Delete Stck\n";
		cout<<"Enter 8 to Clear Stack\n";
		cout<<"Enter 9 to check Lenght\n";
		cout<<"Enter -1 to go back\n";
		cout<<"Enter -2 to go exit\n";

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

		switch(choice){
			case 1 :
				SScreateStack();
			break;
			case 2:
				displayStack();
			break;
            case 3:
			    if(top==-1){
			    	cout<<"Stack doesnot exist";
				}else{
					if(ts<=top){
						cout<<"Stack Is Full.";
					}else{
						float n;
						cout<<"Enter Float Value : ";
						cin>>n;
						push(n);
					}
				}
			break;
			case 4:
				if(top==-1){
				    cout<<"First You Have To Create Stack.";
				}else{
					if(isEmpty()){
						cout<<"Stack Empty.";
					}else{
						float a;
						a = newpop();
						cout<<"Value is : "<<a;
					}

				}
			break;
			case 5:
				isFull();
			break;
			case 6:
				bool j;
				if(top==-1){
					cout<<cout<<"First You Have To Create Stack.";
				}else{
					j = isEmpty();
					if(j==1){
						cout<<"Stack Is Empty.";
					}else{
						cout<<"Stack Is Not Empty.";
					}
				}
			break;
			/** \brief case 7:
				deleteStack();
			break;
			case 8:
				clearStack();
			break;
			case 9:
				int i;
				if(top==-1){
					cout<<"First You Have To Create Stack.";
				}else{
					if(isEmpty()){
						cout<<"Stack Empty.";
					}else{
					}
					i = isLenght();
					cout<<"Lenght Of Stack Is : "<<i;
				}
			break;

             *
             * \param
             * \param
             * \return
             *
             */
			case -1:
			    mainmenu();
                break;
			case -2:
				exit(0);
			break;
			default :
				cout<<"Enter A Valid Value between 1-10\n";
				system("pause");
				system("cls");
			break;
		}
	   getch();
	}
}
void SScreateStack(){

    char c;
            if(head != NULL){

                    cout << "Already exist want to over write ";
                        cin >> c;
            }if(head == NULL || c== 'y' || c=='Y'){
                int number;
                do{
                cout << "Enter Number of elements to enter ";
                cin >> number;
                }while(number < 0);

                for(int i=0 ; i< number ; i++){
                    cout << "Enter value : ";
                    current = head;
                    head = new node;
                    cin >> head -> data;
                    head -> next = current;
                }
            }

            cout << "Stack has been created successfully"<< endl;
            system("pause");
            system("cls");
}
void displayStack(){
	/*if(top==-1){
		cout<<"First You Have To Create Stack. ";
	}else{
		if(top==0){
			cout<<"Stack Empty.";
		}else{
			cout<<"Sr No.  Data \n";
			for(int a=0;a<top;a++){
				cout<<a+1<<"\t"<<stk[a]<<endl;
			}
		}
	}*/

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
void queuepush(int p){
	current = head;
	head = new node;
	head ->data =  p;
	head->next =  current;
	cout<<"Value Successfully Added.";
	system("pause");
	system("cls");
}
void isFull(){
	if(top==-1){
		cout<<"First You Have To Create Stack";
	}else{
      if(top==0){
		cout<<"Stack Empty.";
	}else{
	if(ts<=top){
		cout<<"Stack Is Full.";
	}else{
		cout<<"Stack Is Not Full.";
	}
  }
}
}
bool isEmpty(){
	if(head ==NULL){
		return true;
	}else{
		return false;
	}
}

void clearStack(){
head = NULL;
current = NULL;
}


int newpop(){
	if(head == NULL){
        cout << "stack already empty"<< endl;
        system("pause");
        system("cls");
	}else{
	    int b;
	    b = head -> data;
	    head =head-> next;
	    return b;
	}
}

























//Queue using Link List
void displaylQueue();
void QQenqueue( int a);
int QQdequeue();
void createQQueue();
void deletQQueue();
int findQQueue(int x);

void QQUEUEMenu(){
	int choice;
	while(1){
			system("cls");
		cout<<"Enter 1 to Create Queue\n";
		cout<<"Enter 2 to Display Queue\n";
		cout<<"Enter 3 to Find \n";
		cout<<"Enter 4 to Delete Queue\n";
		cout<<"Enter 5 to Enqueue\n";
		cout<<"Enter 6 to dequeue\n";
		cout<<"Enter -1 to go back\n";
		cout<<"Enter -2 to exit\n";

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
		switch(choice){
			case 1:
				createQQueue();
			break;
			case 2:
				displaylQueue();
			break;
			case 3:
				if(head==NULL){
					cout<<"\nQueue is Not Created.";
				}else{
					int a,b;
					cout<<"\nEnter Value To Find : ";
					cin>>a;
		           b=findQQueue(a);

		           if(b==0){
		           	cout<<"\nvalue is not present in stack ";
				   }

				   else{
				   	cout<<"\nvalue found at index : "<<b;

				   }
				}
			break;
			case 4:
				deletQQueue();
			break;
			case 5:
				if(head==NULL){
					cout<<"\nStack Not Created.";
				}else{ int a;
				cout<<"\nenter value :";cin>>a;


			    QQenqueue( a);
}
			break;


			case 6:
			if(head==NULL){
					cout<<"\nStack Not Created.";
				}else{
				cout<<"\npop element is : :"<<QQdequeue();
			}
			break;
			case -1:
				mainmenu();
			break;
			case -2:
                exit(0);
			default:
				cout<<"Enter An Valid Option.";
				system("pause");
				system("cls");
			break;
		}
		getch();
	}
}
void createQQueue(){
	char ch;
	if(head!=NULL){
		cout<<"QueueAlready Exist.\n";
		cout<<"Do You Want To Overwrite (Y\\N)";
		cin>>ch;
	}
	if(head==NULL || ch=='y' || ch=='Y'){
		int a;
		do{
		cout<<"Enter Size : ";
		cin>>a;
	    }while(a<1);
	    int h;
	    cout<<"Enter element\n";
	    for(int i=0;i<a;i++){
	    	if(head==NULL){
	    		head = new node;
	    		current = head;
	    		cout<<"Enter "<<i+1<<" Element : ";
	    		cin>>current->data;
	    		head->next = head;
			}else{
				current->next = new node;
				current = current->next;
					cout<<"Enter "<<i+1<<" Element : ";
					cin>>current->data;
				current->next = head;
       }
    }
       cout<<"\nQueue Successfully Created.";
  }
}
void displaylQueue(){
	/*if(head == NULL){
		cout<<"\nQueue is not created";
	}else{
		temp = head;
		do{
			cout<<temp<<"\t"<<temp->data;
			cout<<"\t\t"<<temp->next<<endl;
			temp = temp->next;
		}while(temp!=head);
	}*/

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
		} while (current != head);
	 cout << "+---------------+-----------------------+-----------------------+"<< endl;

	}
	system("pause");
	system("cls");

}

void QQenqueue( int a){
	current->next=new node;
	current=current->next;
	current->data=a;
	current->next=head;
	cout<<"\nvalue successfully Enqueued ";

}

int QQdequeue(){
	int b;
	b=head->data;
	head=head->next;
	return b;
}
void deletQQueue(){
	if(head==NULL){
		cout<<"\nstack is not created";
	}else{
		head = NULL;
		cout<<"\nstack Successfully Deleted.";
        
	}
}
int findQQueue(int x)
{
node *tt=head;
int z=0;
do
{
	z++;
if(x==tt->data)
{
return z;
}
tt=tt->next;
}
while(tt!=head);
return 0;

}










































