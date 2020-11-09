#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"


/*
    34、streln结果用于字符串数组下标，且进行写操作，导致尾0被覆盖丢失
*/
void test290_c(char *pList)
{
    unsigned int strLen = 0;
    char *pEnd = NULL;
    strLen = strlen(pList);
    
    /* POTENTIAL FLAW: use strlen() as index of array, may loss the terminal '\0', after use the string, may cause buffer overflow   */
    if ('&' != pList[strLen - 1])
    {
        pList[strLen] = '&';
    }
    /* POTENTIAL FLAW: use strlen() as index of array, may loss the terminal '\0', after use the string, may cause buffer overflow   */
    pEnd = (char *)strstr(pList, "&");
    (void)pEnd;
}


int main(int argc, char **argv)
{
    test290_c(argv[1]);
}


