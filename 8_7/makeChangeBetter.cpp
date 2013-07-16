#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

unsigned int makeChange(const vector<unsigned int> &denoms,const unsigned int capacity,const unsigned int denom)
{
	unsigned int ways = 0;

	if(denoms.size()-1 == denom)
	{
		return 1;
	}
	for(int i=0;capacity>=i*denoms[denom];i++)
	{
		ways += makeChange(denoms,capacity-i*denoms[i],denom+1);
	}
	return ways;
}

int main(int argc,char *argv[])
{
	const vector<unsigned int> denoms = vector<unsigned int>{25,10,5,1};
	cout<<"Please input the capacity:"<<endl;
	unsigned int capacity = 0;
	cin>>capacity;
	cout<<"There are "<<makeChange(denoms,capacity,0)<<" ways."<<endl;
	return 0;
}
