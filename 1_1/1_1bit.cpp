#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	cout<<"Please enter a string:";
	string s;
	cin>>s;
	int checker = 0;
	int var = 0;

	for(int i=0;i!=s.length();i++)
	{
		var = s.at(i) - 'a';
		if((checker & (1<<var)) > 0)
		{
			cout<<"This is not a unique string."<<endl;
			return 0;
		}
		checker |= 1<<var;
	}

	cout<<"This is a unique string."<<endl;
	return 0;
}
