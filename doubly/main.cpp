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
                cout << "Enter 1 to create list "<< endl;
                cout << "Enter 2 display list "<< endl;
                cout << "Enter 3 find in list "<< endl;

                cout << "Enter choice:";
                    cin >> choice;

            switch(choice){
            case 1:
                create();
                break;
            case 2:
                if(head == NULL){

                    cout << "list does not exist"<< endl;
                    system("pause");
                    system("cls");
                }else{
                display();
                }
                break;
            case 3:
                if(head == NULL){

                    cout << "list does not exist"<< endl;
                    system("pause");
                    system("cls");
                }else{
                    cout << "Enter number to find: ";
                    int number;
                    cin >> number;
                    node * ret;
                    ret = find(number);
                    if(ret !=NULL){
                    cout << "found at "<< ret << endl;
                    }else{
                        cout << "Not Found"<< endl;
                    }
                }
                break;
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
		char c;
		cout << "Overwrite?";
		cin >> c;
	}if(head == NULL|| c== 'y'|| c== 'Y'){
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

			}
	}
	cout << "Created successfully "<< endl;
	system("pause");
	system("cls");
 }




 void display(){

     cout << "current\t\tprev\t\titem\t\tnext"<< endl;
	if(head == NULL){
            cout << "Empty"<< endl;
			// not available
	}else{
           current = head;
		do{

		cout << current <<"\t\t"<<current->previous << "\t\t"<<
		current-> item << "\t\t"<< current -> next<< endl;
		current = current -> next;
		}while(current != NULL);

	}
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

