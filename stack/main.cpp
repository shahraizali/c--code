#include <iostream>
#include <process.h>
#include <conio.h>
using namespace std;
//*--------Global Variables-------*//
int top = -1;
int size;
int * stack = new int[size];
int *old =  new int [size];
int x;
//*-------functions--------*//
void menu();
void create_stack();
void display_stack();
void push(int );
int pop();
int main(){

    menu();
    return 0;
}

void menu(){
    int choice;
    while(1){
     cout << "Enter 1 to create stack "<< endl;
     cout << "Enter 2 to display stack "<< endl;
     cout << "Enter 3 to push a number to stack "<< endl;
     cout << "Enter 4 to pop a number "<< endl;
     cout << "Enter your choice : ";
     cin >> choice;
     switch(choice){
    case 1:

        create_stack();
        break;
    case 2:
           if(top < 0){
        cout << "stack is not created yet "<< endl;
        }else{
        display_stack();}
    break;
    case 3:
        int number;
        if(top <0 ){
            cout << "stack does not exist "<< endl;
        }else{
        cout << "Enter the element to push to stack : ";
        cin >> number;
        push(number);
        }
        break;
    case 4:
        int num;

        num = pop();
        if(top >=0){
        cout <<"number "<< old[num] <<" has been popped out "<<endl;
       } break;
    default:
            cout << "This is default";
     }
    }
}

void create_stack(){
  char y_n = 'y';
  int s;
  if(top >= 0){
    cout << "stack already exist you want to overwrite (y/n)? ";
    cin >> y_n;


  }

  if(y_n ==  'y' || y_n ==  'Y'){
    cout << "How long stack you want ? ";
    cin >> size;

    cout << "How many elements you want to add to the list ? ";
    int s;
    cin >> s;
    top =  s;
    for (int i=0; i<s ; i++){
        cout << "Enter element at position "<< i << " : ";
        cin >> old[i];
    }
     cout <<"stack has been created !"<< endl;

  }else{

  }
}

void display_stack(){


        cout << " the stack is [ ";
        for(int i=0 ; i < top ; i++){
            cout << old[i]<< ",";
        }
        cout << "]"<< endl;

}

void push( int number ){
    if(top >= size){
        cout <<"top limit reached ";
    }else{
    old[top] =  number;
    top ++;
    }
}
int pop(){
    if(top <0){cout << "stack is empty "<< endl;
       top =0;
    }else{
    top--;

    return top;
    }
}
