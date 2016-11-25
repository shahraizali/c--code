#include <iostream>

using namespace std;
int length(long long int);
int main()
{
    long long int c;
    c = 378282246310005;
    bool authentic= false;
    int len =  length(c);
    cout << "Credit card number : "<< c << endl;
    int ct = 0;
    int summer = 0;
    int summer2 = 0;
   for ( long long int i=100 ; i < 100000000000000000 ; i*= 100){
        int even = ((c%i)/ (i/10))*2;
        int odd =  ((c%(i/10))/ (i/100));
        summer +=  (even%100/10)+(even%10);
        summer+= (odd%100/10)+(odd%10);
   }

   if(summer%10 == 0){
    cout <<"sum is "<< summer <<"\nit is a valid card number "<< endl;
    authentic = true;
   }
   if(authentic != true){
    cout << "invalid card number "<<endl;
   }


long long int nom = 1;
long long int denom = 1;
long long int denom2 = 1;
for(int i=0 ; i<len ; i++ ){
        nom *= 10;
}
denom =  nom/100;
denom2 =  nom/10; // for visa
int first = c %nom/denom;
int first2 = c %nom/denom2; // for visa

if(len == 15 && authentic == true){
    if( first == 34 || first == 37)
        cout << "AMEX BANK IT IS ";
}
if(len == 16 && authentic == true){
    if( first == 51 || first == 52 || first == 53 || first == 54 || first == 55)
        cout << "Master Card IT IS";
}
if(len == 16 || len == 13 ){
    if( first2 == 4 && authentic == true)
        cout << "Visa Card IT IS";
}


    return 0;
}





int length(long long int  c){
    long long int cg = c;
    int len = 0;
    while(cg > 0){
         cg= cg/10;
            len ++;
    }

    return len;
}
