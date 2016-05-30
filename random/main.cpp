#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
};

node * temp =new node();
int main()
{
temp->data = 5;
    cout << "value = "<<temp<< endl;
    return 0;
}
