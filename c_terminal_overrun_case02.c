#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"


/*
    33、拷贝得到的数据作为字符串处理，可能没有尾0
        1. 通过memcpy_s拷贝得到的数据，未显式加尾0
        2. 通过尾0作为循环结束条件，处理该数据
*/
void test27_c( char* src, int len)
{
    char buf[10] = {0};
    char dest[10] = {0};
    int i = 0;

    /* POTENTIAL FLAW: 拷贝得到的数据作为字符串处理，可能没有尾0  */
    memcpy_s( buf, 10, src, len);

    
    /* POTENTIAL FLAW: 通过尾0作为循环结束条件，处理该数据  */
    while( '\0' != buf[i] )
    {
        dest[i] = buf[i];
        i++;
    }
}


int main(int argc, char **argv)
{
    test27_c(argv[1], strlen(argv[1]));
}


