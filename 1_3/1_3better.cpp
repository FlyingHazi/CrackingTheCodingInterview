#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

	char s[256] = {0};
	printf("Please enter a string:");
	scanf("%s",s);
	int len = strlen(s);
	if(2 > len)
	{
		return 0;
	}
	int tail = 1;

	for(int i=1;i<len;i++)
	{

		int j;
		for(j=0;j!=tail;j++)
		{
			if(s[i] == s[j])
			{
				break;
			}
		}
		if(j == tail)
		{
			s[tail++] = s[i];
		}
	}
	s[tail] = '\0';
	printf("%s\r\n",s);

	return 0;
}
