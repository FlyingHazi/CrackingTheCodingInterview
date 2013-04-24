#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char s[256] = {0};
	printf("Please enter a string:");
	scanf("%s",s);
	size_t l = strlen(s);
	char* p1 = s;
	char* p2 = s+l;
	char t = 0;

	while(p1<p2)
	{
		t = *p1;
		*(p1++) = *p2;
		*(p2--) = t;
	}

	for(int i=1;i<=l;i++)
	{
		printf("%c",s[i]);
	}
	printf("\r\n");
	return 0;
}
