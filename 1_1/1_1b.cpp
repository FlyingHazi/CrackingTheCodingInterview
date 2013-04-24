#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string s;
	cout<<"Please enter a string:";
	cin>>s;

	int l = s.length();
	const char* sp = s.c_str();
	const char* c = sp;
	const char* t = NULL;

	for(int i=0;i!=l;i++)
	{
		c = sp+i;
		t = c+1;
		while('\0' != *t){
			if(*t == *c)
			{
				cout<<"This is not a unique string."<<endl;
				return 0;
			}
			t++;
		};
	}
	cout<<"This is a unique string."<<endl;
	
	return 0;
}
