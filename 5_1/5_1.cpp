#include <stdio.h>

int updateBits(int m, int n, const int i, const int j)
{
	const int max = ~0;
	const int left = max - ((1 << j) -1);
	const int right = (1 << i) -1;
	const int mask = left | right;
	printf("left=%x,right=%x,mask=%x\r\n",left,right,mask);
	m <<= i;
	return (n & mask) | m;
}

int main()
{
	int m,n,i,j;
	printf("Please enter m,n,i,j\r\n");
	scanf("%x %x %d %d",&m,&n,&i,&j);
	printf("\r\nm=%x,n=%x,i=%d,j=%d",m,n,i,j);
	if(i > j)
	{
		printf("error: i > j\r\n");
	}
	int bits = updateBits(m,n,i,j);
	printf("bits=%x\r\n",bits);

}
