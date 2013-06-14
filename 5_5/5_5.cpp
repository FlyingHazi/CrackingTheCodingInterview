#include <iostream>
using namespace std;

int countConvertBits(const int x,const int y)
{
	int n = 0;
	for(int z = x^y;z != 0;z=z >> 1)
	{
		n += (z & 1);
	}
	return n;
}

int main(int argc,char* argv[])
{
	cout<<"Please enter 2 integer:"<<endl;
	int x,y;
	cin>>x>>y;
	int z = countConvertBits(x,y);
	cout<<"need "<<z<<" bits"<<endl;
	return 0;
}
