#include <string>
#include <set>
#include <map>
#include <iostream>
using namespace std;

set<string>* getAllPermutations(const string &origin,const unsigned int index)
{
	set<string> *allPermutations = new set<string>();
	if(origin.length() == index)
	{
		allPermutations->insert("");
		return allPermutations;
	}else
	{
		set<string> *subPermutations = getAllPermutations(origin,index+1);
		for(typename set<string>::iterator it=subPermutations->begin();it!=subPermutations->end();it++)
		{
			unsigned int pos = it->find_last_of(origin[index]);
			pos = string::npos==pos?0:pos+1;
			for(int i=pos;i!=it->length()+1;i++)
			{
				allPermutations->insert(string(*it).insert(i,1,origin[index]));
			}
		}
		delete subPermutations;
	}
	return allPermutations;
}

int main(int argc, char* argv[])
{
	string s ;
	cout<<"Please input the string:"<<endl;
	cin>>s;
	set<string> *permutations = getAllPermutations(s,0);
	for(typename set<string>::iterator it=permutations->begin();it!=permutations->end();it++)
	{
		cout<<*it<<endl;
	}
	delete permutations;
	return 0;
}
