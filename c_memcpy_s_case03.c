#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"




#define MY_HEAD_SIZE (20)
#define SIZE_OF_MY_INFO (8)

/*
    19、（有符号）变量作为指针偏移量，且来源于外部输入
*/
int test15_c(unsigned char * pData, unsigned int len)
{
    unsigned char * pPos = NULL;
    short sLen = 0;

    if (len >= MY_HEAD_SIZE + SIZE_OF_MY_INFO)
    {
        pPos = &pData[MY_HEAD_SIZE];
        
        /* POTENTIAL FLAW: （有符号）变量作为指针偏移量，且来源于外部输入  */
        memcpy_s(&sLen, sizeof(short), pPos, sizeof(short));

        pPos += sizeof(short);
        pPos += sLen; //error

    }
    return 0;
}

int main(int argc, char **argv)
{
    test15_c(argv[1], strlen(argv[2]));
}


