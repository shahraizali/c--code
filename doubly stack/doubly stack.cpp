#include <iostream>
#include <windows.h>
using namespace std;

struct node {
	int item;
	node * previous;
	node * next;

 }*dhead = NULL, *dcurrent = NULL;


 void doublystackdisplay();
 void doublystackcreate();
 void doublystackmenu();
 void doublystackpush();
int  doublystackpop();
 void filedelete();
node *find(int number);

int main()
{
  doublystackmenu();
    return 0;
}


void doublystackmenu(){
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
                doublystackcreate();
                break;
            case 2:
                if(dhead == NULL){

                    cout << "stack does not exist"<< endl;
                    system("pause");
                    system("cls");
                }else{
                doublystackdisplay();
                }
                break;
            case 3:
                if(dhead == NULL){

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

                     doublystackpush();
                    }

                break;



                 case 4:
                if(dhead == NULL){

                    cout << "stack already empty"<< endl;
                    system("pause");
                    system("cls");
                }else{
                 int popped;
                  popped = doublystackpop();

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



void doublystackcreate(){
    char c;
	if (dhead != NULL){

		cout << "Overwrite(y/n)?";
		cin >> c;
	}if(c == 'y'||dhead == NULL||  c== 'Y'){
            if(c=='y'|| c=='Y'){
                dhead=NULL;
                dcurrent = NULL;
                }
			int cs;
			do{
				cout << "Enter size ";
				cin >> cs;

			}while(cs < 0);

			for(int i=0 ; i<cs ; i++){
				if (dhead == NULL){
					dhead = new node;
					dcurrent = dhead;
					cout << "Enter value : ";
					cin >> dcurrent -> item;
					dcurrent -> previous = NULL;
					dcurrent -> next = NULL;

				}else{
					dcurrent -> next= new node;
					(dcurrent ->next)-> previous = dcurrent;
					dcurrent = dcurrent -> next;
					cout << "Enter value : ";
					cin >> dcurrent -> item;
						dcurrent -> next =  NULL;
						}

			}cout << "Created successfully "<< endl;
	system("pause");
	system("cls");
	}

 }




 void doublystackdisplay(){

     cout << "dcurrent\t\tprev\t\titem\t\tnext"<< endl;
	if(dhead == NULL){
            cout << "Empty"<< endl;
			// not available
	}else{
        node*   ndcurrent = dhead;
		do{

		cout << ndcurrent <<"\t\t"<<ndcurrent->previous << "\t\t"<<
		ndcurrent-> item << "\t\t"<< ndcurrent -> next<< endl;
		ndcurrent = ndcurrent -> next;
		}while(ndcurrent != NULL);

	}

	system("pause");
	system("cls");
 }


void filedelete(){
    if(dhead != NULL){
            cout << "List Deleted successfully "<< endl;
        dhead = NULL;
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
    if(dhead == NULL){
            cout << "Empty"<< endl;
			// not available
	}else{
        dcurrent = dhead;
        do{
                if(dcurrent-> item == number){

                    t = dcurrent;
                }
            dcurrent=  dcurrent->next;
        }while(dcurrent != NULL);
	}

return t;
}



void doublystackpush(){

    dcurrent -> next = new node;

    (dcurrent -> next)-> previous=  dcurrent;
    dcurrent = dcurrent -> next;

    cout << "Enter value: ";
    cin >> dcurrent ->item;

    dcurrent -> next = NULL;

    cout << "Value has been pushed "<< endl;
    system("pause");
    system("cls");

}


int doublystackpop(){  int popped;
if(dcurrent ->next == NULL && dcurrent -> previous == NULL)
{
   popped= dcurrent ->item ;
    dhead = NULL;
    dcurrent = NULL;
    return popped;
}else{

          popped = dhead ->item;
    dhead = dhead -> next;
    dhead -> previous = NULL;
        return popped;
}
}
