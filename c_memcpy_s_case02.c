#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"



/*
    11、有符号变量作为拷贝长度，且长度值来源于外部输入，导致读越界。
    13、destmax填写不正确，destmax为三元运算符结果，可能导致destmax起不到保护作用。
*/
#define MAX_CODE_LEN (255)
#define MY_HEAD_SIZE (20)
#define SIZE_OF_MY_INFO (8)
int test10_c(unsigned char * pData, unsigned int len)
{
    unsigned char * pPos = NULL;
    char cName[MAX_CODE_LEN + 1] = {0};
    short sLen = 0;

    if (len >= MY_HEAD_SIZE + SIZE_OF_MY_INFO)
    {
        pPos = &pData[MY_HEAD_SIZE];
        
        memcpy_s(&sLen, sizeof(short), pPos, sizeof(short));

        pPos += sizeof(short);

        /* POTENTIAL FLAW: 有符号变量作为拷贝长度，且长度值来源于外部输入，导致读越界。 */
        memcpy_s(&cName[0], (sLen > MAX_CODE_LEN ? MAX_CODE_LEN : sLen), pPos, (sLen > MAX_CODE_LEN ? MAX_CODE_LEN : sLen)); //error

    }
    return 0;
}


int main(int argc, char **argv)
{
    test10_c(argv[1], strlen(argv[1]));
}


