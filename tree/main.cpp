#include <iostream>


using namespace std;

int main(){
    
    return 0;
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