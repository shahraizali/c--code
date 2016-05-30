#include <iostream>
#include <conio.h>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;
int ts=0,nts=0,top=-1,x=0,lenght=0;
char *stk = new char[ts];
char *nstk = new char[nts];
void input();
void parenthesise();
int operatorWeight(char);
void evaluate();
void postFix(char[],char[],int);
void menu();
int main(){
	system("cls");
	menu();
	getch();
}
void menu(){
	int choice;
	while(1){
		system("cls");
		cout<<"1-Input Expression\n";
		cout<<"2-Output\n";
		cout<<"3-exit";
		cout<<"\nChoose An Option : ";
		cin>>choice;
		cin.clear();
		cin.ignore(1000,'\n');
		switch(choice){
			case 1 :
				input();
			break;
			case 2 :
				evaluate();
			break;
			case 3 :
				exit(0);
			break;
			default :
				cout<<"Enter A Valid Number(1-4)";
			break;
		}
		getch();
	}
}
void input(){
	char ch;
	if(top!=-1){
		cout<<"Expression Already Exist.";
		cout<<"Do You Want To Enter Again(Y\\N)\n";
		cin>>ch;
	}
	if(top==-1 || ch=='y' || ch=='Y'){
		do{
			cout<<"Enter Total Num Of Char For Expression : ";
			cin>>ts;
		}while(ts<3);
		cout<<"Enter Expression Here : ";
		for(int i=0;i<ts;i++){
		cin>>stk[i];
	}
	top++;
		cout<<"Expression Successfully Inserted.";
		parenthesise();
	}
}
void parenthesise(){
	if(top==-1){
		cout<<"No Expression Exist.";
	}else{
		int u=0;
		for(int i=0;stk[i]!='\0';i++){
			if(stk[i]=='('){
				u++;
			}if(stk[i]==')'){
				u--;
			}
		}
		if(u==0){
			nts = ts + u;
				cout<<"\nExpression Is Fully Parenthesise.\n";
			for(int i=0;i<nts;i++){
				nstk[i]=stk[i];
		    	}
			}else{
				cout<<"\nExpression Is Not Fully Parenthesise.\n";
			}
		if(u>0){
			nts = u + ts;
			for(int j=0;j<nts;j++){
				if(j<ts){
					nstk[j] = stk[j];
				}else{
					nstk[j]=')';
				}
			}
				cout<<"Now Its Fully Parenthesise.\n";
		}if(u<0){
			u = u * -1;
			nts = u + ts;
			for(int k=0;k<nts;k++){
				if(k<u){
					nstk[k]='(';
				}else{
					nstk[k]=stk[k-u];
				}
				}
					cout<<"Now Its Fully Parenthesis.\n";
			}
		}
		cout<<"Parenthesise Expression Is : ";	
		for(int p=0;p<nts;p++){
			cout<<nstk[p];
		}
	}
	
void evaluate(){
	if(top==-1){
		cout<<"No Expression Exist.";
	}else{
		char *hope = new char[nts];
		postFix(nstk,hope,nts);
		int alpha = strlen(hope);
		for(int i=0;i<alpha;i++){
			cout<<hope[i];
		}
	}
}
int operatorWeight(char ch) {
   switch (ch) {
      case '/':
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

void postFix(char infix[], char postfix[], int size) {
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;   
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = operatorWeight(ch);
      if (weight == 0) {
         postfix[k++] = ch;

      }
       else {
         if (s.empty()) {
            s.push(ch);
         }
         else {
            while (!s.empty() && s.top() != '(' && weight <= operatorWeight(s.top())) {
               postfix[k++] = s.top();
               s.pop();

            }
            s.push(ch);
         }
      }
      i++;
   }
   while (!s.empty()) {
      postfix[k++] = s.top();
      s.pop();
   }
   postfix[k] = 0;
}
