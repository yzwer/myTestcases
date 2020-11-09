#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "securec_def.h"




/*
    16、拷贝得到的数据作为字符串处理，可能没有尾0
        1. 通过recv获取，没有显式加尾0
        2. 给其它函数拷贝
*/
extern int recv(int, char*, int, int);
void test02_cpp()
{
    char data[255] = {0};
    int Len = 0;

    char m_str[200] = {0};
    
    Len = recv(0, data, 255, 0); 
    
    if (0 >= Len)
    {
      return;
    }
    
    if (0x0d == data[Len - 2] && 0x0a == data[Len - 1])
    {
      data[Len - 2] = 0;

      /* POTENTIAL FLAW: 拷贝得到的数据作为字符串处理，可能没有尾0 */
      strcpy_s(m_str, sizeof(m_str), data);
    }
    else
    {
      /* POTENTIAL FLAW: 拷贝得到的数据作为字符串处理，可能没有尾0 */
      strcpy_s(m_str, sizeof(m_str), data);
    }
}


int main(int argc, char **argv)
{
    test02_cpp();
}


