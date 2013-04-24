#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string s;
	char c = 0;
	char hm[256] = {};
	cout<<"Please enter a string:";
	cin>>s;

	for(int i=0;i!=s.length();i++)
	{
		c = s.at(i);
		if(0 != hm[c])
		{
			cout<<"This is not a unique string."<<endl;
			return 0;
		}	
		hm[c] = 1;
	}

	cout<<"This is a unique string."<<endl;
	return 0;
}
