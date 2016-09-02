#include <stdio.h>

int main(void)
{
    char name[10],address[100];
    printf("Please eneter your name and address:\n");
    scanf("%s %s",name,address);
    printf("your name is %s\nyour address is %s\n",name,address);
    return 0;
}