#include <stdio.h>

int exEO(int i)
{
	return ((0x55555555 & i)<<1) | ((0xaaaaaaaa & i)>>1);
}

int main(int argc,char* argv[])
{
	printf("Please enter a integer:\r\n");
	int i = 0;
	scanf("%x",&i);
	i = exEO(i);
	printf("exEO(i) = %x\r\n",i);
	return 0;
}
