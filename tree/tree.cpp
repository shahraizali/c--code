#include <iostream>
#include <windows.h>

using namespace std;

struct node
{
    int item;
    node* left;
    node* right;
};
void menu();
int add_node(int);
int find(int);
void create();
void display(node* );

node* root = NULL;
node * current = root;
int main(){

    menu();

    return 0;
}

void menu(){
    int choice;
    while (1)
    {
        cout << "Enter 1 to create "<<endl;
        cout << "Enetr 2 to display "<< endl;
        cout << "Enter 3 to add node "<< endl;
        cout << "Enter your choice:";
        cin >> choice;
        char c;
        switch (choice)
        {
            case 1:
                if(root != NULL){
                    cout << "You want to overwrite (y/n)? ";

                    cin >> c;
                }
                if(root == NULL || c== 'y' || c=='Y'){
                   root = NULL;
                   current = NULL;
                   create();
                }
            break;
            case 2:
                display(root);
                system("pause");
                system("cls");
            break;
            case 3:
                int value,a;

                if(root == NULL){
                    cout << "List does not exist"<< endl;
                }else{
                    cout << "Eneter value ";
                    cin >> value;
                    a=find(value);
                    if(a==0){
                        cout << "Duplicate value "<< endl;
                    }else{
                        add_node(value);
                    }
                    cout << "Successfully added "<< endl;
                    system("pause");
                    system("cls");
                }
            break;
        default:
            break;
        }
    }

}

int add_node(int v){

     current = root;
    
    while(1){
        if(current->item == v){

            return 0;
        } else{
            if(v< current-> item){
                if(current -> left == NULL){
                    current -> left = new node;

                    current = current ->left;
                    current -> item = v;
                    current -> left = NULL;
                    current -> right = NULL;
                    return 1;
                }else{
                    current = current -> left;
                }
            }else{
                if(current -> right == NULL){
                    current -> right = new node;
                    current = current -> right;
                    current -> item = v;
                    current -> left = NULL;
                    current -> right = NULL;
                    return 1;

                }else{
                    current = current -> right;
                }
            }

        }
    }
}


int find(int v){

     current = root;
    int t=1;
    while(t){
        if(current->item == v){

            return 0;
        } else{
            if(v< current-> item){
                if(current -> left == NULL){

                    return 1;
                }else{
                    current = current -> left;
                }
            }else{
                if(current -> right == NULL){

                    return 1;

                }else{
                    current = current -> right;
                }
            }

        }
    }
}




void create(){
    int counter;
    int value;
            int a;
    do
    {
        cout << "How many nodes you want to enter : ";
        cin >> counter;
    } while(counter< 1);

    for (int i = 0; i < counter; i++)
    {
        if(root == NULL){
            root = new node;
            current = root;
            cout << "Enter data : ";
            cin >> current->item ;
            current -> left = NULL;
            current -> right = NULL;
        }else{

            cout << "Enter data : ";
            cin >> value;
            a = add_node(value);
            if(a==0 ){
                cout << "Value is dublicate "<<endl;
                i--;
            }

        }
    }
    cout << "Successfully added "<< endl;
    system("pause");
    system("cls");
}



void display(node * start){
    if(start == NULL){
        return;
    }

    cout << start->item<< ", ";
    display(start -> left);
   display(start -> right);


}
