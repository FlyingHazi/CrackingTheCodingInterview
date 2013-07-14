#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
typedef vector<vector<int> > ssi;

void printSSI(ssi *pssi)
{
	for(unsigned int i=0;i!=pssi->size();i++)
	{
		cout<<'{';
		for(unsigned int j=0;j!=(*pssi)[i].size();j++)
		{
			cout<<(*pssi)[i][j]<<',';
		}
		cout<<"},"<<endl;
	}
}
ssi *getSubsets(const vector<int> *fullSet,const unsigned int index)
{
	ssi *allSets = NULL;
	if(index == fullSet->size())
	{
		allSets = new ssi();
		allSets->push_back(vector<int>());
	}else
	{
		int item = (*fullSet)[index];
		allSets = getSubsets(fullSet,index + 1);
		ssi *moreSets = new ssi();
		vector<int> *newSet = NULL;
		for(typename ssi::const_iterator it=allSets->begin();it!=allSets->end();it++)
		{
			newSet = new vector<int>(*it);
			newSet->push_back(item);
			moreSets->push_back(*newSet);
			delete newSet;
		}
		allSets->insert(allSets->end(),moreSets->begin(),moreSets->end());
		delete moreSets;
	}
	return allSets;
}

int main(int argc,char* argv[])
{
	vector<int> *fullSet = new vector<int>{1,2,3};
	ssi *subSets = getSubsets(fullSet,0);
	printSSI(subSets);

	return 0;
}
