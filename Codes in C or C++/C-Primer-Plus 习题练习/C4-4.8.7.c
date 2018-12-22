#include <stdio.h>
#define EXMILES 3.785
int main(void)
{
    float miles,volume;
    const float EXVOL = 1.609;
    float result;
    printf("Please enter miles:\n");
    scanf("%f",&miles);
    printf("Please enter gas volume:\n");
    scanf("%f",&volume);
    result = miles/volume;
    printf("%.1f miles/gal\n",result);
    result = ((volume*EXVOL)/(miles*EXMILES))*100;
    printf("%.1f L/100km\n",result);
    return 0;
}