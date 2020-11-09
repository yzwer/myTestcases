#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"



/*
    36、指针强转为整型，可能存在地址截断
        指针强转为整型，可能存在地址截断
*/
void test29_c(char * pStart, char * pEnd)
{
    int i = 0;
    
    /* POTENTIAL FLAW: 指针强转为整型，可能存在地址截断 */
    while ((unsigned int)pStart < (unsigned int)pEnd)
    {
        i++;
        break;
    }

}


int main(int argc, char **argv)
{
    test29_c(argv[1], argv[2]);
}


