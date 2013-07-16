#include <iostream>
using namespace std;

unsigned int makeChange(const unsigned int capacity,const unsigned int denom)
{
	unsigned int ways = 0;
	const unsigned int denoms[4] = {25,10,5,1};

	if(0 == capacity)
	{
		return 1;
	}
	for(int i=0;i!=sizeof(denoms)/sizeof(unsigned int);i++)
	{
		if(denoms[i] < denom)
		{
			break;
		}
		if(capacity >= denoms[i])
		{
			ways += makeChange(capacity-denoms[i],denoms[i]);
		}
	}
	return ways;
}

int main(int argc,char *argv[])
{
	cout<<"Please input the capacity:"<<endl;
	unsigned int capacity = 0;
	cin>>capacity;
	cout<<"There are "<<makeChange(capacity,0)<<" ways."<<endl;
	return 0;
}
