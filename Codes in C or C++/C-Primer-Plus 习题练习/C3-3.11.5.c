#include <stdio.h>

int main(void)
{
    const float timePerYear = 3.156e7;
    int age;
    printf("Please enter your age:\n");
    scanf("%d",&age);
    printf("The age equals to %e s\n",timePerYear*age);
    return 0;
}