#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> *findPar(const unsigned int left,const unsigned int right)
{
	set<string> *allSet = new set<string>();
	if(0==left && 0==right)
	{
		allSet->insert(string(""));
	}
	set<string> *subset = NULL;
	if(left > 0)
	{
		subset = findPar(left-1,right);
		for(typename set<string>::iterator it=subset->begin();it!=subset->end();it++)
		{
			allSet->insert("("+*it);
		}
		delete subset;
	}
	if(right > left)
	{
		subset = findPar(left,right-1);
		for(typename set<string>::iterator it=subset->begin();it!=subset->end();it++)
		{
			allSet->insert(")"+*it);
		}
		delete subset;
	}
	return allSet;

}

int main(int argc, char* argv[])
{
	int n ;
	cout<<"Please input the count:"<<endl;
	cin>>n;
	set<string> *pars = findPar(n,n);
	for(typename set<string>::iterator it=pars->begin();it!=pars->end();it++)
	{
		cout<<*it<<endl;
	}
	delete pars;
	return 0;
}
