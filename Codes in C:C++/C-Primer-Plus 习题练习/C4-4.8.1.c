#include <stdio.h>

int main(void)
{
    char firstName[10],lastName[10];
    printf("Please enter your first and last name:\n");
    scanf("%s %s",firstName,lastName);
    printf("%s, %s\n",firstName,lastName);
    return 0;
}
