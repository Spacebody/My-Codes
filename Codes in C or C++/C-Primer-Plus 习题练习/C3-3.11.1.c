#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("%d %d\n",INT_MAX,INT_MAX+1);
    printf("%d %d\n",INT_MIN,INT_MIN-1);
    printf("%e %e\n",DBL_MAX,DBL_MAX+DBL_EPSILON);
    printf("%e %e\n",DBL_MIN,DBL_MIN-DBL_EPSILON);
    printf("%e %e\n",FLT_MAX,FLT_MAX+FLT_EPSILON);
    printf("%e %e\n",FLT_MIN,FLT_MIN-FLT_EPSILON);
    return 0;
}