#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"


unsigned char * test18_c(unsigned char ucType, unsigned char *pucMsg)
{
    unsigned short usMsgLength = 0;
    unsigned char ucAttrLength = 0;
    unsigned char ucAttrType = 0;
    unsigned long ulCount = 0;

    if (NULL == pucMsg)
    {
        return NULL;
    }

    /* POTENTIAL FLAW: External data is not verified by fixed size offset or array subscript access.  */
    usMsgLength = *(unsigned short *)&pucMsg[2];
    
    if (usMsgLength <= 20)
    {
        return NULL;
    }

    usMsgLength -= 20;
    pucMsg += 20;

    while (usMsgLength)
    {
        ucAttrType = pucMsg[0];
        
        /* POTENTIAL FLAW: 
            usMsgLength could be 1 byte, which means that pucMsg[0] is valid, pucMsg[1]
            however would be an OOB read  
        */
        ucAttrLength = pucMsg[1];
        if(ucAttrLength < 2)
        {
            return NULL;
        }
        
        if (ucAttrType == ucType)
        {
            return pucMsg;
        }

        if (usMsgLength < ucAttrLength)
        {
            return NULL;
        }

        usMsgLength -= ucAttrLength;
        pucMsg += ucAttrLength;

        ulCount ++;
        if (ulCount > 100)
        {
            ulCount = 0;    
        }
    }
}


int main(int argc, char **argv)
{
    test18_c((unsigned char)(argv[1][0]), argv[2]);
}


