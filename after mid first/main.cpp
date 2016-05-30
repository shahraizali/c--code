#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
    int size=0;
    int* mystack =  new int[size];

int top =-1;

void stackmenu();
void createstack();
void display();
void push(int number);
int pop();
int main()
{

    stackmenu();
    return 0;
}

void stackmenu(){

    while(1){

            cout << "Enter 1 to create stack " << endl;
            cout << "Enter 2 to display stack "<< endl;
            cout << "Enter 3 to push element "<< endl;
            cout << "Enter 4 to pop element "<< endl;
            cout << "Enter Your choice : ";
            int choice =0;char cchoice ='y';
            cin >> choice;
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
                if(top <=-1){cout << "stack does not exist "<< endl; getch(); system("cls"); }
                else{
                display();
                }
                break;
            case 3:
                int element;
                if(top < 0 ){
                    cout << "Stack does not exist "<< endl; getch(); system("cls");
                }else{
                    if(top < size){
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
                }else{
                    cout << "element "<< pop() << " is popped out "<<endl;
                    cout << "Now stack is \n   "<<endl;
                    display();
                }
                break;
            }

    }
}

void createstack(){
    char cchoice= 'n';
    int elementsize = 0;
    top =0;
    cout << "Enter size of stack ";
    cin >> size;

    cout << "Want to add elements now (y/n)";
    cin >> cchoice;

    if(cchoice == 'y' || cchoice == 'Y'){

        cout << "How many elements you want to add ";
      do{
        cin >> elementsize;

        if(elementsize > size){
            cout << "\nHint: you can add elements less than "<<size << "\nEnter Again : ";
        }if(elementsize <= 0){
            cout << "\nHint: Try a positive integer less than "<<size << "\nEnter Again : ";
        }
      }while(elementsize > size || elementsize <= 0);
int element;
        for (int i=0 ; i < elementsize ; i++){

            cout << "Enter Element : ";
            cin >>element;
            push(element);
        }

      }
}

void display(){

    cout << "[ ";
    for(int i=0 ; i < top+1 ; i++){

        cout << mystack[i]<<", ";
    }
    cout << "]"<< endl;

}

void push(int number){

        mystack[top] = number;
         top++;
}

int pop(){
    int element;
    element =  mystack[top];
    top--;
    return element;
}




