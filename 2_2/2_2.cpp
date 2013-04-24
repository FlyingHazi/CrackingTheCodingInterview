#include <iostream>
#include <list>
using namespace std;

int main(int argc,char* argv[])
{
	string s;
	int n = 0;
	list<char> ls;
	list<char>::iterator nt;
	cout<<"Please enter a string:";
	cin>>s;
	cout<<"please enter the n";
	cin>>n;
	if(s.size()<n)
	{
		cout<<"wrong"<<endl;
		return 0;
	}
	ls.assign(s.begin(),s.end());
	nt = ls.begin();
	list<char>::iterator it = nt;
	for(int i=0;i!=n;i++,it++);
	for(;it!=ls.end();++it,++nt);
	cout<<"The nth char to the last is "<<*nt<<endl;
	return 0;
}
