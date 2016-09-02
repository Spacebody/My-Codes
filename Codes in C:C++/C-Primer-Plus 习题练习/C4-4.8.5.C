#include <stdio.h>
#include <string.h>

int main(void)
{
    char firstName[10],lastName[10];
    printf("Enter your first name and last name:\n");
    scanf("%s %s",firstName,lastName);
    unsigned width1 = (int)strlen(firstName);
    unsigned width2 = (int)strlen(lastName);
    printf("%s %s\n",firstName,lastName);
    printf("%*d %*d\n",width1,width1,width2,width2);
    printf("%-*d %-*d\n",width1,width1,width2,width2);
    return 0;
}
