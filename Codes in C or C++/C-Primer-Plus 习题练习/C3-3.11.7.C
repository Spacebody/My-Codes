#include <stdio.h>
#define CONVER 2.54

int main(void)
{
    float height;
    printf("Please enter your height in feet:\n");
    scanf("%f",&height);
    printf("Your height is %.2f feet tall or %.2f cm tall.\n",height,height*CONVER);
    return 0;
}