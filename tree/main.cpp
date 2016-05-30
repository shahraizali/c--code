#include <iostream>


using namespace std;
void menu();
void add_node();
struct node
{
    int item;
    node* left;
    node* right;
};

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
        
        switch (choice)
        {
            case 1:
                if()
            break;
            case 2:
            break;
            case 3:
            break;
        default:
            break;
        }
    }
    
}

void add_node(){
    
     current = root;
    int t=1;
    while(t){
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