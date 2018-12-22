#include <stdio.h>

int main(void)
{
    void print1(void);
    void print2(void);
    print1();
    print2();
    return 0;
}

void print1(void)
{
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
    printf("For he's a jolly good fellow!\n");
}

void print2(void)
{
    printf("Which nobody can deny!\n");

}