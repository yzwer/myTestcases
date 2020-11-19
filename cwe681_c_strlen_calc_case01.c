#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include "securec_def.h"

/*
4、strlen计算结果用于整数运算，存在整数溢出
*/
void test04_c(char* src)
{
	unsigned char caTmpCode[256] = { 0 };

	size_t len = strlen(src) - 1;   //error

									/* POTENTIAL FLAW: strlen计算结果用于整数运算，存在整数溢出， */
	memcpy_s(caTmpCode, sizeof(caTmpCode), src + 1, strlen(src) - 1);   //error

	if (strlen(src) > 1)
		len = strlen(src) - 1;      //ok

}


int main()
{
	char * p = "aa";
	test04_c(p);
	return 0;
}
