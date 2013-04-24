#include <stdio.h>

int main(int argc, char* argv[])
{
	char s[256] = {0};
	int n = 0;
	int i = 0;

	printf("Please enter a string:");
	scanf("%[^\r\n]",s);
	for(i=0;'\0'!=s[i];i++)
	{
		if(' ' == s[i])
		{
			n+=2;
		}
	}

	while(0!=n)
	{
		if(s[i] == ' ')
		{
			s[i+n--] = '0';
			s[i+n--] = '2';
			s[i+n] = '%';
		}
		else
		{
			s[i+n] = s[i];
		}
		i--;
	}

	printf("%s\r\n",s);

	return 0;
}
