
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>


void test03_c(char* Resp)
{
	char* pcStr = NULL;
	unsigned int ulLen = 0;

	pcStr = strtok(Resp, " ");
	if (pcStr)
	{
		ulLen = strlen(Resp);
		/* POTENTIAL FLAW: If there is no separator, the offset exceeds the threshold. Subsequent dereference will exceed the threshold. */
		pcStr = pcStr + ulLen + 2;
		while (*pcStr)
		{
			printf("%c,", *pcStr);
			pcStr++;
		}
	}
}


int main(int argc, char *argv[])
{
	//char Resp[] = "1234567890";
	if (argc < 2)
		return -1;
	test03_c(argv[1]);
	return 0;
}
