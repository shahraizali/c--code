#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int z,x=0;
    int y=0;
    int num;
int t;
while(1){
        system("cls");
    printf("size of mario pyramid : ");
    scanf("%d",&num);
    t= num;
    for(x=0 ; x< num ; x++){
        for(z=t ; z>0 ; z--){
            printf(" ");
        }
        t--;
        printf("%d. ",x+1);
        for(y=0; y<=x ; y++){
            printf("*");
        }
        printf("\n");
    }
system("pause");
}

}
