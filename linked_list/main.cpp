#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
//funnctions

void menu();
void display();
void create();

struct stack{
        int data;
        stack* next;
}*head=NULL , *current=NULL;


int main()
{
    menu();
    return 0;
}

void menu(){
int c;
while(1){
                cout << "Enter 1 to create linked list "<< endl;
               // cout << "Enter 2 to delete linked list "<< endl;
                cout << "Enter 2 to display linked list "<< endl;
                cout << "Enter 3 to exit "<< endl;
        //        cout << "Enter 1 to create linked list "<< endl;
        //        cout << "Enter 1 to create linked list "<< endl;
        //        cout << "Enter 1 to create linked list "<< endl;

        cout << "Enetr your choice ";
        cin >> c;

        switch(c){
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            system("cls");
            cout << "Wrong choice !"<< endl;
        }

}
}

void create(){
    char c;int size;
    if(head!= NULL ){
        cout << "Link LIst already exists want to over write(Y/N)? ";
        cin >> c;
    }if(head == NULL || c== 'y' || c== 'Y'){
          do{
            cout << "How many element you want to enter : ";
            cin >> size;
          }while(size < 1);
          for(int i=0 ;i < size ; i++){
                if(head == NULL ){

                    head = new stack;
                    current = head;

                    cout << "Enter element ";
                    cin >> current->data;
                    current->next =  NULL;
                }else{
                    current->next = new stack;
                    current =  current -> next;
                    cout << "Enter element ";
                    cin >> current->data;
                    current->next =  NULL;
                }
          }
        }

getch();
}
void display(){
    if(head == NULL){
        cout << "List is not created "<< endl;
    }else{
   // cout <<"&Head = "<< &head << ", Value = "<< head << endl;
    cout << "current    current->data      current->next"<< endl;
    current= head;
    do{
        cout << current << "            " << current->data << "           " << current->next<< endl;
        current = current->next;

    }while(current != NULL);
    }
    getch();
}

