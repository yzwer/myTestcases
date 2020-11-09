#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"




/*
    32、从外部消息中获取的数据，没有显式加尾0，通过字符串拷贝函数处理
*/
typedef struct
{
    unsigned char *pCurAttr;
    unsigned char *pSendBuff;
    unsigned long ulTotalAttr;
    unsigned char etype;
    unsigned char ucIdentifier;
    unsigned short usPacketLen;
    unsigned char ucReserved[16];
}MY_Packet_S;
typedef struct
{
    unsigned char ucNumber;
    unsigned char ucLength;
}MY_Info;

#define MAX2 (200)
#define MAX1 (100)
unsigned int test26_c(MY_Packet_S *pPacket, unsigned char *pID)
{
    MY_Info  *pstAttr = NULL;
    unsigned long ulPacketCount = 0;
    unsigned long ullen = 0;
    unsigned char *pucAttr = NULL;

    pstAttr = (MY_Info*)((unsigned char*)pPacket + sizeof(MY_Packet_S));

    while (((unsigned char*)pstAttr != pPacket->pCurAttr)
           && (ulPacketCount < pPacket->ulTotalAttr))
    {
        pucAttr = (unsigned char *)pstAttr + 2;
        ullen = pstAttr->ucLength - 2;

        if(ullen > MAX2)      //error
        {
            return 0xFFFFFFFF;
        }

        // VULN: This assumes pucAttr is zero termianted
        /* POTENTIAL FLAW: 从外部消息中获取的数据，没有显式加尾0，通过字符串拷贝函数处理  */
        (void)strcpy_s(pID, MAX1 + 1, pucAttr);      //error
        
        // VULN: ullen has been checked against MAX2 and not MAX1
        //         so ullen could overflow
        pID[ullen] = '\0';      //error
        
        return 0;   
    }
}



int main(int argc, char **argv)
{
    test26_c((MY_Packet_S *)argv[2], argv[1]);
}


