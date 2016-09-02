#include <stdio.h>

int main(void)
{
    char firstName[10],lastName[10];
    printf("Please eneter your first name and last name:\n");
    scanf("%s %s",firstName,lastName);
    printf("%s %s\n",firstName,lastName);
    printf("%s\n%s\n",firstName,lastName);
    printf("%s ",firstName);
    printf("%s\n",lastName);
    return 0;
}
