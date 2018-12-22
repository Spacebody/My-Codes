#include <stdio.h>

void Fibonacci(int last, int current);
void reverse(int last, int current);

int main(void)
{
    Fibonacci(0,1);
    printf("\n");
    reverse(144,89);
    return 0;
}


void Fibonacci(int last, int current)
{
    if(current < 100)
    {
        printf("%d\n", current);
        int temp = last + current;
        Fibonacci(current, temp);
    }
    
}

void reverse(int last, int current)
{
    if(current > 0 )
    {
        printf("%d\n", current);
        int temp = last - current;
        reverse(current, temp);
    }
}
