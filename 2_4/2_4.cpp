#include <iostream>
#include <list>
using namespace std;

list<int> *listPlus(list<int>& ls1,list<int>& ls2)
{
	list<int> *pls = new list<int>(ls1.begin(),ls1.end());
	list<int>::iterator it1 = pls->begin();
	list<int>::iterator it2 = ls2.begin();
	int carry = 0;
	while(pls->end() != it1)
	{
		if(ls2.end() == it2)
		{
			*it1 += carry;
			carry = *it1 / 10;
			*it1 = *it1%10;
			break;
		}
		*it1 += *it2 + carry;
		carry = *it1/10;
		*it1 = *it1%10;
		++it1;
		++it2;
	}

	while(ls2.end() != it2)
	{
		pls->push_back((*it2+carry)%10);
		carry = (*it2+carry)/10;
		it2++;
	}
	if(0 != carry)
	{
		pls->push_back(1);
	}
	return pls;
}

int main(int argc,char* argv[])
{
	cout<<"Please enter the 1st num:";
	string s1;
	cin>>s1;
	cout<<"Please enter the 2nd num:";
	string s2;
	cin>>s2;
	list<int> ls1 = list<int>(s1.begin(),s1.end());
	list<int> ls2 = list<int>(s2.begin(),s2.end());
	for(list<int>::iterator it=ls1.begin();it!=ls1.end();it++)
	{
		*it -= '0';
	}
	for(list<int>::iterator it=ls2.begin();it!=ls2.end();it++)
	{
		*it -= '0';
	}
	list<int> *pls = listPlus(ls1,ls2);
	for(list<int>::iterator it=pls->begin();it!=pls->end();it++)
	{
		cout<<*it<<"->";
	}
	cout<<endl;
	return 0;
}
