#include <iostream>
#include <process.h>
using namespace std;
int size=0;
int front=0;
int rear = 0;
int* x= new int[size];
void create();
 int element;
   void display();
void enque(int);
int deque();
int main()
{
while(1){
    int choice;
    cout << "entre 1 to create queue" << endl;
    cout << "Enter 2 to enque element"<< endl;
    cout << "Enter 3 to deque element"<< endl;
    cout << "Enter 4 to display queue"<< endl;

    cout << "Enter your choice: ";
    cin >>choice;
    switch(choice){
        case 1:
            create();
            break;
        case 2:
            if(rear >= size){
                cout << "Queue is full ";

            }else{
            cout << "Enetr element : ";
            cin >>element;
            enque(element);
            }
            break;
        case 3:
            int catch1;
            catch1=deque();
           cout << catch1 <<" is dequeued from queue "<< endl;
            break;
        case 4:
            display();
            break;
        case -1:
            break;
    }

}
return 0;
}

void create(){

    cout << "enter size of queue: ";
    cin>> size;
 cout << "queue has been created of size :"<< size<< endl;
}
int deque(){
    int ret;
    ret = x[front];
   for (int i=0 ; i <size ; i++){
        x[i]=x[i+1];
   }
   size--;
   rear-=2;
   return ret;
}
void enque(int element){

    x[rear] =  element;
rear ++;

}
void display(){
    if(size >0){
       cout << "Queue = {";
        for(int i=0; i < rear ; i ++){
            cout << x[i]<< ", ";
        }
        cout << " }";
    }else{
    cout << "Empty "<< endl;
    }
    cout << endl;
}

