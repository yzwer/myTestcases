#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "securec_def.h"



#define HEADER_LEN (sizeof(HEAD_S))
#define TYPE_LEN (20)  //暂时将此宏设置为20

typedef struct 
{
    unsigned char nextType;
    unsigned char value[0];
}HEAD_S;

void test31_c(unsigned char* pMsg, unsigned long umLen, unsigned int* pLen)
{
    HEAD_S *pHead = NULL;
    unsigned char uType = 0;
    unsigned char uLen = 0;
    
    if (NULL == pMsg)
    {
        return;
    }

    pHead = (HEAD_S*)pMsg;
    *pLen = HEADER_LEN;

    uType = pHead->nextType;
    
    while (uType != 0)
    {
        /* POTENTIAL FLAW: There is no check here that pMsg + (*pLen) are within the bounds of the outer message.*/
        uLen = (*(unsigned char*)(pMsg + (*pLen)));
        
        if (0 == uLen)
        {
            return;
        }
        //Integer overflow
        (*pLen) += (uLen * 4 - 1);

        /* POTENTIAL FLAW: There is no check here that pMsg + (*pLen) are within the bounds of the outer message.*/
        uType = *((unsigned char*)(pMsg + (*pLen)));
        
        (*pLen) += TYPE_LEN;
        
        if ((*pLen) > umLen)
        {
            return;
        }
    
    }

    return;
}



int main(int argc, char **argv)
{
    unsigned int ulLen = 0;
    test31_c(argv[1], strlen(argv[1]), &ulLen);
}
