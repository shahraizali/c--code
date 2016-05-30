
#include<iostream>
using namespace std;
int fabonaki(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(fabonaki(n-1)+(n-2));
    }
}
int main()
{    int n,i=0;
    cout<<"Enter the number of terms:";
    cin>>n;
    cout<<"\nfabonaki Series :";
  while(i<n)
    {        cout<<" "<<fabonaki(i);
        i++;
    }

    return 0;
}
