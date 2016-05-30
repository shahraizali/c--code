#include <iostream>
#include <windows.h>
using namespace std;

struct node {
	int item;
	node * previous;
	node * next;

 }*head = NULL, *current = NULL;


 void display();
 void create();
 void menu();
 void push();
int  pop();
 void filedelete();
node *find(int number);

int main()
{
  menu();
    return 0;
}


void menu(){
    int choice;
        while(1){
                cout << "Enter 1 to create stack "<< endl;
                cout << "Enter 2 display stack "<< endl;
                cout << "Enter 3 to push element "<< endl;
                cout << "Enter 4 to pop element "<< endl;

                cout << "Enter choice:";
                    cin >> choice;

            switch(choice){
            case 1:
                create();
                break;
            case 2:
                if(head == NULL){

                    cout << "stack does not exist"<< endl;
                    system("pause");
                    system("cls");
                }else{
                display();
                }
                break;
            case 3:
                if(head == NULL){

                    cout << "stack does not exist"<< endl;
                    system("pause");
                    system("cls");
                }else{
                   /**  cout << "Enter number to find: ";
                    int number;
                    cin >> number;
                    node * ret;
                    ret = find(number);
                    if(ret !=NULL){
                    cout << "found at "<< ret << endl;
                    }else{
                        cout << "Not Found"<< endl;
                    \brief
                     *
                     * \param
                     * \param
                     * \return
                     *
                     */

                     push();
                    }

                break;



                 case 4:
                if(head == NULL){

                    cout << "stack already empty"<< endl;
                    system("pause");
                    system("cls");
                }else{
                 int popped;
                  popped = pop();

                  cout << "item "<< popped << " is popped !"<< endl;
                  system("pause");
                  system("cls");

                }break;
            default:
                cout << "Wrong choice";
                system("pause");
                system("cls");
            }
        }
}



void create(){
    char c;
	if (head != NULL){

		cout << "Overwrite(y/n)?";
		cin >> c;
	}if(c == 'y'||head == NULL||  c== 'Y'){
            if(c=='y'|| c=='Y'){
                head=NULL;
                current = NULL;
                }
			int cs;
			do{
				cout << "Enter size ";
				cin >> cs;

			}while(cs < 0);

			for(int i=0 ; i<cs ; i++){
				if (head == NULL){
					head = new node;
					current = head;
					cout << "Enter value : ";
					cin >> current -> item;
					current -> previous = NULL;
					current -> next = NULL;

				}else{
					current -> next= new node;
					(current ->next)-> previous = current;
					current = current -> next;
					cout << "Enter value : ";
					cin >> current -> item;
						current -> next =  NULL;
						}

			}cout << "Created successfully "<< endl;
	system("pause");
	system("cls");
	}

 }




 void display(){

     cout << "current\t\tprev\t\titem\t\tnext"<< endl;
	if(head == NULL){
            cout << "Empty"<< endl;
			// not available
	}else{
        node*   ncurrent = head;
		do{

		cout << ncurrent <<"\t\t"<<ncurrent->previous << "\t\t"<<
		ncurrent-> item << "\t\t"<< ncurrent -> next<< endl;
		ncurrent = ncurrent -> next;
		}while(ncurrent != NULL);

	}

	system("pause");
	system("cls");
 }


void filedelete(){
    if(head != NULL){
            cout << "List Deleted successfully "<< endl;
        head = NULL;
            system("pause");
    system("cls");
    }else{
        cout << "List does Not exist "<< endl;
        system("pause");
    system("cls");
    }
}


node * find(int number){
 node * t=NULL;
    if(head == NULL){
            cout << "Empty"<< endl;
			// not available
	}else{
        current = head;
        do{
                if(current-> item == number){

                    t = current;
                }
            current=  current->next;
        }while(current != NULL);
	}

return t;
}



void push(){

    current -> next = new node;

    (current -> next)-> previous=  current;
    current = current -> next;

    cout << "Enter value: ";
    cin >> current ->item;

    current -> next = NULL;

    cout << "Value has been pushed "<< endl;
    system("pause");
    system("cls");

}


int pop(){  int popped;
if(current ->next == NULL && current -> previous == NULL)
{
   popped= current ->item ;
    head = NULL;
    current = NULL;
    return popped;
}else{

          popped = head ->item;
    head = head -> next;
    head -> previous = NULL;
        return popped;
}
}
