#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "securec_def.h"



#define HEADER_LEN (20)

void test32_c(unsigned char* pHeader, unsigned int Size)
{
    unsigned char uType = 0;
    unsigned char uLen = 0;
    unsigned char uTotalLen = 0;
    unsigned char* pData = NULL;

    pData = pHeader + HEADER_LEN;
    uType = *(pData-1);

    while (0 != uType)
    {
        uLen = (*pData) << 2;
        uTotalLen += uLen; //Integer overflow
        if (uTotalLen > 20 || 0 == uLen)
        {
            return;
        }
        
        /* POTENTIAL FLAW: Pointer offset comes from external input, and reading after offset leads to out-of-bounds read.*/
        pData += uLen;
        uType = *(pData-1);// OUT-OF-BOUNDS READ
    }
}




int main(int argc, char **argv)
{
    test32_c(argv[1], strlen(argv[1]));
}

