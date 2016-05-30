#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int MAX =10;

int st[10];
	int top=-1,t;


	bool isempty() ;
	bool isfull() ;
	void push(char var);

	void push1(int var);
	int topp1();
	char topp();
	void makeempty();
	int chk();
	char   pop();
	int   pop1();



    bool isopen(char symbol);
	bool isclose(char symbol);
	bool matches(char symbol ,char opensymbol);
	bool prsd(char ,char);
	int prsd1(char);
	int op(char);





int main()
{int n,i,c,x;float b,y,z;
    position2:
char a;

char symbol[20],opensymbol,p[20],s[20],ch;
	position9:
	    //try
    system("cls");int t=0;
	bool blanced=true;
makeempty();




cout<<"enter an integral expression within brackets round brack e.i. (2*3)\n";
		gets(symbol);	i=0;
		while(symbol[i] != '\0')
	{	if(isdigit(symbol[i])==false)
		{
			if(isopen(symbol[i])==true)
			{
			push(symbol[i]);
			goto position7;
			}
	else{
		if(isclose(symbol[i])==true)
		{
position6:
			opensymbol=topp();
if(opensymbol=='('||opensymbol=='{'||opensymbol=='['){
					//cout<<opensymbol;   _getch();
					pop();
					//cout<<blanced;      _getch();
		blanced = matches(symbol[i],opensymbol);
		if(blanced==true)
			goto position7;
		else
			goto position8;
}	else
			{
				c=pop();
				p[t]=c;    t++;
			goto position6;
}
		}else
			{
				if(isempty()==true||topp()=='('||topp()=='{'||topp()=='[')  {
				push(symbol[i]);

				//cout<<symbol[i];_getch();
				goto position7;
				}
		else 	{	opensymbol=topp();

		c=prsd(symbol[i],opensymbol);
		if(c==1){

			push(symbol[i]);	goto position7;
		}	else
			{
				opensymbol=pop();p[t]=opensymbol;t++;
				push(symbol[i]);goto position7;}
		}
		}
	}
		}
	else
	{
		p[t]=symbol[i];t++;goto position7;
		}     position7:
		i++;}
position8:
		//cout<<"value stored"<<t;_getch();
		if(isempty()!=true)
			blanced=false;
		else
			blanced=blanced;
if(blanced==true)
{ cout<<" expression is well formed\n\n";
}
		else{
			cout<<" expression is not well formed\n\n";   _getch(); goto position2;

		}
	//	system("cls");
	cout<<"\n postfix form is \n";
	for(int i=0;i<t;i++)
			cout<<p[i];
		_getch();


		for(int i=0;i<t;i++)
		{ if(isdigit(p[i]))
		{  int pt;
		pt=p[i]-48;
		//cout<<"digt going to push"<<pt;_getch();
		push1(pt);
		}
		else
			{ pop1();
		y=pop1();
		a=op(p[i]);
		if(a==1)
		{
		b=z + y;//  cout<<b; _getch();
		push1(b);
		goto position4;
		}
		else
		if(a==2){
			b=y - z;// cout<<b; _getch();
			push1(b);
			goto position4;
		}
		else
		if(a==3)
		{
			b=z * y;	 //cout<<b; _getch();
			push1(b);
			goto position4;
		}
		else
		if(a==4)
		{
			b= y / z;  //cout<<b; _getch();
		push1(b);goto position4;}

		} position4:cout<<"";
		}
position5:
	///	float n4;char h;
		//
		//cout<<"\n\n\t\t\ANSWER IS  :  "<<n4;

	//	_getch();
		 goto position2;



    return 0;
}


bool isopen(char symbol)

{
	if((symbol== '(' )||( symbol == '{' )||( symbol == '['))
		return true;
	else
		return false ;
}

bool isclose(char symbol)
{
	if((symbol== ')' )||( symbol == '}' )||( symbol == ']'))
		return true;
	else
		return false ;
}

bool matches(char symbol,char opensymbol)
{
	return (((opensymbol=='(') && symbol==')')
		|| ((opensymbol=='{') && symbol=='}')
		|| ((opensymbol=='[') && symbol==']'));
}





int op(char opr)
   {
	   if(opr=='+')

		   return 1;
	   else  if(opr=='-')
		   return 2;
		 else
			 if(opr=='*')
		   return 3;
		  else
			  if(opr=='/')
		   return 4;
		   //if(opr=='+')
		   //return 1;
   }
  bool prsd(char op1,char op2)
   {
	   int oper1,oper2;
	   oper1=prsd1(op1);
	   oper2=prsd1(op2);
	   if(oper1>=oper2)
		   return true;


	   else
	   return false;
   }
  int prsd1(char a)
  {if(a=='/'||a=='*')
  return 2;
  if(a=='+'||a=='-')
	  return 0;
  }






   int chk()
   {return top;
   }
   void makeempty()
   {
	   top=-1;
   }
bool isempty()
 {
	 return(top==-1);
}
bool isfull()
	{
		return(top==MAX-1);
}
void push(char  var )
	{

if(isfull())

	cout<<"Stack is Full";
		else
		st[++top]=var;
	}

// int wala push
void push1(int  var )
	{

if(isfull())

	cout<<"Stack is Full";
		else
		st[++top]=var;
	}



		char pop()
	{
	if(isempty()==true)
	cout<<"Stack is Empty";


		else

		return st[top--];
	}

		//int wala
		int  pop1()
	{//cout<<"intr hoa pop";cout<<isempty();_getch();
	if(isempty()==true)
cout<<"Stack is Empty";


		else

		return st[top--];
	}


	char topp()
	{	if(isempty())
			cout<<"Stack is Empty\n";

	else
	return st[top];
	}

		int topp1()
	{	if(isempty())
			cout<<"Stack is Empty\n";

	else
	return st[top];
	}







