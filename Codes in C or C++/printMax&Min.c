#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("The minimum value of short int = %d\n", SHRT_MIN);
    printf("The maximum value of short int = %d\n", SHRT_MAX);
    
    printf("The minimum value of int = %d\n", INT_MIN);
    printf("The maximum value of int = %d\n", INT_MAX);
    
    printf("The minimum value of long int = %ld\n", LONG_MIN);
    printf("The maximum value of long int = %ld\n", LONG_MAX);
    
    printf("The minimum value of long long int = %lld\n", LLONG_MIN);
    printf("The maximum value of long long int = %lld\n", LLONG_MAX);

    printf("The maximum value of unsigned short int = %d\n", USHRT_MAX);
    
    printf("The maximum value of unsigned int = %u\n", UINT_MAX);
    
    printf("The maximum value of unsigned long int = %lu\n", ULONG_MAX);
    
    printf("The maximum value of unsigned long long int = %llu\n", ULLONG_MAX);

    
    printf("The minimum value of char = %d\n", CHAR_MIN);
    printf("The maximum value of char = %d\n", CHAR_MAX);
    
    printf("The maximum value of unsigend char = %d\n", UCHAR_MAX);
    
    return 0;
}