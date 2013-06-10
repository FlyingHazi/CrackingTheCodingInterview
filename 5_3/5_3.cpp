#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string nextSmallest(const string &binary)
{
	const int length = binary.size() + 1;
	char* next = new char[length];
	strcpy(next,binary.c_str());
	int i=length,j=length-1;
	for(;i>=0;--i)
	{
		if('1' == *(next+i))
		{
			break;
		}
	}
	if(-1 == i)
	{
		return binary;
	}
	for(;i>=0;--i)
	{
		if('0' == *(next+i))
		{
			*(next+i) = '1';
			*(next+(++i)) = '0';
			break;
		}
	}
	if(-1 == i || length == ++i)
	{
		return string(next);
	}

	j = length - 1;
	while('1' == *(next+i) && '0' == *(next+j) && i>j)
	{
		*(next+(i++)) = '0';
		*(next+(j--)) = '1';
	}
	string s = string(next);
	return s;
}

string prevBiggest(const string &binary)
{
	const int length = binary.size() + 1;
	char* prev = new char[length];
	strcpy(prev,binary.c_str());
	int i=length,j=length-1;
	for(;i>=0;--i)
	{
		if('0' == *(prev+i))
		{
			break;
		}
	}
	if(-1 == i)
	{
		return binary;
	}
	for(;i>=0;--i)
	{
		if('1' == *(prev+i))
		{
			*(prev+i) = '0';
			*(prev+(++i)) = '1';
			break;
		}
	}
	if(-1 == i || length == ++i)
	{
		return string(prev);
	}

	while('0' == *(prev+i) && '1' == *(prev+j) && i>j)
	{
		*(prev+(i++)) = '1';
		*(prev+(j--)) = '0';
	}
	string s = string(prev);
	return s;
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
