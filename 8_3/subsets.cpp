#include <iostream>
#include <set>
#include <initializer_list>
using namespace std;
typedef set<set<int> > ssi;

void printSet(const set<int> *ps)
{
	cout<<'{';
	for(set<int>::const_iterator it = ps->begin();it != ps->end();it++)
	{
		cout<<*it<<',';
	}
	cout<<'}'<<endl;
}

void printSets(const ssi *pssi)
{
	cout<<'{';
	for(typename ssi::const_iterator ps=pssi->begin();ps!=pssi->end();ps++)
	{
		cout<<'{';
		for(set<int>::const_iterator it = ps->begin();it != ps->end();it++)
		{
			cout<<*it<<',';
		}
		cout<<"},";
	}
	cout<<'}'<<endl;
}

ssi *getSubsets(const set<int> *fullSet)
{
	ssi *allSets = new ssi();
	ssi *subSets;
	set<int> *tempSet;
	ssi *tempSets;
	set<int> *copySet;

	allSets->insert(set<int>());
	for(typename set<int>::const_iterator it=fullSet->begin();it!=fullSet->end();it++)
	{
		copySet = new set<int>(*fullSet);
		tempSets = new ssi();
		copySet->erase(*it);
		subSets = getSubsets(copySet);
		for(typename ssi::const_iterator itr = subSets->begin();itr!= subSets->end();itr++)
		{
			tempSet = new set<int>(*itr);
			tempSet->insert(*it);
			tempSets->insert(*tempSet);
			delete tempSet;
		}
		allSets->insert(tempSets->begin(),tempSets->end());
		delete copySet;
		delete subSets;
		delete tempSets;
	}

	return allSets;
}

int main(int argc,char* argv[])
{
	set<int> *fullSet = new set<int>{1,2,3};
	ssi *subSets = getSubsets(fullSet);
	printSets(subSets);

	return 0;
}
