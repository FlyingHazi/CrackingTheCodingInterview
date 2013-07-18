#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void backMerge(char a[],const char b[],int al,int bl)
{
	unsigned int cur = al + bl;
	al--;
	bl--;
	a[cur] = '\0';
	while(al>=0 && bl>=0)
	{
		a[--cur] = a[al]<b[bl]?b[bl--]:a[al--];
	}

	while(bl>=0)
	{
		a[--cur] = b[bl--];
	}
}

int main(int argc,char* argv[])
{
	char a[256] = {0};
	char b[256] = {0};
	printf("Please enter two sorted strings:\r\n");
	scanf("%s%s",a,b);
	backMerge(a,b,strlen(a),strlen(b));
	printf("sorted string %s\n",a);
	return 0;
}
