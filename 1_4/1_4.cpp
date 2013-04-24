#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int main(int argc, char* argv[])
{
	char s1[256] = {0};
	char s2[256] = {0};
	int l = 0;
	map<const char,int> m1;
	map<const char,int> m2;
	map<const char,int>::iterator it;

	printf("Please enter the 1st string:");
	scanf("%s",s1);
	printf("Please enter the 2nd string:");
	scanf("%s",s2);
	
	l = strlen(s1);
	if(l != strlen(s2))
	{
		printf("no");
		return 0;
	}

	for(int i=0;i!=l;i++)
	{
		m1[s1[i]]++;
	}
	for(int i=0;i!=l;i++)
	{
		m2[s2[i]]++;
	}

	if(m1 == m2)
	{
		printf("yes\r\n");
	}
	else
	{
		printf("no\r\n");
	}
	return 0;
}
