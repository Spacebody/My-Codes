#include <stdio.h>
#define WATERMASS 3.0e-23
#define QUART 950

int main(void)
{
    int n;
    printf("Please enter the quart of water:\n");
    scanf("%d",&n);
    printf("There is %e molecules of water in %d water.\n",n*QUART/WATERMASS,n);
    return 0;
}