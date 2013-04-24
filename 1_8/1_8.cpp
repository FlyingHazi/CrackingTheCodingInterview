#include <iostream>
#include <string>
using namespace std;

int main(int argc,char* argv[])
{
	string s1;
	string s2;
	cout<<"Please enter the 1st string:";
	cin>>s1;
	cout<<"Please enter the 2nd string:";
	cin>>s2;

	s1.append(s1);
	if(string::npos != s1.find(s2))
	{
		cout<<"yes"<<endl;
	}else
	{
		cout<<"no"<<endl;
	}
	return 0;
}
