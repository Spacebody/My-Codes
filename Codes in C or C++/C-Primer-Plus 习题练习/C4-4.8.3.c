#include <stdio.h>

int main(void)
{
    float num;
    printf("Enter an float number:\n");
    scanf("%f",&num);
    printf("The input is %.1f or %.1e\n",num,num);
    printf("The input is %+.1f or %.1e\n",num,num);
    return 0;
}

