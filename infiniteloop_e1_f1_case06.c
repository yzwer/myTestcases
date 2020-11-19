#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void test24_c(const char *aucAttr)
{
	unsigned char ucCurrentIndex = 0;
	int count = 0;
	while (aucAttr[ucCurrentIndex] != '\0')
	{

		/* POTENTIAL FLAW: ucCurrentIndex type is unsigned char,
		if loop count max than 255, it will be a interger overflow, may cause infinite loop */
		ucCurrentIndex++; // 若循环次数大于255，则会进入死循环
		if (ucCurrentIndex == 254)
		{
			count++;
			printf("%d, let's infinitloop!\n", count);
		}
	}
	printf("%s\n", "no infinitloop!");
}


int main()
{
	unsigned char *aucAttr = "if loop count max than 255, it will be a interger overflow, may cause infinite loop - > len is 100.if loop count max than 255, it will be a interger overflow, may cause infinite loop - > len is 100.123132132132123132132132132123132123132132132123132132132132123132123132132132123132132132132123132123132132132123132132132132123132";
	test24_c(aucAttr);
	return 0;
}
