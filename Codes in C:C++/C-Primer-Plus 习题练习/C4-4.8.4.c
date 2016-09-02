#include <stdio.h>

int main(void)
{
    float height;
    char name[10];
    printf("What's your name?\n");
    scanf("%s",name);
    printf("What's your height?\n");
    scanf("%f",&height);
    printf("%s, you are %.3f cm tall\n",name,height);
    return 0;
}