#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[10];
    printf("Please enter your name:\n");
    scanf("%s",name);
    unsigned width = (int)(strlen(name) + 3);
    printf("\"%s\"\n",name);
    printf("%20s\n",name);
    printf("%-20s\n",name);
    printf("%*s\n",width,name);
    return 0;
}
