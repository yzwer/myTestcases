#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"



#define F_LEN (8)
#define MY_HEAD_LEN (16)
#define E_HEAD_LEN (8)
#define X_LEN (F_LEN + MY_HEAD_LEN + E_HEAD_LEN)

extern int memcpy_s(void* dest, size_t destMax, const void* src, size_t count);

unsigned char * test16_c(unsigned char * packet, const unsigned int len)
{
    unsigned char * pos = NULL;
    unsigned char vID = 0;
    unsigned short HeadELen = 0;

    pos = &packet[F_LEN];
    vID = packet[sizeof(unsigned short) + sizeof(unsigned short) + sizeof(unsigned char) + sizeof(unsigned short)];

    if (vID == 1)
    {

        memcpy_s(&HeadELen, sizeof(HeadELen), &packet[X_LEN - E_HEAD_LEN - sizeof(unsigned short)], sizeof(unsigned short));

        /* POTENTIAL FLAW: The variable is the subscript of the array and comes from the external input.  */
        pos = &packet[X_LEN - E_HEAD_LEN + HeadELen]; //error
    }

  return pos;
}


int main(int argc, char **argv)
{
    test16_c(argv[1], strlen(argv[2]));
}


