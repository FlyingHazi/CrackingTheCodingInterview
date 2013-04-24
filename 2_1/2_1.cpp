#include <iostream>
#include <list>
using namespace std;

void removeduplication(list<char> &ls)
{
	bool checker[256] = {false};
	list<char>::iterator it = ls.begin();
	list<char>::iterator tmp;
	while(ls.end() != it)
	{
		tmp = it++;
		if(false == checker[*tmp])
		{
			checker[*tmp] = true;
		}
		else
		{
			ls.erase(tmp);
		}
	}
}

int main(int argc,char* argv[])
{
	string s;
	list<char> ls;

	cout<<"Please enter a string:";
	cin>>s;
	ls.assign(s.begin(),s.end());
	removeduplication(ls);
	for(list<char>::iterator it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it;
	}
	cout<<endl;
	return 0;
}
