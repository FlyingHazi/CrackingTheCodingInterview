#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string nextSmallest(const string &binary)
{
	string next = binary;
	string::iterator i = next.begin();
	string::iterator j = next.begin();
	for(;i!=next.end();i++)
	{
		if('1' == *i)
		{
			j = i;
			break;
		}
	}
	if(next.end() == i)
	{
		return next;
	}
	for(;i!=next.end();i++)
	{
		if('0' == *i)
		{
			*i = '1';
			*(--i) = '0';
			break;
		}
	}
	if(next.end() == i || next.begin() == i || next.begin() == j)
	{
		return next;
	}
	i--;
	j--;
	for(;j!=next.begin();i--,j--)
	{
		*i = '0';
		*j = '1';
	}
	*i = '0';
	*j = '1';
	return next;

}

string prevBiggest(const string &binary)
{
	const int length = binary.size() + 1;
	char* prev = new char[length];
	strcpy(prev,binary.c_str());
	int i=0,j=0;
	for(;i!=length;++i)
	{
		if('0' == *(prev+i))
		{
			break;
		}
	}
	if(length == i)
	{
		return binary;
	}
	for(;i!=length;++i)
	{
		if('1' == *(prev+i))
		{
			*(prev+i) = '0';
			*(prev+(--i)) = '1';
			break;
		}
	}
	if(length == i || 0 == i)
	{
		return binary;
	}
	cout<<"i:"<<i<<endl<<"j:"<<j<<endl;
	--i;
	while('0' == *(prev+i) && '1' == *(prev+j) && i>j)
	{
		*(prev+(i--)) = '1';
		*(prev+(j++)) = '0';
	}
	return string(prev);
}

int main(int argc,char* argv[])
{
	string input;
	cout<<"Pleas input a binary:"<<endl;
	cin>>input;
	string next = nextSmallest(input);
	string prev = prevBiggest(input);
	cout<<"The next :"<<next<<endl;
	cout<<"The prev :"<<prev<<endl;
	return 0;
}
