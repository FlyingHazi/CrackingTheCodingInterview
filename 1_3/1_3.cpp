#include <stdio.h>

int main(int argc, char* argv[])
{
	char s[256] = {0};
	char f = 0;
	char *p1 = NULL;
	char *p2 = NULL;

	printf("Please enter a string:");
	scanf("%s",s);

	f = s[0];
	p1 = s;

	while('\0' != *p1)
	{
		while(*p1 == f)
		{
			p1++;
		}
		p2 = p1 + 1;
		while('\0' != *p2)
		{
			if(*p1 == *p2)
			{
				*p2 = f;
			}
			p2++;
		}
		p1++;
	}

	p1 = s + 1;
	while(*p1 != f && *p1 != '\0')
	{
		p1++;
	}
	p2 = p1;

	while('\0' != *p1)
	{
		while(*p2 == f)
		{
			p2++;
		}
		*p1 = *(p2++);
		if('\0' != *p1)
		{
			p1++;
		}else
		{
			break;
		}
	}

	printf("%s\r\n",s);

	return 0;
}
