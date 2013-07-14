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
ssi *getSubsets(const vector<int> *fullSet)
{
	ssi *allSets = new ssi();
	const unsigned int max = (1<<fullSet->size());
	vector<int> *subSet = NULL;

	for(unsigned int i=0;i!=max;i++)
	{
		//Bits to subsets
		subSet = new vector<int>();
		for(unsigned int index=0;index!=i;index++)
		{
			if(0x01 & i>>index)
			{
				subSet->push_back((*fullSet)[index]);
			}
		}
		allSets->push_back(*subSet);
		delete subSet;
	}
	return allSets;
}

int main(int argc,char* argv[])
{
	vector<int> *fullSet = new vector<int>{1,2,3};
	ssi *subSets = getSubsets(fullSet);
	printSSI(subSets);
	delete fullSet;
	delete subSets;

	return 0;
}
