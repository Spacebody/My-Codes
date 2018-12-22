#include <stdio.h>

int main(void)
{
    float a;
    printf("Please enter a float number:\n");
    scanf("%f",&a);
    printf("The input is %f or %e\n",a,a);
    return 0;
}