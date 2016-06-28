#include <stdio.h>

int main(void){
    float water;
    float bottles;
    float volume;

    printf("How many bottles do you use while having a shower? ");
    scanf("%d",&water);
    printf("what is the volume of bottle? ");
    scanf("%d",&volume);
    printf("You use %f bottles\n",water/volume);

    system("pause");
}
