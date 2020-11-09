#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "securec_def.h"



/*
    2、fcvt输出参数可能为负数
    fcvt输出参数可能为负数，未经校验直接作为指针偏移或拷贝长度等，可能导致缓冲区溢出。
    char *fcvt(double number, int ndigits, int *decpt, int *sign)
*/
void test02_c(double dValue, unsigned int* pLen, unsigned char* pStr)
{
    int decimal = 0;
    int sign = 0;
    char* numStr = NULL;
    unsigned int pos = 0;

    numStr = fcvt(dValue, 8, &decimal, &sign);

    if (sign)
    {
    pStr[pos] = '-';
    ++pos;
    }

    if ((pos + decimal + 1) > *pLen)  // decimal为负数时可能有问题
    {
    return;
    }

    /* POTENTIAL FLAW: decimal为负数时可能有问题，destmax填对也可能有问题 */
    memcpy_s(&pStr[pos], decimal, numStr, decimal);  // decimal为负数时可能有问题，destmax填对也可能有问题

} 


int main(int argc, char *argv[])
{
    double d = 0;
    unsigned int pLen[100];
    unsigned char pStr[100];
	test02_c(d, pLen, pStr);
	return 0;
}
