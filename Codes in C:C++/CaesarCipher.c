#include <stdio.h>
#include <string.h> //为了使用 strlen 函数
int main(void)
{
    char a[] = "pdeo eo pda yknnayp wjosan"; //待解的密文
    int i; 
    int b[strlen(a)]; // strlen 可以获取字符串 a 的长度，即有多少个字符。
                       
    for(i = 0;i<strlen(a);i++) 
    { 
        if(a[i] != ' ') 
        { 
            if(a[i]+4>'z') //如果往后移动四位之后超出了字母部分对应的 ascii码
            {  
                b[i] = (a[i]+4)%'z'+'a'-1;  
            }
            else
            { //如果没超过就直接移动 4 位之后赋值给 b
                b[i]=a[i]+4; //
            }
            a[i] = b[i]; 
        }
    }
    printf("%s\n", a); //输出解密后的结果
    return 0;
}
