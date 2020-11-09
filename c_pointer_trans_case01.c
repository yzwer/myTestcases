#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"



/*
    36、指针强转为整型，可能存在地址截断
        指针强转为整型，可能存在地址截断
*/


int main(int argc, char **argv)
{
    char * pStart = argv[1];
    char * pEnd = argv[2];
    
    int i = 0;
    
    /* POTENTIAL FLAW: 指针强转为整型，可能存在地址截断 */
    while ((unsigned int)pStart < (unsigned int)pEnd)
    {
        i++;
        break;
    }
}


