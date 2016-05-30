#include <iostream>
#include <process.h>
#include <windows.h>
using namespace std;
int size=0;
int front=0;
int rear = -1;
int* x= new int[size];
void createqueue();
 int element;
   void displayqueue();
void enqueue(int);
int dequeue();
bool int_check = false;
void queuemenu();

int main()
{
queuemenu();
return 0;
}

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
    cin >>choice;
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

